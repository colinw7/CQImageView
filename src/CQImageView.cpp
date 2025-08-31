#include <CQImageView.h>
#include <CQUtil.h>

#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>

class CQImageViewRenderer : public CImageViewRenderer {
 public:
  CQImageViewRenderer(QImage *image) :
   image_(image) {
    width_  = image_->width();
    height_ = image_->height();
  }

  void drawPoint(int x, int y, const CRGBA &rgba) override;

 private:
  QImage *image_  { nullptr };
  int     width_  { 0 };
  int     height_ { 0 };
};

CQImageView::
CQImageView(QWidget *parent) :
 QWidget(parent)
{
  setFocusPolicy(Qt::StrongFocus);

  setMouseTracking(true);
}

void
CQImageView::
setImage(CImagePtr image)
{
  view_.setImage(image);
}

void
CQImageView::
getImageColor(int x, int y, CRGBA &rgba)
{
  view_.getImageColor(x, y, rgba);
}

void
CQImageView::
setGrid(bool b)
{
  grid_ = b;

  update();
}

void
CQImageView::
setAutoSize(bool b)
{
  autoSize_ = b;

  update();
}

void
CQImageView::
setMode(CImageView::Mode mode)
{
  view_.setMode(mode);

  update();
}

CImageView::Mode
CQImageView::
getMode() const
{
  return view_.getMode();
}

void
CQImageView::
paintEvent(QPaintEvent *)
{
  QPainter painter(this);

  //---

  // draw background
  //   grid or solid color
  if (grid_) {
    auto bg = (! bg_.isValid() ? QColor(Qt::white) : bg_);

    int cs = 32;
    int nc = (width () + cs - 1)/cs;
    int nr = (height() + cs - 1)/cs;

    for (int r = 0; r < nr; ++r) {
      int y = r*cs;

      for (int c = 0; c < nc; ++c) {
        int x = c*cs;

        if ((r + c) & 1)
          painter.fillRect(QRect(x, y, cs, cs), QColor(200,200,200));
        else
          painter.fillRect(QRect(x, y, cs, cs), bg);
      }
    }
  }
  else {
    if (bg_.isValid())
      painter.fillRect(rect(), QColor(bg_));
  }

  //---

  if (getAutoSize()) {
    auto *qimage = dynamic_cast<CQImage *>(view_.getImage().get());

    if (getNeedsSize()) {
      qimage_ = qimage->getQImage().scaled(width(), height(), Qt::KeepAspectRatio);

      setNeedsSize(false);
    }

    painter.drawImage(0, 0, qimage_);
  }
  else {
    CQImageViewRenderer renderer(&image_);

    image_.fill(0);

    view_.draw(&renderer, uint(width()), uint(height()));

    painter.drawImage(0, 0, image_);
  }
}

void
CQImageView::
resizeEvent(QResizeEvent *)
{
  image_ = QImage(width(), height(), QImage::Format_ARGB32);

  setNeedsSize(true);
}

void
CQImageView::
mousePressEvent(QMouseEvent *e)
{
  int x = e->pos().x();
  int y = e->pos().y();

  pressX_ = x;
  pressY_ = y;

  int ix, iy;

  if (view_.pixelToImage(x, y, ix, iy))
    emit imageMousePress(ix, iy);

  pressed_ = true;
}

void
CQImageView::
mouseMoveEvent(QMouseEvent *e)
{
  int x = e->pos().x();
  int y = e->pos().y();

  int ix, iy;

  if (view_.pixelToImage(x, y, ix, iy)) {
    if (pressed_)
      emit imageMouseDrag(ix, iy);
    else
      emit imageMouseMove(ix, iy);
  }

  if (pressed_) {
    if (movable_)
      view_.setOffset(view_.getOffset() + CIPoint2D(x - pressX_, y - pressY_));
  }

  pressX_ = x;
  pressY_ = y;

  update();
}

void
CQImageView::
mouseReleaseEvent(QMouseEvent *e)
{
  int x = e->pos().x();
  int y = e->pos().y();

  int ix, iy;

  if (view_.pixelToImage(x, y, ix, iy))
    emit imageMouseRelease(ix, iy);

  if (movable_)
    view_.setOffset(view_.getOffset() + CIPoint2D(x - pressX_, y - pressY_));

  pressX_ = x;
  pressY_ = y;

  update();

  pressed_ = false;
}

void
CQImageView::
keyPressEvent(QKeyEvent *e)
{
  int key = e->key();

  if (movable_) {
    if      (key == Qt::Key_Left    ) view_.setOffset(view_.getOffset() + CIPoint2D(-1, 0));
    else if (key == Qt::Key_Right   ) view_.setOffset(view_.getOffset() + CIPoint2D( 1, 0));
    else if (key == Qt::Key_Down    ) view_.setOffset(view_.getOffset() + CIPoint2D(0, -1));
    else if (key == Qt::Key_Up      ) view_.setOffset(view_.getOffset() + CIPoint2D(0,  1));
  }

  if (scalable_) {
    if      (key == Qt::Key_PageUp  ) view_.setScale(view_.getScale() + 1);
    else if (key == Qt::Key_PageDown) view_.setScale(view_.getScale() - 1);
  }

  update();
}

//-----

void
CQImageViewRenderer::
drawPoint(int x, int y, const CRGBA &rgba)
{
  if (x >= 0 && x < width_ && y >= 0 && y < height_)
    //image_->setPixel(x, y, CQUtil::rgbaToColor(rgba).rgba());
    image_->setPixel(x, y, rgba.encodeARGB());
}

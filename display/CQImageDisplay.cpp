#include <CQImageDisplay.h>
#include <QScrollArea>

#include <QPainter>
#include <QHBoxLayout>
#include <QToolButton>

CQImageDisplay::
CQImageDisplay(QWidget *parent) :
 QWidget(parent)
{
  setObjectName("preview");

  auto *layout = new QHBoxLayout(this);
  layout->setMargin(0); layout->setSpacing(0);

  canvas_ = new CQImageDisplayCanvas(this);

  sarea_ = new QScrollArea(this);

  sarea_->setWidget(canvas_);

  layout->addWidget(sarea_);
}

CQImageDisplay::
~CQImageDisplay()
{
}

void
CQImageDisplay::
canvasUpdateSlot()
{
  canvas_->update();
}

void
CQImageDisplay::
sendCancelSignal()
{
  emit cancelSignal();
}

QImage
CQImageDisplay::
getImage() const
{
  return canvas_->getImage();
}

void
CQImageDisplay::
setImage(QImage image)
{
  canvas_->setImage(image);
}

void
CQImageDisplay::
setBackground(const QColor &bg)
{
  canvas_->setBackground(bg);
}

//----------

CQImageDisplayCanvas::
CQImageDisplayCanvas(CQImageDisplay *view) :
 QWidget(nullptr), view_(view)
{
  setFocusPolicy(Qt::StrongFocus);
}

CQImageDisplayCanvas::
~CQImageDisplayCanvas()
{
}

void
CQImageDisplayCanvas::
setImage(QImage image)
{
  image_ = image;

  if (! image_.isNull())
    setFixedSize(image_.width(), image_.height());

  update();
}

void
CQImageDisplayCanvas::
setBackground(const QColor &bg)
{
  bg_ = bg;

  update();
}

void
CQImageDisplayCanvas::
resizeEvent(QResizeEvent *)
{
}

void
CQImageDisplayCanvas::
paintEvent(QPaintEvent *)
{
  QPainter painter(this);

  painter.fillRect(rect(), bg_);

  if (image_.isNull()) return;

  int dx = 0, dy = 0;

  auto iw = image_.width ();
  auto ih = image_.height();

  if (int(iw) > width())
    dx = (width() - int(iw))/2;

  if (int(ih) > height())
    dy = (height() - int(ih))/2;

  painter.drawImage(QPoint(dx, dy), image_);
}

void
CQImageDisplayCanvas::
keyPressEvent(QKeyEvent *)
{
}

#include <CImageView.h>

CImageView::
CImageView()
{
}

void
CImageView::
setImage(CImagePtr image)
{
  image_ = image;
}

void
CImageView::
setScale(int scale)
{
  scale_ = scale;
}

void
CImageView::
setOffset(const CIPoint2D &offset)
{
  offset_ = offset;
}

void
CImageView::
getImageColor(int x, int y, CRGBA &rgba)
{
  getRGBAPixel(x, y, rgba);
}

void
CImageView::
setMode(Mode mode)
{
  mode_ = mode;
}

CImageView::Mode
CImageView::
getMode() const
{
  return mode_;
}

void
CImageView::
draw(CImageViewRenderer *renderer, uint w, uint h)
{
  if (! image_) return;

  if (w == 0 || h == 0) return;

  int iw = int(image_->getWidth ());
  int ih = int(image_->getHeight());

  int x1 = 0, x2 = iw - 1;
  int y1 = 0, y2 = ih - 1;

  if      (scale_ <= 0) {
    int scale = -(scale_ - 2);

    for (int y = y1; y <= y2; y += scale) {
      int iy = y/scale + offset_.y;

      if (iy < 0 || iy >= int(h)) continue;

      for (int x = x1; x <= x2; x += scale) {
        int ix = x/scale + offset_.x;

        if (ix < 0 || ix >= int(w)) continue;

        CRGBA rgba;

        getRGBAPixel(x, y, rgba);

        renderer->drawPoint(ix, iy, rgba);
      }
    }
  }
  else if (scale_ > 1) {
    for (int y = y1; y <= y2; ++y) {
      int iy = y*scale_ + offset_.y;

      if (iy < -scale_ || iy >= int(h) + scale_) continue;

      for (int x = x1; x <= x2; ++x) {
        int ix = x*scale_ + offset_.x;

        if (ix < -scale_ || ix >= int(w) + scale_) continue;

        CRGBA rgba;

        getRGBAPixel(x, y, rgba);

        for (int yy1 = 0; yy1 < scale_; ++yy1)
          for (int xx1 = 0; xx1 < scale_; ++xx1)
            renderer->drawPoint(ix + yy1, iy + xx1, rgba);
      }
    }
  }
  else {
    for (int y = y1; y <= y2; ++y) {
      int iy = y + offset_.y;

      if (iy < 0 || iy >= int(h)) continue;

      for (int x = x1; x <= x2; ++x) {
        int ix = x + offset_.x;

        if (ix < 0 || ix >= int(w)) continue;

        CRGBA rgba;

        getRGBAPixel(x, y, rgba);

        renderer->drawPoint(ix, iy, rgba);
      }
    }
  }
}

bool
CImageView::
pixelToImage(int px, int py, int &ix, int &iy)
{
  ix = px;
  iy = py;

  if      (scale_ <= 0) {
    int scale = -(scale_ - 2);

    ix = scale*(px - offset_.x);
    iy = scale*(py - offset_.y);
  }
  else if (scale_ > 1) {
    ix = (px - offset_.x)/scale_;
    iy = (py - offset_.y)/scale_;
  }
  else {
    ix = px - offset_.x;
    iy = py - offset_.y;
  }

  int iw = int(image_->getWidth ());
  int ih = int(image_->getHeight());

  if (ix < 0 || ix >= iw || iy < 0 || iy >= ih)
    return false;

  return true;
}

void
CImageView::
getRGBAPixel(int x, int y, CRGBA &rgba)
{
  image_->getRGBAPixel(x, y, rgba);

  if      (mode_ == Mode::GRAY)
    rgba = rgba.getGrayRGBA();
  else if (mode_ == Mode::SEPIA)
    rgba = rgba.sepia();
  else if (mode_ == Mode::RED) {
    rgba.setGreen(0);
    rgba.setBlue (0);
  }
  else if (mode_ == Mode::GREEN) {
    rgba.setRed (0);
    rgba.setBlue(0);
  }
  else if (mode_ == Mode::BLUE) {
    rgba.setRed  (0);
    rgba.setGreen(0);
  }
  else if (mode_ == Mode::ALPHA) {
    auto a = rgba.getAlpha();

    rgba.setRed  (a);
    rgba.setGreen(a);
    rgba.setBlue (a);
    rgba.setAlpha(1.0);
  }
}

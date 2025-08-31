#ifndef CImageView_H
#define CImageView_H

#include <CPoint2D.h>
#include <CImageLib.h>

// Filter: gray, r, g, b, sepia ...
class CImageViewRenderer;

class CImageView {
 public:
  enum class Mode {
    NORMAL,
    GRAY,
    SEPIA,
    RED,
    GREEN,
    BLUE,
    ALPHA
  };

 public:
  CImageView();

  virtual ~CImageView() { }

  const CImagePtr &getImage() const { return image_; }
  void setImage(CImagePtr image);

  int getScale() const { return scale_; }
  void setScale(int scale);

  const CIPoint2D &getOffset() const { return offset_; }
  void setOffset(const CIPoint2D &offset);

  void getImageColor(int x, int y, CRGBA &rgba);

  void setMode(CImageView::Mode mode);

  CImageView::Mode getMode() const;

  void draw(CImageViewRenderer *renderer, uint w, uint h);

  bool pixelToImage(int px, int py, int &ix, int &iy);

 private:
  void getRGBAPixel(int x, int y, CRGBA &rgba);

 private:
  CImagePtr image_;
  int       scale_  { 1 };    // positive (zoom in), negative (zoom out)
  CIPoint2D offset_ { 0, 0 }; // offset
  Mode      mode_   { Mode::NORMAL };
};

//---

class CImageViewRenderer {
 public:
  CImageViewRenderer() { }

  virtual ~CImageViewRenderer() { }

  virtual void drawPoint(int x, int y, const CRGBA &rgba) = 0;
};

#endif

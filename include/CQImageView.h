#ifndef CQImageView_H
#define CQImageView_H

#include <CQImage.h>
#include <CImageLib.h>
#include <CImageView.h>

#include <QWidget>
#include <QImage>

class CQImageView : public QWidget {
  Q_OBJECT

  Q_PROPERTY(bool   movable  READ isMovable   WRITE setMovable)
  Q_PROPERTY(bool   scalable READ isScalable  WRITE setScalable)
  Q_PROPERTY(bool   grid     READ getGrid     WRITE setGrid)
  Q_PROPERTY(bool   autoSize READ getAutoSize WRITE setAutoSize)
  Q_PROPERTY(QColor bg       READ bg          WRITE setBg)

 public:
  CQImageView(QWidget *parent=nullptr);

  void setImage(CImagePtr image);

  void getImageColor(int x, int y, CRGBA &rgba);

  bool isMovable() const { return movable_; }
  void setMovable(bool b) { movable_ = b; }

  bool isScalable() const { return scalable_; }
  void setScalable(bool b) { scalable_ = b; }

  bool getGrid() const { return grid_; }
  void setGrid(bool b);

  bool getAutoSize() const { return autoSize_; }
  void setAutoSize(bool b);

  bool getNeedsSize() const { return needsSize_; }
  void setNeedsSize(bool b) { needsSize_ = b; }

  CImageView::Mode getMode() const;
  void setMode(CImageView::Mode mode);

  const QColor &bg() const { return bg_; }
  void setBg(const QColor &v) { bg_ = v; }

  // renderer use only
  void drawPoint(int x, int y, const CRGBA &rgba);

 private:
  void paintEvent(QPaintEvent *) override;
  void resizeEvent(QResizeEvent *) override;

  void mousePressEvent(QMouseEvent *e) override;
  void mouseMoveEvent(QMouseEvent *e) override;
  void mouseReleaseEvent(QMouseEvent *e) override;

  void keyPressEvent(QKeyEvent *e) override;

 signals:
  void imageMousePress  (int x, int y);
  void imageMouseDrag   (int x, int y); // move pressed
  void imageMouseMove   (int x, int y); // move not-pressed
  void imageMouseRelease(int x, int y);

 private:
  CImageView view_;
  QImage     image_;
  QImage     qimage_;
  bool       movable_   { true };
  bool       scalable_  { true };
  bool       grid_      { false };
  bool       autoSize_  { false };
  bool       needsSize_ { true };
  QColor     bg_;
  int        pressX_    { 0 };
  int        pressY_    { 0 };
  bool       pressed_   { false };
};

#endif

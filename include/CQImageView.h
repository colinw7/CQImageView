#ifndef CQImageView_H
#define CQImageView_H

#include <QWidget>
#include <QImage>

#include <CBool.h>
#include <CInt.h>
#include <CImageLib.h>
#include <CImageView.h>

class CQImageView : public QWidget {
  Q_OBJECT

  Q_PROPERTY(bool   movable  READ isMovable  WRITE setMovable)
  Q_PROPERTY(bool   scalable READ isScalable WRITE setScalable)
  Q_PROPERTY(bool   grid     READ getGrid    WRITE setGrid)
  Q_PROPERTY(QColor bg       READ bg         WRITE setBg)

 public:
  CQImageView(QWidget *parent=0);

  void setImage(CImagePtr image);

  void getImageColor(int x, int y, CRGBA &rgba);

  bool isMovable() const { return movable_; }
  void setMovable(bool b) { movable_ = b; }

  bool isScalable() const { return scalable_; }
  void setScalable(bool b) { scalable_ = b; }

  bool getGrid() const { return grid_; }
  void setGrid(bool b);

  CImageView::Mode getMode() const;
  void setMode(CImageView::Mode mode);

  const QColor &bg() const { return bg_; }
  void setBg(const QColor &v) { bg_ = v; }

  // renderer use only
  void drawPoint(int x, int y, const CRGBA &rgba);

 private:
  void paintEvent(QPaintEvent *);
  void resizeEvent(QResizeEvent *);

  void mousePressEvent(QMouseEvent *e);
  void mouseMoveEvent(QMouseEvent *e);
  void mouseReleaseEvent(QMouseEvent *e);

  void keyPressEvent(QKeyEvent *e);

 signals:
  void imageMousePress  (int x, int y);
  void imageMouseDrag   (int x, int y); // move pressed
  void imageMouseMove   (int x, int y); // move not-pressed
  void imageMouseRelease(int x, int y);

 private:
  CImageView view_;
  QImage     image_;
  bool       movable_  { true };
  bool       scalable_ { true };
  CBool      grid_;
  QColor     bg_;
  CInt       pressX_;
  CInt       pressY_;
  CBool      pressed_;
};

#endif

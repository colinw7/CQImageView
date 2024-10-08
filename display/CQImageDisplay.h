#ifndef CQImageDisplay_H
#define CQImageDisplay_H

#include <QWidget>
#include <QImage>

class QResizeEvent;
class QPaintEvent;

class CQImageDisplayCanvas;
class QScrollArea;

//---

class CQImageDisplay : public QWidget {
  Q_OBJECT

 public:
  CQImageDisplay(QWidget *parent=nullptr);

 ~CQImageDisplay();

  QImage getImage() const;
  void setImage(QImage image);

  void setBackground(const QColor &rgba);

  QScrollArea *getScrollArea() const { return sarea_; }

  void sendCancelSignal();

 signals:
  void cancelSignal();

 private slots:
  void canvasUpdateSlot();

 private:
  CQImageDisplayCanvas* canvas_ { nullptr };
  QScrollArea*          sarea_  { nullptr };
};

//---

class CQImageDisplayCanvas : public QWidget {
  Q_OBJECT

 public:
  CQImageDisplayCanvas(CQImageDisplay *view);

  virtual ~CQImageDisplayCanvas();

  QImage getImage() const { return image_; }
  void setImage(QImage image);

  void setFillScreen(bool fillScreen) { fillScreen_ = fillScreen; }
  void setKeepAspect(bool keepAspect) { keepAspect_ = keepAspect; }

  bool getFillScreen() const { return fillScreen_; }
  bool getKeepAspect() const { return keepAspect_; }

  void setBackground(const QColor &bg);

  void resizeEvent(QResizeEvent *e) override;
  void paintEvent(QPaintEvent *e) override;

  void keyPressEvent(QKeyEvent *e) override;

 private:
  CQImageDisplay* view_       { nullptr };
  QImage          image_;
  bool            fillScreen_ { false };
  bool            keepAspect_ { true };
  QColor          bg_;
};

#endif

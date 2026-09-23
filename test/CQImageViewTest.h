#ifndef CQImageViewTest_H
#define CQImageViewTest_H

#include <QDialog>
#include <CImageLib.h>

class CQImageView;
class CQIconButton;
class CQRealSpin;
class CQIntegerSpin;

class QFrame;
class QLabel;
class QCheckBox;

class CQImageViewTest : public QDialog {
  Q_OBJECT

 public:
  CQImageViewTest();

  bool addImage(const char *fileName);

  void loadImage();

 private:
  void createToolBar();
  void createControlFrame();
  void createStatus();

  void resizeEvent(QResizeEvent *) override;

 private Q_SLOTS:
  void imagePositionSlot(int x, int y);

  void scaleViewSlot();

  void nextSlot();
  void prevSlot();

  void graySlot();
  void sepiaSlot();

  void redSlot();
  void greenSlot();
  void blueSlot();
  void alphaSlot();

  void scaleSlot(int);
  void gridSlot(int);
  void autoSizeSlot(int);
  void autoScaleSlot(int);

  void settingsSlot(bool);

 public Q_SLOTS:
  void updateSize();
  void updateState();

 private:
  // image data
  struct ImageData {
    std::string fileName;
    CImagePtr   image;
    bool        loaded { false };
    bool        valid  { false };
  };

  using ImageList = std::vector<ImageData>;

  int       imageNum_ { 0 };
  ImageList images_;

  // widgets
  CQImageView* view_ { nullptr };

  struct ControlWidgets {
    QFrame*      frame      { nullptr };
    QPushButton* nextButton { nullptr };
    QPushButton* prevButton { nullptr };
  };

  struct ToolbarWidgets {
    QFrame*        frame          { nullptr };
    CQIconButton*  nextButton     { nullptr };
    CQIconButton*  prevButton     { nullptr };
    CQIntegerSpin* scaleSpin      { nullptr };
    CQIconButton*  settingsButton { nullptr };
  };

  struct StatusWidgets {
    QFrame* frame      { nullptr };
    QLabel* nameLabel  { nullptr };
    QLabel* sizeLabel  { nullptr };
    QLabel* colorLabel { nullptr };
  };

  ToolbarWidgets toolbarWidgets_;
  ControlWidgets controlWidgets_;
  StatusWidgets  statusWidgets_;

  int viewWidth_  { -1 };
  int viewHeight_ { -1 };

  bool sizeInited_ { false };
};

#endif

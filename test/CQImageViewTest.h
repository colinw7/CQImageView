#ifndef CQImageViewTest_H
#define CQImageViewTest_H

#include <QDialog>
#include <CImageLib.h>

class CQImageView;
class QFrame;
class QLabel;
class QCheckBox;

class CQImageViewTest : public QDialog {
  Q_OBJECT

 public:
  CQImageViewTest();

  void addImage(const char *fileName);

  void loadImage();

 private slots:
  void imagePositionSlot(int x, int y);

  void nextSlot();
  void prevSlot();

  void graySlot();
  void sepiaSlot();

  void redSlot();
  void greenSlot();
  void blueSlot();
  void alphaSlot();

  void gridSlot();
  void autoSizeSlot();

  void updateState();

 private:
  using NameList  = std::vector<std::string>;
  using ImageList = std::vector<CImagePtr>;

  QFrame      *control_       { nullptr };
  CQImageView *view_          { nullptr };
  QLabel      *colorLabel_    { nullptr };
  QPushButton *nextButton_    { nullptr };
  QPushButton *prevButton_    { nullptr };
  QCheckBox   *gridCheck_     { nullptr };
  QCheckBox   *autoSizeCheck_ { nullptr };
  int          imageNum_      { 0 };
  NameList     names_;
  ImageList    images_;
};

#endif

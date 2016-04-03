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

  void gridSlot();

  void updateState();

 private:
  typedef std::vector<std::string> NameList;
  typedef std::vector<CImagePtr>   ImageList;

  QFrame      *control_    { 0 };
  CQImageView *view_       { 0 };
  QLabel      *colorLabel_ { 0 };
  QPushButton *nextButton_;
  QPushButton *prevButton_;
  QCheckBox   *gridCheck_;
  int          imageNum_   { 0 };
  NameList     names_;
  ImageList    images_;
};

#endif

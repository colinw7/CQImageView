#include <CQImageViewTest.h>
#include <CQImageView.h>
#include <CQApp.h>
#include <CQUtil.h>
#include <CQUtilRGBA.h>

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>

int
main(int argc, char **argv)
{
  CQApp app(argc, argv);

  auto *test = new CQImageViewTest;

  for (int i = 1; i < argc; ++i)
    test->addImage(argv[i]);

  test->loadImage();

  test->show();

  return app.exec();
}

CQImageViewTest::
CQImageViewTest()
{
  auto *layout = new QHBoxLayout(this);
  layout->setMargin(0); layout->setSpacing(0);

  view_ = new CQImageView;

  connect(view_, SIGNAL(imageMouseMove(int, int)), this, SLOT(imagePositionSlot(int, int)));

  layout->addWidget(view_);

  control_ = new QFrame;

  QFontMetrics fm(font());

  control_->setFixedWidth(fm.horizontalAdvance("XXXX,XXXX") + 16);

  auto *vlayout = new QVBoxLayout(control_);
  vlayout->setMargin(2); vlayout->setSpacing(2);

  colorLabel_ = new QLabel();

  colorLabel_->setFixedSize(fm.horizontalAdvance("XXXX,XXXX"), fm.height());

  vlayout->addWidget(colorLabel_);

  //---

  nextButton_ = new QPushButton("Next");

  connect(nextButton_, SIGNAL(clicked()), this, SLOT(nextSlot()));

  vlayout->addWidget(nextButton_);

  prevButton_ = new QPushButton("Prev");

  connect(prevButton_, SIGNAL(clicked()), this, SLOT(prevSlot()));

  vlayout->addWidget(prevButton_);

  //---

  auto *grayButton = new QPushButton("Gray");

  connect(grayButton, SIGNAL(clicked()), this, SLOT(graySlot()));

  vlayout->addWidget(grayButton);

  auto *sepiaButton = new QPushButton("Sepia");

  connect(sepiaButton, SIGNAL(clicked()), this, SLOT(sepiaSlot()));

  vlayout->addWidget(sepiaButton);

  //---

  auto *redButton = new QPushButton("Red");

  connect(redButton, SIGNAL(clicked()), this, SLOT(redSlot()));

  vlayout->addWidget(redButton);

  auto *greenButton = new QPushButton("Green");

  connect(greenButton, SIGNAL(clicked()), this, SLOT(greenSlot()));

  vlayout->addWidget(greenButton);

  auto *blueButton = new QPushButton("Blue");

  connect(blueButton, SIGNAL(clicked()), this, SLOT(blueSlot()));

  vlayout->addWidget(blueButton);

  //---

  gridCheck_ = new QCheckBox("Grid");

  connect(gridCheck_, SIGNAL(stateChanged(int)), this, SLOT(gridSlot()));

  vlayout->addWidget(gridCheck_);

  //---

  vlayout->addStretch();

  layout->addWidget(control_);
}

void
CQImageViewTest::
addImage(const char *fileName)
{
  CImageFileSrc src(fileName);

  CImagePtr image = CImageMgrInst->createImage(src);
  if (! image) return;

  names_ .push_back(fileName);
  images_.push_back(image);

  updateState();
}

void
CQImageViewTest::
loadImage()
{
  if (imageNum_ < 0 || imageNum_ >= int(images_.size()))
    return;

  const std::string &name = names_[imageNum_];

  CImagePtr image = images_[imageNum_];

  view_->setImage(image);

  view_->resize(image->getWidth(), image->getHeight());

  view_->update();

  resize(view_->width() + control_->width(), view_->height());

  setWindowTitle(name.c_str());
}

void
CQImageViewTest::
imagePositionSlot(int x, int y)
{
  CRGBA rgba;

  view_->getImageColor(x, y, rgba);

  CQUtil::setBackground(colorLabel_, CQUtil::rgbaToColor(rgba));
  CQUtil::setForeground(colorLabel_, CQUtil::rgbaToColor(rgba.bwColor()));

  colorLabel_->setText(QString("%1, %2").arg(x).arg(y));
}

void
CQImageViewTest::
nextSlot()
{
  if (imageNum_ < int(images_.size()) - 1) {
    ++imageNum_;

    loadImage();

    updateState();
  }
}

void
CQImageViewTest::
prevSlot()
{
  if (imageNum_ > 0) {
    --imageNum_;

    loadImage();

    updateState();
  }
}

void
CQImageViewTest::
graySlot()
{
  CImageView::Mode mode = view_->getMode();

  if (mode == CImageView::Mode::GRAY)
    view_->setMode(CImageView::Mode::NORMAL);
  else
    view_->setMode(CImageView::Mode::GRAY);
}

void
CQImageViewTest::
sepiaSlot()
{
  CImageView::Mode mode = view_->getMode();

  if (mode == CImageView::Mode::SEPIA)
    view_->setMode(CImageView::Mode::NORMAL);
  else
    view_->setMode(CImageView::Mode::SEPIA);
}

void
CQImageViewTest::
redSlot()
{
  CImageView::Mode mode = view_->getMode();

  if (mode == CImageView::Mode::RED)
    view_->setMode(CImageView::Mode::NORMAL);
  else
    view_->setMode(CImageView::Mode::RED);
}

void
CQImageViewTest::
greenSlot()
{
  CImageView::Mode mode = view_->getMode();

  if (mode == CImageView::Mode::GREEN)
    view_->setMode(CImageView::Mode::NORMAL);
  else
    view_->setMode(CImageView::Mode::GREEN);
}

void
CQImageViewTest::
blueSlot()
{
  CImageView::Mode mode = view_->getMode();

  if (mode == CImageView::Mode::BLUE)
    view_->setMode(CImageView::Mode::NORMAL);
  else
    view_->setMode(CImageView::Mode::BLUE);
}

void
CQImageViewTest::
gridSlot()
{
  view_->setGrid(gridCheck_->isChecked());
}

void
CQImageViewTest::
updateState()
{
  prevButton_->setEnabled(imageNum_ > 0);
  nextButton_->setEnabled(imageNum_ < int(images_.size()) - 1);
}

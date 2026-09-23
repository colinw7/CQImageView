#include <CQImageViewTest.h>
#include <CQImageView.h>

#include <CQIconButton.h>
#include <CQRealSpin.h>
#include <CQIntegerSpin.h>
#include <CQApp.h>
#include <CQUtil.h>
#include <CQUtilRGBA.h>
#include <CFileUtil.h>

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>

#include <svg/prev_svg.h>
#include <svg/next_svg.h>
#include <svg/settings_svg.h>

int
main(int argc, char **argv)
{
  CQApp app(argc, argv);

  auto *test = new CQImageViewTest;

  for (int i = 1; i < argc; ++i)
    test->addImage(argv[i]);

  test->loadImage();

  test->show();

  test->updateSize();

  return app.exec();
}

CQImageViewTest::
CQImageViewTest()
{
  auto *layout = new QVBoxLayout(this);
  layout->setMargin(0); layout->setSpacing(0);

  //---

  createToolBar();

  layout->addWidget(toolbarWidgets_.frame);

  //---

  auto *clayout = new QHBoxLayout;
  clayout->setMargin(0); clayout->setSpacing(0);

  layout->addLayout(clayout);

  //---

  // image view
  view_ = new CQImageView;

  connect(view_, SIGNAL(imageMouseMove(int, int)), this, SLOT(imagePositionSlot(int, int)));

  connect(view_, SIGNAL(scaleChanged()), this, SLOT(scaleViewSlot()));

  clayout->addWidget(view_);

  //---

  createControlFrame();

  clayout->addWidget(controlWidgets_.frame);

  controlWidgets_.frame->setVisible(false);

  //---

  createStatus();

  layout->addWidget(statusWidgets_.frame);
}

void
CQImageViewTest::
createToolBar()
{
  toolbarWidgets_.frame = new QFrame;

  toolbarWidgets_.frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

  auto *layout = new QHBoxLayout(toolbarWidgets_.frame);
  layout->setMargin(0); layout->setSpacing(0);

  //---

  auto addToolButton = [&](const QString &name, const QString &iconName, const QString &tip) {
    auto *button = new CQIconButton;

    button->setFocusPolicy(Qt::NoFocus);

    button->setObjectName(name);
    button->setIcon(iconName);
    button->setIconSize(QSize(32, 32));
    button->setAutoRaise(true);
    button->setToolTip(tip);

    layout->addWidget(button);

    return button;
  };

  auto addCheckButton = [&](const QString &name, const QString &iconName, const QString &tip) {
    auto *button = addToolButton(name, iconName, tip);

    button->setCheckable(true);

    return button;
  };

  auto addCheck = [&](const QString &name, const char *slotName, const QString &tip) {
    auto *check = new QCheckBox(name);

    check->setObjectName(name);
    check->setToolTip(tip);

    connect(check, SIGNAL(stateChanged(int)), this, slotName);

    layout->addWidget(check);

    return check;
  };

#if 0
  auto addRealSpin = [&](const QString &name, const char *slotName) {
    auto *frame = new QFrame;

    auto *layout1 = new QHBoxLayout(frame);
    layout1->setMargin(0); layout1->setSpacing(2);

    auto *label = new QLabel(name);
    auto *spin  = new CQRealSpin;

    layout1->addWidget(label);
    layout1->addWidget(spin);

    connect(spin, SIGNAL(realValueChanged(double)), this, slotName);

    layout->addWidget(frame);

    return spin;
  };
#endif

  auto addIntegerSpin = [&](const QString &name, const char *slotName) {
    auto *frame = new QFrame;

    auto *layout1 = new QHBoxLayout(frame);
    layout1->setMargin(0); layout1->setSpacing(2);

    auto *label = new QLabel(name);
    auto *spin  = new CQIntegerSpin;

    layout1->addWidget(label);
    layout1->addWidget(spin);

    connect(spin, SIGNAL(valueChanged(int)), this, slotName);

    layout->addWidget(frame);

    return spin;
  };

  //---

  toolbarWidgets_.prevButton = addToolButton("prev", "PREV", "Prev");
  toolbarWidgets_.nextButton = addToolButton("next", "NEXT", "Next");

  connect(toolbarWidgets_.prevButton, SIGNAL(clicked()), this, SLOT(prevSlot()));
  connect(toolbarWidgets_.nextButton, SIGNAL(clicked()), this, SLOT(nextSlot()));

  //---

  layout->addStretch(1);

  //---

  //toolbarWidgets_.scaleSpin = addRealSpin("Scale", SLOT(scaleSlot(double)));
  toolbarWidgets_.scaleSpin = addIntegerSpin("Scale", SLOT(scaleSlot(int)));

  addCheck("Grid"      , SLOT(gridSlot(int)), "Show background grid");
  addCheck("Auto Size" , SLOT(autoSizeSlot(int)), "Size image to window");
  addCheck("Auto Scale", SLOT(autoScaleSlot(int)), "Size window to image");

  //---

  toolbarWidgets_.settingsButton = addCheckButton("settings", "SETTINGS", "Settings");

  connect(toolbarWidgets_.settingsButton, SIGNAL(toggled(bool)), this, SLOT(settingsSlot(bool)));
}

void
CQImageViewTest::
createControlFrame()
{
  // control frame
  controlWidgets_.frame = new QFrame;

  controlWidgets_.frame->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

  QFontMetrics fm(font());

  controlWidgets_.frame->setFixedWidth(fm.horizontalAdvance("XXXX,XXXX") + 32);

  auto *vlayout = new QVBoxLayout(controlWidgets_.frame);
  vlayout->setMargin(2); vlayout->setSpacing(2);

  //---

  auto addButton = [&](const QString &name, const char *slotName) {
    auto *button = new QPushButton(name);

    connect(button, SIGNAL(clicked()), this, slotName);

    vlayout->addWidget(button);

    return button;
  };

#if 0
  auto addCheck = [&](const QString &name, const char *slotName) {
    auto *check = new QCheckBox(name);

    connect(check, SIGNAL(stateChanged(int)), this, slotName);

    vlayout->addWidget(check);

    return check;
  };
#endif

  //---

#if 0
  controlWidgets_.nextButton = addButton("Next", SLOT(nextSlot()));
  controlWidgets_.prevButton = addButton("Prev", SLOT(prevSlot()));
#endif

  //---

  addButton("Gray" , SLOT(graySlot()));
  addButton("Sepia", SLOT(sepiaSlot()));

  //---

  addButton("Red"  , SLOT(redSlot()));
  addButton("Green", SLOT(greenSlot()));
  addButton("Blue" , SLOT(blueSlot()));

  addButton("Alpha", SLOT(alphaSlot()));

  //---

#if 0
  addCheck("Grid"     , SLOT(gridSlot(int)));
  addCheck("Auto Size", SLOT(autoSizeSlot(int)));
#endif

  //---

  vlayout->addStretch();
}

void
CQImageViewTest::
createStatus()
{
  statusWidgets_.frame = new QFrame;
  auto *slayout = new QHBoxLayout(statusWidgets_.frame);

  statusWidgets_.frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

  statusWidgets_.nameLabel = new QLabel(" ");
  statusWidgets_.sizeLabel = new QLabel(" ");

  statusWidgets_.nameLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

  statusWidgets_.nameLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

  slayout->addWidget(statusWidgets_.nameLabel);
  slayout->addWidget(statusWidgets_.sizeLabel);

  //---

  QFontMetrics fm(font());

  statusWidgets_.colorLabel = new QLabel();

  statusWidgets_.colorLabel->setFixedSize(fm.horizontalAdvance("XXXX,XXXX"), fm.height());

  slayout->addWidget(statusWidgets_.colorLabel);
}

void
CQImageViewTest::
resizeEvent(QResizeEvent *)
{
  if (! sizeInited_)
    return;

  if (! view_->getAutoScale() && ! view_->getAutoSize()) {
    viewWidth_  = view_->width ();
    viewHeight_ = view_->height();
  }
}

bool
CQImageViewTest::
addImage(const char *fileName)
{
  CFile file(fileName);

  if (file.isDirectory()) {
    std::cerr << "File: '" << fileName << "' is not an image\n";
    return false;
  };

  auto isImage = [&]() {
    auto type = CFileUtil::getImageType(&file);

    if (type == CFILE_TYPE_NONE)
      type = CFileUtil::getImageTypeFromName(fileName);

    return (type != CFILE_TYPE_NONE);
  };

  if (! isImage()) {
    std::cerr << "File: '" << fileName << "' is not an image\n";
    return false;
  }

  ImageData data;

  data.fileName = fileName;

  images_.push_back(data);

  updateState();

  return true;
}

void
CQImageViewTest::
loadImage()
{
  if (imageNum_ < 0 || imageNum_ >= int(images_.size()))
    return;

  auto &data = images_[imageNum_];

  if (! data.loaded) {
    CImageFileSrc src(data.fileName);

    data.image = CImageMgrInst->createImage(src);

    data.valid  = !!data.image;
    data.loaded = true;

    if (! data.valid)
      std::cerr << "Failed to load '" << data.fileName << "'\n";
  }

  auto name = QString::fromStdString(data.fileName);

  int w = data.image->getWidth();
  int h = data.image->getHeight();

  view_->setImage(data.image);

  // resize window to match image size
  if (view_->getAutoScale()) {
    view_->resize(w, h);

    viewWidth_  = w;
    viewHeight_ = h;
  }
  else {
    // view_->setNeedsSize(true);

    if (viewWidth_ < 0) {
      viewWidth_  = w;
      viewHeight_ = h;
    }
  }

  view_->update();

  statusWidgets_.nameLabel->setText(name);

  auto sizeStr = QString("%1 x %2").arg(w).arg(h);

  QFontMetrics fm(statusWidgets_.sizeLabel->font());

  statusWidgets_.sizeLabel->setText(sizeStr);
  statusWidgets_.sizeLabel->setFixedSize(fm.horizontalAdvance(sizeStr) + 32, fm.height());

  //---

  if (! view_->getAutoSize()) {
    if (sizeInited_)
      updateSize();
  }

  //---

  setWindowTitle(name);
}

void
CQImageViewTest::
updateSize()
{
  int w1 = viewWidth_;
  int h1 = viewHeight_;

  if (w1 < 0) {
    w1 = 1024;
    h1 = 1024;
  }

  if (controlWidgets_.frame && controlWidgets_.frame->isVisible())
    w1 += controlWidgets_.frame->width();

  if (toolbarWidgets_.frame)
    h1 += toolbarWidgets_.frame->height();

  if (statusWidgets_.frame)
    h1 += statusWidgets_.frame->height();

  resize(w1, h1);

  sizeInited_ = true;
}

void
CQImageViewTest::
imagePositionSlot(int x, int y)
{
  CRGBA rgba;

  view_->getImageColor(x, y, rgba);

  CQUtil::setBackground(statusWidgets_.colorLabel, CQUtil::rgbaToColor(rgba));
  CQUtil::setForeground(statusWidgets_.colorLabel, CQUtil::rgbaToColor(rgba.bwColor()));

  statusWidgets_.colorLabel->setText(QString("%1, %2").arg(x).arg(y));
}

void
CQImageViewTest::
scaleViewSlot()
{
  toolbarWidgets_.scaleSpin->setValue(view_->getScale());
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
alphaSlot()
{
  CImageView::Mode mode = view_->getMode();

  if (mode == CImageView::Mode::ALPHA)
    view_->setMode(CImageView::Mode::NORMAL);
  else
    view_->setMode(CImageView::Mode::ALPHA);
}

void
CQImageViewTest::
scaleSlot(int scale)
{
  view_->setScale(scale);
}

void
CQImageViewTest::
gridSlot(int i)
{
  view_->setGrid(i);
}

void
CQImageViewTest::
autoSizeSlot(int i)
{
  view_->setAutoSize(i);
}

void
CQImageViewTest::
autoScaleSlot(int i)
{
  view_->setAutoScale(i);
}

void
CQImageViewTest::
settingsSlot(bool b)
{
  viewWidth_  = view_->width ();
  viewHeight_ = view_->height();

  controlWidgets_.frame->setVisible(b);

  updateSize();
}

void
CQImageViewTest::
updateState()
{
  toolbarWidgets_.prevButton->setEnabled(imageNum_ > 0);
  toolbarWidgets_.nextButton->setEnabled(imageNum_ < int(images_.size()) - 1);

#if 0
  controlWidgets_.prevButton->setEnabled(imageNum_ > 0);
  controlWidgets_.nextButton->setEnabled(imageNum_ < int(images_.size()) - 1);
#endif
}

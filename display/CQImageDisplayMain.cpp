#include <CQImageDisplayMain.h>
#include <CQImageDisplay.h>

#include <QApplication>
#include <QVBoxLayout>
#include <QImage>

int
main(int argc, char **argv)
{
  QApplication app(argc, argv);

  auto *test = new CQImageDisplayTest;

  auto *layout = new QVBoxLayout(test);
  layout->setMargin(0); layout->setSpacing(0);

  auto *canvas = new CQImageDisplay;

  test->resize(400, 400);

  layout->addWidget(canvas);

  for (int i = 1; i < argc; ++i) {
    auto image = QImage(argv[i]);

    if (! image.isNull())
      canvas->setImage(image);
  }

  test->show();

  return app.exec();
}

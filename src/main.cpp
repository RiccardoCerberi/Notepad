#include<QApplication>
#include<QPushButton>

int main(int argc, char** argv) {
  // istanzio applicazione Qt
  QApplication a(argc, argv);

  // add new icon

  // setup button
  QPushButton* button = new QPushButton("everything works in vim too!!!");
  button->setIcon(QIcon(":/resources/icons/close.png")); // specify the full path src->resources->icons->icon_name.png
  button->setIconSize(QSize(100, 100));
  button->show();

  // eseguo applicazione
  return a.exec();
}


#include<QVBoxLayout>
#include"MainWindow.hpp"

MainWindow::MainWindow() : QWidget(0) {
  _menuBar = new QMenuBar();
  _fileMenu = new QMenu("File");
  _openAction = new QAction(QIcon(":/icons/open.png"), "Open", _fileMenu);

  _editMenu = new QMenu("Edit");
  _aboutMenu = new QMenu("?");
  _menuBar->addMenu(_fileMenu);
  _menuBar->addMenu(_editMenu);
  _menuBar->addMenu(_aboutMenu);

  QVBoxLayout* layout = new QVBoxLayout();
  layout->addWidget(_menuBar);
  setLayout(layout);
}
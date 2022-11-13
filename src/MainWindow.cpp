#include<QVBoxLayout>
#include"MainWindow.hpp"

MainWindow::MainWindow() : QWidget(0) {
  _menuBar = new QMenuBar();

  _fileMenu = new QMenu("File");
	// open file
  _openAction = new QAction(QIcon(":resources/icons/open.png"), "Open", _fileMenu);
	_openAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
	_fileMenu->addAction(_openAction);
	// open recent file
	_openRecentMenu = new QMenu("Open recent");
	_fileMenu->addMenu(_openRecentMenu);
	// save file
	_saveAction = new QAction(QIcon(":resources/icons/save.png"), "Save", _fileMenu);
	_saveAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
	_fileMenu->addAction(_saveAction);
	// "save as" file
	_saveAsAction = new QAction( "Save as", _fileMenu);
	_fileMenu->addAction(_saveAsAction);
	// print file
	_printAction = new QAction(QIcon(":resources/icons/print.png"), "Print", _fileMenu);
	_fileMenu->addSeparator(); // it adds a horizontal line to separate something related to the file integrity
	_printAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_P));
	_fileMenu->addAction(_printAction);
	_fileMenu->addSeparator();
	// exit
	_exitAction = new QAction(QIcon(":resources/icons/exit.png"), "Exit", _fileMenu);
	_exitAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
	_fileMenu->addAction(_exitAction);

  _editMenu = new QMenu("Edit");
	// NOTE: redo and undo are platform dependent
	// redo
	_redoAction = new QAction(QIcon(":resources/icons/redo.png"), "Redo", _fileMenu);
	_redoAction->setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_Z));
	_fileMenu->addAction(_redoAction);
	// undo
	_undoAction = new QAction(QIcon(":resources/icons/undo.png"), "Undo", _fileMenu);
	_undoAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
	_fileMenu->addAction(_undoAction);

  _aboutMenu = new QMenu("?");
	_aboutAction = new QAction(QIcon(":resources/icons/about.png"), "About Notepad", _fileMenu);
	_fileMenu->addAction(_aboutAction);
	_aboutQtAction = new QAction( "About Qt", _fileMenu);
	_fileMenu->addAction(_aboutQtAction);


  _menuBar->addMenu(_fileMenu);
  _menuBar->addMenu(_editMenu);
  _menuBar->addMenu(_aboutMenu);

  QVBoxLayout* layout = new QVBoxLayout();
  layout->addWidget(_menuBar);
  setLayout(layout);
}
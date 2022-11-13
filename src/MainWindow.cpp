#include<QVBoxLayout>
#include"MainWindow.hpp"
#include"Document.hpp"

MainWindow::MainWindow() : QWidget(0) {
  _menuBar = new QMenuBar();
  _fileMenu = new QMenu("File");
	// new file
	_newAction = new QAction(QIcon(":resources/icons/new.png"), "New file", _fileMenu);
	_newAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
	_fileMenu->addAction(_newAction);
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
	_editMenu->addAction(_redoAction);
	// undo
	_undoAction = new QAction(QIcon(":resources/icons/undo.png"), "Undo", _fileMenu);
	_undoAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
	_editMenu->addAction(_undoAction);

	// about menu
  _aboutMenu = new QMenu("?");
	_aboutAction = new QAction(QIcon(":resources/icons/about.png"), "About Notepad", _fileMenu);
	_aboutMenu->addAction(_aboutAction);
	_aboutQtAction = new QAction( "About Qt", _fileMenu);
	_aboutMenu->addAction(_aboutQtAction);

	// add all the menu to the menubar
  _menuBar->addMenu(_fileMenu);
  _menuBar->addMenu(_editMenu);
  _menuBar->addMenu(_aboutMenu);

	_toolBar = new QToolBar();
	_toolBar->addAction(_newAction); // NOTE: creation of the new action
	_toolBar->addAction(_openAction);
	_toolBar->addAction(_saveAction);
	_toolBar->addAction(_printAction);
	_toolBar->addSeparator();
	_toolBar->addAction(_redoAction);
	_toolBar->addAction(_undoAction);
  _toolBar->addSeparator();
  _toolBar->addAction(_aboutAction);

  _tabs = new QTabWidget();
  _tabs->addTab(new Document(), "newfile");

  _statusBar = new QStatusBar();
  _statusBar->showMessage("statusBar ok");

  QVBoxLayout* layout = new QVBoxLayout();
  layout->setContentsMargins(0,0,0,0); // to avoid blanck space between box and menu
  layout->setSpacing(0); // every compnent must be sticked together
  layout->addWidget(_menuBar);
  layout->addWidget(_toolBar);
  layout->addWidget(_tabs);
  layout->addWidget(_statusBar);
  setLayout(layout);
  setMinimumSize(800, 600);

  // connections
  connect(_aboutAction, SIGNAL(triggered()), this, SLOT(aboutActionTriggered()));
  connect(_aboutQtAction, SIGNAL(triggered()), this, SLOT(aboutQtActionTriggered()));
}

void MainWindow::aboutActionTriggered() {
  QString const text("Sample project");
  QMessageBox::about(this, "About Notepad", text); // the last parameters take html file
}

void MainWindow::aboutQtActionTriggered() {
  QMessageBox::aboutQt(this);
}

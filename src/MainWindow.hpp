#pragma once

#include<QWidget>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QToolBar>
#include<QStatusBar>
#include<QTabBar>


/*
  This is the header used to set up the GUI of Notepad.
*/

class MainWindow : public QWidget {
  Q_OBJECT 
private:
  QMenuBar* _menuBar;


  QMenu* _fileMenu;

  QAction* _newAction; // create a new file
  QAction* _openAction; // open an existing file

  QMenu* _openRecentMenu; // open the most recent file. This will create a new Menu

  QAction* _saveAction; // save a file
  QAction* _saveAsAction; // "save as" file
  QAction* _printAction; // print the current document
  QAction* _exitAction; // exit from Notepad


  QMenu* _editMenu;

  QAction* _redoAction; // redo the last action
  QAction _undoAction; // go back to the preovious action


  QMenu* _aboutMenu;
  QAction* _aboutAction; // information about Notepad
  QAction* _aboutQtAction; // information about qt library

  QToolBar* _toolBar;
  
  QTabBar* _tabBar;

  QStatusBar* _statusBar; // it's private because it cannot be modified by the user
public:
  MainWindow();
public slots:

};

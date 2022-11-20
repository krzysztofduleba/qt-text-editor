#include "mainwindow.h"

void MainWindow::setMenu() {
    QAction* fileNew = new QAction("&New", this);
    QAction* fileOpen = new QAction("&Open", this);
    QAction* fileSave = new QAction("&Save", this);
    QAction* fileSaveAs = new QAction("&Save as", this);
    QAction* filePrint = new QAction("&Print", this);

    QMenu* file = menuBar()->addMenu("&File");
    file->addAction(fileNew);
    file->addAction(fileOpen);
    file->addAction(fileSave);
    file->addAction(fileSaveAs);
    file->addAction(filePrint);

    connect(fileNew, &QAction::triggered, this, &MainWindow::newFile);
    connect(fileOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect(fileSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect(fileSaveAs, &QAction::triggered, this, &MainWindow::saveFileAs);
    connect(filePrint, &QAction::triggered, this, &MainWindow::printFile);

    QAction* editCopy = new QAction("&Copy", this);
    QAction* editPaste = new QAction("&Paste", this);
    QAction* editCut = new QAction("&Cut", this);
    QAction* editUndo = new QAction("&Undo", this);
    QAction* editRedo = new QAction("&Redo", this);

    QMenu* edit = menuBar()->addMenu("&Edit");
    edit->addAction(editCopy);
    edit->addAction(editPaste);
    edit->addAction(editCut);
    edit->addAction(editUndo);
    edit->addAction(editRedo);

    connect(editCopy, &QAction::triggered, this, &MainWindow::copy);
    connect(editPaste, &QAction::triggered, this, &MainWindow::paste);
    connect(editCut, &QAction::triggered, this, &MainWindow::cut);
    connect(editUndo, &QAction::triggered, this, &MainWindow::undo);
    connect(editRedo, &QAction::triggered, this, &MainWindow::redo);

    QAction* preferencesFont = new QAction("&Font", this);
    QAction* preferencesLight = new QAction("&Light", this);
    QAction* preferencesDark = new QAction("&Dark", this);
    QAction* preferencesResetAll = new QAction("&Reset all settings", this);

    QMenu* preferences = menuBar()->addMenu("&Preferences");
    preferences->addAction(preferencesFont);
    QMenu* preferencesTheme = preferences->addMenu("&Theme");
    preferencesTheme->addAction(preferencesLight);
    preferencesTheme->addAction(preferencesDark);
    preferences->addAction(preferencesResetAll);

    connect(preferencesFont, &QAction::triggered, this, &MainWindow::selectFont);
    connect(preferencesLight, &QAction::triggered, this, &MainWindow::setLightTheme);
    connect(preferencesDark, &QAction::triggered, this, &MainWindow::setDarkTheme);
    connect(preferencesResetAll, &QAction::triggered, this, &MainWindow::resetAllSettings);
}

void MainWindow::setToolBar() {
    QToolBar* toolBar = new QToolBar(this);
    toolBar->setWindowTitle("Tool bar");
    toolBar->setMovable(false);

    newFileAction = toolBar->addAction(QIcon(":/icons/icons/new.png"), "New");
    openFileAction = toolBar->addAction(QIcon(":/icons/icons/open.png"), "Open");
    saveFileAction = toolBar->addAction(QIcon(":/icons/icons/save.png"), "Save");
    selectFontAction = toolBar->addAction(QIcon(":/icons/icons/font.png"), "Font");
    printFileAction = toolBar->addAction(QIcon(":/icons/icons/print.png"), "Print");
    toggleThemeAction = toolBar->addAction(QIcon(":/icons/icons/theme.png"), "Toggle theme");

    connect(newFileAction, &QAction::triggered, this, &MainWindow::newFile);
    connect(openFileAction, &QAction::triggered, this, &MainWindow::openFile);
    connect(saveFileAction, &QAction::triggered, this, &MainWindow::saveFile);
    connect(selectFontAction, &QAction::triggered, this, &MainWindow::selectFont);
    connect(printFileAction, &QAction::triggered, this, &MainWindow::printFile);
    connect(toggleThemeAction, &QAction::triggered, this, &MainWindow::toggleTheme);

    addToolBar(Qt::TopToolBarArea, toolBar);
}

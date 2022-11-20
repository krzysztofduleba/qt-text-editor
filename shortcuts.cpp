#include "mainwindow.h"

void MainWindow::setShortcuts() {
    increaseFontShortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Plus), this);
    connect(increaseFontShortcut, &QShortcut::activated, this, &MainWindow::increaseFontSize);

    decreaseFontShortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Minus), this);
    connect(decreaseFontShortcut, &QShortcut::activated, this, &MainWindow::decreaseFontSize);

    newFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    openFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    saveFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    selectFontAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));
    printFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_P));
    toggleThemeAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_T));
}

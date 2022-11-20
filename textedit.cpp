#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::copy() {
    textEdit->copy();
}

void MainWindow::paste() {
    textEdit->paste();
}

void MainWindow::cut() {
    textEdit->cut();
}

void MainWindow::undo() {
    textEdit->undo();
}

void MainWindow::redo() {
    textEdit->redo();
}

void MainWindow::showCursorPos() {
    int line = textEdit->textCursor().blockNumber()+1;
    int pos = textEdit->textCursor().columnNumber()+1;
    ui->statusbar->showMessage(QString("Ln %1, Col %2").arg(line).arg(pos));
}

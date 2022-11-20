#include "mainwindow.h"

void MainWindow::selectFont() {
    bool selectedFont;
    font = QFontDialog::getFont(&selectedFont, QFont(fontFamily, fontSize), this);

    if (selectedFont) {
        fontSize = font.pointSize();
        fontFamily = font.family();
        textEdit->setFont(font);
    }
}

void MainWindow::increaseFontSize() {
    if (font.pointSize() <= 70) {
        fontSize += 2;
        font.setPointSize(fontSize);
        textEdit->setFont(font);
    }
}

void MainWindow::decreaseFontSize() {
    if (font.pointSize() >= 4) {
        fontSize -= 2;
        font.setPointSize(fontSize);
        textEdit->setFont(font);
    }
}

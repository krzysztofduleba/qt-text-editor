#include "mainwindow.h"

void MainWindow::toggleTheme() {
    theme == "light" ? MainWindow::setDarkTheme() : MainWindow::setLightTheme();
}

void MainWindow::setDarkTheme() {
    theme = "dark";

    QPalette palette = textEdit->palette();
    palette.setColor(QPalette::Text, "#e0e0e0");
    palette.setColor(QPalette::Base, "#1e1e1e");
    textEdit->setPalette(palette);

    textEdit->moveCursor(QTextCursor::NoMove);
}

void MainWindow::setLightTheme() {
    theme = "light";

    QPalette palette = textEdit->palette();
    palette.setColor(QPalette::Text, Qt::black);
    palette.setColor(QPalette::Base, Qt::white);
    textEdit->setPalette(palette);

    textEdit->moveCursor(QTextCursor::NoMove);
}

void MainWindow::highlightCurrentLine() {
    QList<QTextEdit::ExtraSelection> extraSelections;
    QTextEdit::ExtraSelection selection;

    QColor lineColor;
    theme == "light" ? lineColor = QColor(Qt::yellow).lighter(160) : lineColor = QColor(Qt::yellow).lighter(40);

    selection.format.setBackground(lineColor);
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    selection.cursor = textEdit->textCursor();
    selection.cursor.clearSelection();
    extraSelections.append(selection);

    textEdit->setExtraSelections(extraSelections);
}

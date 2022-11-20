#include "mainwindow.h"

void MainWindow::newFile() {
    setWindowTitle("Text Editor");
    fileName.clear();
    textEdit->setPlainText(QString(""));
}

void MainWindow::openFile() {
    fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);

    if (file.open(QIODevice::ReadOnly | QFile::Text)) {
        setWindowTitle(fileName);
        QTextStream in(&file);
        QString text = in.readAll();
        textEdit->setPlainText(text);
        file.close();
        isSaved = true;
    }
}

void MainWindow::saveFile() {
    if (fileName.isEmpty()) {
        MainWindow::saveFileAs();
        return;
    }

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QFile::Text)) {
        setWindowTitle(fileName);
        QTextStream out(&file);
        QString text = textEdit->toPlainText();
        out << text;
        file.close();
        isSaved = true;
    }
}

void MainWindow::saveFileAs() {
    fileName =
            QFileDialog::getSaveFileName(
                this,
                tr("Save as"),
                "",
                tr("Text file (*.txt);;" "C File (*.c);;" "Cpp File (*.cpp)"));

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QFile::Text)) {
        setWindowTitle(fileName);
        QTextStream out(&file);
        QString text = textEdit->toPlainText();
        out << text;
        file.close();
        isSaved = true;
    }
}

void MainWindow::printFile() {
    QPrinter printer;
    QPrintDialog pDialog(&printer, this);

    if(pDialog.exec() != QDialog::Rejected) {
        textEdit->print(&printer);
    }
}

void MainWindow::resetIsSaved() {
    isSaved = false;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    QFile file(fileSettings);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);
    out << theme << '\n'
        << fontSize << '\n'
        << fontFamily;
    file.close();

    if (isSaved == false) {
        QMessageBox::StandardButton resBtn =
                QMessageBox::question(
                    this,
                    "Text Editor",
                    tr("You are trying to quit " "without saving the file.\n" "Are you sure?\n"),
                    QMessageBox::No | QMessageBox::Yes);

        if (resBtn != QMessageBox::Yes) {
            event->ignore();
        } else {
            event->accept();
        }
    }
}

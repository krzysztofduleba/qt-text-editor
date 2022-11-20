#include "mainwindow.h"

void MainWindow::loadSettings() {
    QFile file(fileSettings);
    if (QFileInfo::exists(fileSettings)) {
        MainWindow::loadSettingsFromFile();
    }
    else {
        loadDefaultSettings();
    }
}

void MainWindow::loadSettingsFromFile() {
    QFile file(fileSettings);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line;

        while (!in.atEnd()) {
            theme = in.readLine();
            fontSize = in.readLine().toInt();
            fontFamily = in.readLine();
        }

        file.close();

        if (theme == "light") {
            MainWindow::setLightTheme();
        }
        else if (theme == "dark") {
            MainWindow::setDarkTheme();
        }

        font.setPointSize(fontSize);
        font.setFamily(fontFamily);
        textEdit->setFont(font);
    }
}

void MainWindow::loadDefaultSettings() {
    MainWindow::setLightTheme();

    fontSize = 12;
    font.setPointSize(fontSize);

    fontFamily = "Consolas";
    font.setFamily(fontFamily);

    textEdit->setFont(font);
}

void MainWindow::resetAllSettings() {
    loadDefaultSettings();
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QPrinter>
#include <QPrintDialog>
#include <QLineEdit>
#include <QTextCursor>
#include <QShortcut>
#include <QColorDialog>
#include <QFontDialog>
#include <QFont>
#include <QFontDatabase>
#include <QtWidgets>
#include <QLineEdit>
#include <QWidget>
#include <QCloseEvent>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    /* Attributes */
    Ui::MainWindow *ui;
    QPlainTextEdit* textEdit;
    QString fileName;
    QString theme;
    const QString fileSettings = "settings.txt";
    int fontSize;
    QString fontFamily;
    QFont font;
    bool isSaved;

    QShortcut* increaseFontShortcut;
    QShortcut* decreaseFontShortcut;

    QAction* newFileAction;
    QAction* openFileAction;
    QAction* saveFileAction;
    QAction* selectFontAction;
    QAction* printFileAction;
    QAction* toggleThemeAction;

    /* Methods */
    void setMenu();
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void printFile();
    void closeEvent(QCloseEvent *event);
    void copy();
    void paste();
    void cut();
    void undo();
    void redo();
    void selectFont();
    void showCursorPos();
    void setupEditor();
    void loadSettings();
    void loadSettingsFromFile();
    void loadDefaultSettings();
    void toggleTheme();
    void setDarkTheme();
    void setLightTheme();
    void setToolBar();
    void highlightCurrentLine();
    void resetIsSaved();
    void increaseFontSize();
    void decreaseFontSize();
    void setShortcuts();
    void resetAllSettings();

};

#endif // MAINWINDOW_H

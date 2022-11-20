#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("Text Editor");
    textEdit = new QPlainTextEdit(this);
    this->setCentralWidget(textEdit);

    MainWindow::setupEditor();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupEditor() {
    MainWindow::loadSettings();
    MainWindow::setMenu();
    MainWindow::setToolBar();
    MainWindow::setShortcuts();
    MainWindow::highlightCurrentLine();

    isSaved = true;

    connect(textEdit, &QPlainTextEdit::textChanged, this, &MainWindow::resetIsSaved);
    connect(textEdit, &QPlainTextEdit::cursorPositionChanged, this, &MainWindow::showCursorPos);
    connect(textEdit, &QPlainTextEdit::cursorPositionChanged, this, &MainWindow::highlightCurrentLine);
}

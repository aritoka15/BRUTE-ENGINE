#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 👇 Aquí dentro sí va bien
    QFont retroFont("DotGothic16", 10);
    this->menuBar()->setFont(retroFont);

    for (QAction *action : this->menuBar()->actions()) {
        if (QMenu *menu = action->menu()) {
            menu->setFont(retroFont);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

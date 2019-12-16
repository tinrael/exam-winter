#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    addTasks();
    addApproaches();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTasks()
{
    tasks.emplace_back(std::make_shared<Task>("square", 15));
    tasks.emplace_back(std::make_shared<Task>("matrix multiplication", 35));
    tasks.emplace_back(std::make_shared<Task>("matrix subtraction", 5));
    tasks.emplace_back(std::make_shared<Task>("square", 10));
    tasks.emplace_back(std::make_shared<Task>("integral", 45));

    for (std::shared_ptr<Task> &task : tasks) {
        ui->lwTasks->addItem(QString::fromStdString(task->getType()));
    }
}

void MainWindow::addApproaches()
{
    approaches.emplace_back(std::make_shared<ApproachTypeA>("square", 0.2, true, 15));
    approaches.emplace_back(std::make_shared<ApproachTypeA>("integral", 0.9, false, 20));
    approaches.emplace_back(std::make_shared<ApproachTypeA>("integral", 0.9, false, 20));
    approaches.emplace_back(std::make_shared<ApproachTypeB>("square", 0.01, false, 5));
    approaches.emplace_back(std::make_shared<ApproachTypeB>("derivative", 0.4, true, 7));
    approaches.emplace_back(std::make_shared<ApproachTypeB>("matrix multiplication", 0.4, true, 7));
    approaches.emplace_back(std::make_shared<ApproachTypeC>("square", 0.02, false, 10));
    approaches.emplace_back(std::make_shared<ApproachTypeC>("matrix multiplication", 0.03, true, 25));

    for (std::shared_ptr<Approach> &approach : approaches) {
        ui->lwApproaches->addItem(QString::fromStdString(approach->getTaskType()));
    }
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDateTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tblResults->setColumnWidth(0, 175);
    ui->tblResults->setColumnWidth(1, 175);
    ui->tblResults->setHorizontalHeaderLabels(QStringList{
                                                  "Task",
                                                  "Approach",
                                                  "Time",
                                                  "Probability",
                                                  "Result"
                                                  });

    addTasks();
    addApproaches();

    QObject::connect(ui->lwTasks, &QListWidget::currentRowChanged, this, &MainWindow::setSolveButtonEnabled);
    QObject::connect(ui->lwApproaches, &QListWidget::currentRowChanged, this, &MainWindow::setSolveButtonEnabled);
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

void MainWindow::calculate()
{
    std::shared_ptr<Task> task = tasks[ui->lwTasks->currentRow()];
    std::shared_ptr<Approach> approach = approaches[ui->lwApproaches->currentRow()];

    bool isSolved = approach->solve(*task);
    addResultToTable(*task, *approach, isSolved);
}

void MainWindow::addResultToTable(Task &task, Approach &approach, bool isSolved)
{
    QString currentDateTime = QDateTime::currentDateTime().toString();
    QString taskType = QString::fromStdString(task.getType());
    QString approachType = QString::fromStdString(approach.getTaskType());
    QString successProbability = QString::number(approach.getSuccessProbability(task));
    QString timeSolving = QString::number(approach.getTimeSolving(task));

    int rowCount = ui->tblResults->rowCount();
    ui->tblResults->setRowCount(rowCount + 1);

    QTableWidgetItem* itemTaskType = new QTableWidgetItem(taskType);
    ui->tblResults->setItem(rowCount, 0, itemTaskType);

    QTableWidgetItem* itemApproachType = new QTableWidgetItem(approachType);
    ui->tblResults->setItem(rowCount, 1, itemApproachType);

    QTableWidgetItem* itemTimeSolving = new QTableWidgetItem(timeSolving);
    ui->tblResults->setItem(rowCount, 2, itemTimeSolving);

    QTableWidgetItem* itemSuccessProbability = new QTableWidgetItem(successProbability);
    ui->tblResults->setItem(rowCount, 3, itemSuccessProbability);

    QTableWidgetItem* itemSolved = new QTableWidgetItem(QString::number(isSolved));
    ui->tblResults->setItem(rowCount, 4, itemSolved);
}

void MainWindow::setSolveButtonEnabled()
{
    if (ui->lwTasks->currentRow() != -1 && ui->lwApproaches->currentRow() != -1) {
        ui->pbSolve->setEnabled(true);
    }
    else {
        ui->pbSolve->setEnabled(false);
    }
}

void MainWindow::on_pbSolve_clicked()
{
    calculate();
}

#include "mainboard.h"
#include "./ui_mainboard.h"
#include <iostream>
#include <BoardSolution.h>
#define CELL_SIZE 50

MainBoard::MainBoard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainBoard)
{
    ui->setupUi(this);
    makeConnections();
    initComponents();
}

MainBoard::~MainBoard()
{
    delete ui;
}

void MainBoard::initComponents(){

    ui->mainBoardTable->horizontalHeader()->setDefaultSectionSize(CELL_SIZE);
    ui->mainBoardTable->verticalHeader()->setDefaultSectionSize(CELL_SIZE);
    ui->mainBoardTable->horizontalHeader()->sectionResizeMode(QHeaderView::Fixed);
    ui->mainBoardTable->verticalHeader()->sectionResizeMode(QHeaderView::Fixed);
    ui->mainBoardTable->verticalHeader()->hide();
    ui->mainBoardTable->horizontalHeader()->hide();

    ui->rowCount->setValidator( new QIntValidator(0, 15, this) );
    ui->columnCount->setValidator( new QIntValidator(0, 15, this) );


    ui->mainBoardTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->mainBoardTable->setFocusPolicy(Qt::NoFocus);
    ui->mainBoardTable->setSelectionMode(QAbstractItemView::NoSelection);
}

void MainBoard::makeConnections(){
    connect(ui->applySizeBtn, SIGNAL(clicked()), this, SLOT(applySizeClicked()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clearBoard()));
    connect(ui->calculateGroups, SIGNAL(clicked()), this, SLOT(calculateGroups()));
    connect(ui->mainBoardTable, SIGNAL(cellClicked(int, int)), this, SLOT(clickedCell(int, int)));

}

void MainBoard::applySizeClicked(){
    int rowCount = ui->rowCount->text().toInt();
    int columnCount = ui->columnCount->text().toInt();

    ui->mainBoardTable->setRowCount(rowCount);
    ui->mainBoardTable->setColumnCount(columnCount);

    ui->mainBoardTable->setMinimumHeight(CELL_SIZE * rowCount + CELL_SIZE / 10);
    ui->mainBoardTable->setMinimumWidth(CELL_SIZE * columnCount + CELL_SIZE / 10);
    BoardSolution::getBoard()->SetSize(rowCount, columnCount);
}

void MainBoard::clickedCell(int row, int column){
    if(BoardSolution::getBoard()->isFilled(row,column)){
        ui->mainBoardTable->setItem(row, column, new QTableWidgetItem);
        BoardSolution::getBoard()->SetZero(row,column);
    }else{
        ui->mainBoardTable->setItem(row, column, new QTableWidgetItem);
        ui->mainBoardTable->item(row, column)->setBackground(Qt::white);
        BoardSolution::getBoard()->SetOne(row, column);
    }

}

void MainBoard::clearBoard(){
    for(int i = 0; i < ui->mainBoardTable->rowCount(); i++){
        for (int j = 0; j < ui->mainBoardTable->columnCount(); j++) {
            ui->mainBoardTable->setItem(i, j, new QTableWidgetItem);

        }
    }
     BoardSolution::getBoard()->ClearBoard();
}

void MainBoard::calculateGroups(){
    int numberOfGroups = BoardSolution::getSolution()->Run();

    auto board = BoardSolution::getBoard()->GetBoard();
    std::map <int, int> labelColors;
    int colorCounter = 6;
    for(auto point:board ){
        if(point.second > 1){
            if(labelColors.find(point.second) == labelColors.end()){
                labelColors[point.second] = ++colorCounter;
                std::cout << point.first.x << "," << point.first.y << std::endl;
            }

            ui->mainBoardTable->setItem(point.first.x, point.first.y, new QTableWidgetItem);
            ui->mainBoardTable->item(point.first.x, point.first.y)->setBackground((Qt::GlobalColor)labelColors[point.second]);
            BoardSolution::getBoard()->SetOne(point.first.x, point.first.y);
        }


    }
    std::cout << "Number of groups : " << numberOfGroups << std::endl;

}



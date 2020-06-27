#include <BoardSolution.h>
#include <iostream>
#include <vector>
BoardSolution * BoardSolution::solution;

BoardSolution *BoardSolution::getInstance()
{
    if(solution == nullptr){
        solution = new BoardSolution();
        solution->connectivity.push_back(Point(-1, 0));
        solution->connectivity.push_back(Point( 0,-1));
        solution->connectivity.push_back(Point( 0, 1));
        solution->connectivity.push_back(Point( 1, 0));
    }
    return solution;
}

void BoardSolution::ConnectComponents(Point point, int label){
    this->mainBoard[point] = label;
    for (auto offset: connectivity){
        Point newPoint;
        newPoint.x = point.x + offset.x;
        newPoint.y = point.y + offset.y;
        if (isFilled(newPoint.x, newPoint.y)){
            ConnectComponents(newPoint,label);
        }

    }
}

int BoardSolution::Run()
{
    totalLabelCount = 1;
    for(int i = 0; i < this->rowCount;i++){
        for (int j = 0; j < this->colCount;j++) {
             if (isFilled(i,j)){
                 totalLabelCount++;
                ConnectComponents(Point(i,j), totalLabelCount);
             }
        }
    }
    Print();
    int totalLabel = 0;
    return totalLabel;
}

void BoardSolution::Exit(){

}

void BoardSolution::SetSize(const int numRows, const int numCols)
{
    this->mainBoard.clear();
    this->rowCount = numRows;
    this->colCount = numCols;
    for(int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++) {
            this->mainBoard[Point(i,j)] = false;
        }
    }
}

void BoardSolution::GetSize(int &numRows, int &numCols)
{
    numRows = rowCount;
    numCols = colCount;
}

void BoardSolution::SetZero(const int row, const int col)
{
    this->mainBoard[Point(row,col)] = 0;
}

void BoardSolution::SetOne(const int row, const int col)
{
    this->mainBoard[Point(row,col)] = 1;
}

bool BoardSolution::checkRowAndCol(const int row, const int col){
    return !(row < 0 || col < 0 || row > rowCount || col > colCount);
}

bool BoardSolution::isLabelled(const int row, const int col){
    if(checkRowAndCol(row,col)){
        return this->mainBoard[Point(row,col)] > 1;
    }else{
        return false;
    }
}

bool BoardSolution::isFilled(const int row, const int col)
{
    if(checkRowAndCol(row,col)){
        return this->mainBoard[Point(row,col)] == 1;
    }else{
        return false;
    }
}

void BoardSolution::Print()
{
    std::cout << "---------Table Content-----------" << std::endl;
    for (int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++){
            std::cout << this->mainBoard[Point(i,j)] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "---------Table Content End-----------" << std::endl;

}

void BoardSolution::ClearBoard(){
    totalLabelCount = 1;
    for (int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++){
            SetZero(i,j);
        }
    }
}

BoardInterface *BoardSolution::getBoard()
{
    return getInstance();
}

SolutionInterface *BoardSolution::getSolution()
{
    return getInstance();
}


std::map<Point, int> BoardSolution::GetBoard()
{
    return this->mainBoard;
}

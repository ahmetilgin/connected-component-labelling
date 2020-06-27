#ifndef BOARDSOLUTION_H
#define BOARDSOLUTION_H
#include <BoardInterface.h>
#include <SolutionInterface.h>
#include <Point.h>
#include <map>
#include <vector>
class BoardSolution : public BoardInterface, public SolutionInterface{
private:
    std::map<Point, int> mainBoard;
    int rowCount, colCount;
    static BoardSolution * solution;
    static BoardSolution *getInstance();
    int totalLabelCount = 1;
    std::vector<Point> connectivity;
    // SolutionInterface interface
public:
    BoardSolution(){}
    int Run();
    void Exit();
    // BoardInterface interface
public:
    void SetSize(const int numRows, const int numCols);
    void GetSize(int &numRows, int &numCols);
    void SetZero(const int row, const int col);
    void SetOne(const int row, const int col);
    bool isFilled(const int row, const int col);
    void Print();
public:
    static BoardInterface * getBoard();
    static SolutionInterface *getSolution();
    bool isLabelled(const int row, const int col);
    void ClearBoard();
    std::map<Point, int> GetBoard();
private:
    bool checkRowAndCol(const int row, const int col);
    void ConnectComponents(Point point, int label);
};

#endif // BOARDSOLUTION_H

#ifndef MAINBOARD_H
#define MAINBOARD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainBoard; }
QT_END_NAMESPACE

class MainBoard : public QMainWindow
{
    Q_OBJECT

public:
    MainBoard(QWidget *parent = nullptr);
    ~MainBoard();
    void makeConnections();
public slots:
    void applySizeClicked();
    void clickedCell(int row, int column);
    void clearBoard();
    void calculateGroups();
private:
    Ui::MainBoard *ui;
    void initComponents();
};
#endif // MAINBOARD_H

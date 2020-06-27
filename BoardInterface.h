#ifndef BOARDINTERFACE_H
#define BOARDINTERFACE_H
#include <Point.h>
#include <map>
class BoardInterface {
public:
    virtual ~BoardInterface() {}
    // Alan boyutlarını belirlemek için kullanılır.
    virtual void SetSize(const int numRows, const int numCols) = 0;
    // Alan boyutlarını sorgulamak için kullanılır.
    virtual void GetSize(int & numRows, int & numCols) = 0;
    // Verilen satır ve sütunu silmek için kullanılır.
    virtual void SetZero(const int row, const int col) = 0;
    // Verilen satır ve sütunu doldurmak için kullanılır.
    virtual void SetOne(const int row, const int col) = 0;
    // Verilen satır ve sütunun durumunu sorgulamak için kullanılır.
    virtual bool isFilled(const int row, const int col) = 0;
    // Alanın içeriğini yazdırmak için kullanılır.
    virtual void Print() = 0;
    // Alanı sıfırlar
    virtual void ClearBoard() = 0 ;
    // Alanı almak için kullanılır.
    virtual std::map<Point, int> GetBoard() = 0;

};


#endif // BOARDINTERFACE_H

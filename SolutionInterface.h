#ifndef SOLUTIONINTERFACE_H
#define SOLUTIONINTERFACE_H
#include <BoardInterface.h>
class SolutionInterface {
public:
    virtual ~SolutionInterface() {}
    // Çözüm öncesi hazırlıklar için kullanılır.
    virtual int Run() = 0;
    // Çözüm sonrası işlemler için kullanılır.
    virtual void Exit() = 0;
};
#endif // SOLUTIONINTERFACE_H

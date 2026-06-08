#ifndef STACKCANCEL_H
#define STACKCANCEL_H
#include "Models.h"

class StackCancel {
private:
    Ticket* top;
public:
    StackCancel();
    void push(Ticket* t);
    Ticket* pop();
    void displayStack();
};

#endif
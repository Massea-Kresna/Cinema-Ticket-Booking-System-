#ifndef QUEUETICKET_H
#define QUEUETICKET_H
#include "Models.h"

class QueueTicket {
private:
    Ticket* head;
    Ticket* tail;
    int count;
public:
    QueueTicket();
    void enqueue(int id, std::string name, int movieId);
    Ticket* dequeue(); // Menghapus dari antrian untuk diproses/dibatalkan
    void displayQueue();
    int getCount();
};

#endif
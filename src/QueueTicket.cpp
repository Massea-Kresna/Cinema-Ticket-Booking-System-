#include "QueueTicket.h"
#include <iostream>

QueueTicket::QueueTicket() : head(nullptr), tail(nullptr), count(0) {}

void QueueTicket::enqueue(int id, std::string name, int movieId) {
    Ticket* newTicket = new Ticket{id, name, movieId, nullptr};
    if (tail == nullptr) {
        head = tail = newTicket;
    } else {
        tail->next = newTicket;
        tail = newTicket;
    }
    count++;
}

Ticket* QueueTicket::dequeue() {
    if (head == nullptr) return nullptr;
    Ticket* temp = head;
    head = head->next;
    if (head == nullptr) tail = nullptr;
    temp->next = nullptr;
    count--;
    return temp;
}

void QueueTicket::displayQueue() {
    if (head == nullptr) {
        std::cout << "Antrian kosong.\n";
        return;
    }
    Ticket* temp = head;
    std::cout << "--- Daftar Antrian ---\n";
    while (temp != nullptr) {
        std::cout << "ID Tiket: " << temp->id << " | Nama: " << temp->customerName << " | ID Film: " << temp->movieId << "\n";
        temp = temp->next;
    }
}

int QueueTicket::getCount() {
    return count;
}
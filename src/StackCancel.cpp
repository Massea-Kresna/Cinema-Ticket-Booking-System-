#include "StackCancel.h"
#include <iostream>

StackCancel::StackCancel() : top(nullptr) {}

void StackCancel::push(Ticket* t) {
    if (t == nullptr) return;
    t->next = top;
    top = t;
}

Ticket* StackCancel::pop() {
    if (top == nullptr) return nullptr;
    Ticket* temp = top;
    top = top->next;
    temp->next = nullptr;
    return temp;
}

void StackCancel::displayStack() {
    if (top == nullptr) {
        std::cout << "Tidak ada riwayat pembatalan.\n";
        return;
    }
    std::cout << "--- Riwayat Pembatalan (Terbaru di atas) ---\n";
    Ticket* temp = top;
    while (temp != nullptr) {
        std::cout << "ID Tiket: " << temp->id << " | Nama: " << temp->customerName << "\n";
        temp = temp->next;
    }
}
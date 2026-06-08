#ifndef MODELS_H
#define MODELS_H

#include <string>

struct Movie {
    int id;
    std::string title;
    std::string time;
    int studio;
};

struct Ticket {
    int id;
    std::string customerName;
    int movieId;
    Ticket* next; // Pointer untuk Linked List (Queue & Stack)
};

#endif
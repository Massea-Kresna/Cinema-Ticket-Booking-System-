#ifndef MOVIESCHEDULE_H
#define MOVIESCHEDULE_H
#include "Models.h"

class MovieSchedule {
private:
    void merge(Movie arr[], int left, int mid, int right);
public:
    void mergeSort(Movie arr[], int left, int right);
    int binarySearch(Movie arr[], int left, int right, int searchId);
    void displayMovies(Movie arr[], int size);
};

#endif
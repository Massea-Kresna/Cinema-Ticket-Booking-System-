#include "MovieSchedule.h"
#include <iostream>

void MovieSchedule::merge(Movie arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Movie* L = new Movie[n1];
    Movie* R = new Movie[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].id <= R[j].id) {
            arr[k] = L[i]; i++;
        } else {
            arr[k] = R[j]; j++;
        }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }

    delete[] L;
    delete[] R;
}

void MovieSchedule::mergeSort(Movie arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int MovieSchedule::binarySearch(Movie arr[], int left, int right, int searchId) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid].id == searchId) return mid;
        if (arr[mid].id > searchId) return binarySearch(arr, left, mid - 1, searchId);
        return binarySearch(arr, mid + 1, right, searchId);
    }
    return -1;
}

void MovieSchedule::displayMovies(Movie arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "[" << arr[i].id << "] " << arr[i].title << " - " << arr[i].time << " (Studio " << arr[i].studio << ")\n";
    }
}
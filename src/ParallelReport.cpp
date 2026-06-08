#include "ParallelReport.h"
#include <iostream>
#include <thread>

void ParallelReport::countTicketsPerStudio(Ticket* processedArr, int size, int targetMovieId, int* resultCount) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (processedArr[i].movieId == targetMovieId) {
            count++;
        }
    }
    *resultCount = count;
}

void ParallelReport::generateReport(Ticket* processedArr, int size, Movie* movies, int numMovies) {
    int* results = new int[numMovies];
    std::thread* threads = new std::thread[numMovies];

    // Menjalankan thread secara paralel untuk setiap studio/film
    for (int i = 0; i < numMovies; i++) {
        threads[i] = std::thread(countTicketsPerStudio, processedArr, size, movies[i].id, &results[i]);
    }

    // Menunggu semua thread selesai (Join)
    for (int i = 0; i < numMovies; i++) {
        threads[i].join();
    }

    std::cout << "\n=== Rekap Penonton Per Studio ===\n";
    for (int i = 0; i < numMovies; i++) {
        std::cout << "Studio " << movies[i].studio << " (" << movies[i].title << ") : " << results[i] << " Penonton\n";
    }

    delete[] results;
    delete[] threads;
}
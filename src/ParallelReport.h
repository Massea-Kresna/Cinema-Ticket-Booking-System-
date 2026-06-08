#ifndef PARALLELREPORT_H
#define PARALLELREPORT_H
#include "Models.h"

class ParallelReport {
public:
    // Fungsi statis agar mudah dilempar ke thread
    static void countTicketsPerStudio(Ticket* processedArr, int size, int targetMovieId, int* resultCount);
    void generateReport(Ticket* processedArr, int size, Movie* movies, int numMovies);
};

#endif
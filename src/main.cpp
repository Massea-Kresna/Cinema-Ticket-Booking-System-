#include <iostream>
#include "QueueTicket.h"
#include "StackCancel.h"
#include "MovieSchedule.h"
#include "ParallelReport.h"

using namespace std;

int main() {
    QueueTicket queue;
    StackCancel stack;
    MovieSchedule schedule;
    ParallelReport report;

    // Inisialisasi Data Film (Acak untuk simulasi sorting)
    int numMovies = 4;
    Movie movies[] = {
        {104, "Inception", "20:00", 2},
        {101, "Interstellar", "13:00", 1},
        {103, "Oppenheimer", "18:30", 3},
        {102, "Dune: Part Two", "15:45", 4}
    };

    // Array manual untuk menyimpan tiket yang sukses diproses (untuk laporan paralel)
    int maxProcessed = 100;
    Ticket* processedTickets = new Ticket[maxProcessed];
    int processedCount = 0;

    int ticketCounter = 1;
    int choice;

    do {
        cout << "\n=== CINEMA TICKET BOOKING SYSTEM ===\n";
        cout << "1. Tambah Antrian Pemesanan\n";
        cout << "2. Proses Pembelian (Sukses)\n";
        cout << "3. Batalkan Antrian Depan (Masuk Riwayat)\n";
        cout << "4. Undo Pembatalan Terakhir\n";
        cout << "5. Lihat Antrian & Riwayat\n";
        cout << "6. Cari Jadwal Film (Merge Sort & Binary Search)\n";
        cout << "7. Laporan Paralel (Rekap Penonton)\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int movieId;
                cout << "Nama Pelanggan: "; cin >> ws; getline(cin, name);
                cout << "ID Film: "; cin >> movieId;
                queue.enqueue(ticketCounter++, name, movieId);
                cout << "Tiket masuk antrian!\n";
                break;
            }
            case 2: {
                Ticket* t = queue.dequeue();
                if (t) {
                    if (processedCount < maxProcessed) {
                        processedTickets[processedCount] = *t;
                        processedCount++;
                    }
                    cout << "Tiket a.n " << t->customerName << " berhasil diproses!\n";
                    delete t;
                } else {
                    cout << "Antrian kosong!\n";
                }
                break;
            }
            case 3: {
                Ticket* t = queue.dequeue();
                if (t) {
                    stack.push(t);
                    cout << "Pemesanan a.n " << t->customerName << " dibatalkan.\n";
                } else {
                    cout << "Antrian kosong!\n";
                }
                break;
            }
            case 4: {
                Ticket* t = stack.pop();
                if (t) {
                    queue.enqueue(t->id, t->customerName, t->movieId);
                    cout << "Undo berhasil! " << t->customerName << " kembali ke antrian.\n";
                    delete t; 
                } else {
                    cout << "Tidak ada riwayat pembatalan.\n";
                }
                break;
            }
            case 5: {
                queue.displayQueue();
                cout << "\n";
                stack.displayStack();
                break;
            }
            case 6: {
                // Implementasi Divide & Conquer
                schedule.mergeSort(movies, 0, numMovies - 1);
                cout << "\nJadwal Terurut (Berdasarkan ID):\n";
                schedule.displayMovies(movies, numMovies);

                int searchId;
                cout << "\nMasukkan ID Film yang dicari: ";
                cin >> searchId;
                int index = schedule.binarySearch(movies, 0, numMovies - 1, searchId);
                
                if (index != -1) {
                    cout << "Ditemukan: " << movies[index].title << " di Studio " << movies[index].studio << "\n";
                } else {
                    cout << "Film tidak ditemukan!\n";
                }
                break;
            }
            case 7: {
                report.generateReport(processedTickets, processedCount, movies, numMovies);
                break;
            }
        }
    } while (choice != 0);

    delete[] processedTickets;
    return 0;
}
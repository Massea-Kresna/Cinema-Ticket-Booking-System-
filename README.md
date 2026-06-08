---

## 📌 Anggota Kelompok
* **Massea Kresna Aravena Putra Febrianto** - (NIM: 21120124120027) - *Teknik Komputer, Universitas Diponegoro*
* **Rakha Aljiva Prabaswara** - (NIM: 21120124140126) - *Teknik Komputer, Universitas Diponegoro*
* **Mayo Pinto Denai** - (NIM: 21120124140133) - *Teknik Komputer, Universitas Diponegoro*

---

## 📖 Deskripsi Kasus
Sistem ini dirancang untuk mensimulasikan manajemen layanan pada bioskop pintar (*Smart Cinema*). Aplikasi ini mampu mengelola antrean pemesanan tiket pelanggan, menyimpan riwayat pembatalan tiket untuk mendukung fitur pembatalan instan (*Undo*), mengurutkan serta mencari jadwal film secara efisien, serta melakukan kalkulasi statistik penonton per studio secara simultan memanfaatkan pemrosesan paralel (*Multithreading*).

Seluruh komponen struktur data dan algoritma dalam program ini dibangun menggunakan **Native C++** (tanpa pustaka kontainer bawaan seperti `<queue>`, `<stack>`, atau `<algorithm>`) untuk mendemonstrasikan pemahaman mendalam mengenai alokasi memori dinamis (*pointer*) dan efisiensi algoritma.

---

## 🛠️ Implementasi Konsep Algoritma & Struktur Data

Aplikasi ini mengintegrasikan 5 konsep utama sesuai dengan spesifikasi lembar tugas:

1. **Queue (Antrian Pembelian Tiket):** Menggunakan representasi *Linked List* dinamis untuk mengelola antrean pelanggan dengan prinsip *First In, First Out* (FIFO).
2. **Stack (Riwayat Pembatalan Tiket):** Menyimpan tiket yang dibatalkan ke dalam struktur data tumpukan berprinsip *Last In, First Out* (LIFO) untuk mengakomodasi fitur *Undo*.
3. **Divide & Conquer (Manajemen Jadwal Film):**
   * **Merge Sort:** Mengurutkan array objek jadwal film berdasarkan ID Film secara *stable* dengan memecah dan menggabungkan sub-array.
   * **Binary Search:** Mencari jadwal film tertentu pada data yang telah terurut dengan memotong ruang pencarian menjadi setengah di setiap rekursi.
4. **Algoritma Paralel (Rekapitulasi Penonton):** Memanfaatkan `<thread>` murni untuk menghitung jumlah penonton di setiap studio secara mandiri dan bersamaan guna mempercepat pemrosesan laporan harian.
5. **Analisis Kompleksitas (Big O):** Setiap fungsi dioptimalkan untuk mencapai performa terbaik dan didokumentasikan batas atas performanya.

---
## 🚀 Panduan Build dan Run

Aplikasi ini menggunakan **CMake** untuk manajemen kompilasi lintas platform. Pastikan sistem Anda telah terpasang *compiler* C++ (GCC/MinGW/Clang) dan CMake Tools.

### Kompilasi lewat Terminal / Command Prompt

1. **Kloning atau Unduh** repositori ini ke direktori lokal Anda.
2. **Buka terminal** dan navigasikan ke dalam folder utama proyek `CinemaBookingSystem/`.
3. **Buat direktori build** terpisah agar *source code* tetap bersih:
   ```bash
   mkdir build
   cd build

---

## 📂 Struktur Direktori Proyek

Proyek ini dibangun menggunakan pendekatan **Modular Programming**, memisahkan definisi (*Interface/Header*) dengan implementasi (*Source Code*):

```text
CinemaBookingSystem/
├── CMakeLists.txt              # Konfigurasi Build Automation menggunakan CMake
└── src/
    ├── main.cpp                # Alur utama program berbasis Menu CLI
    ├── Models.h                # Definisi Struct Data (Movie, Ticket)
    ├── QueueTicket.h           # Interface kelas Antrian (Queue)
    ├── QueueTicket.cpp         # Implementasi operasi Enqueue & Dequeue
    ├── StackCancel.h           # Interface kelas Riwayat Pembatalan (Stack)
    ├── StackCancel.cpp         # Implementasi operasi Push & Pop (Undo)
    ├── MovieSchedule.h         # Interface kelas Divide & Conquer (Sort & Search)
    ├── MovieSchedule.cpp       # Implementasi Merge Sort & Binary Search
    ├── ParallelReport.h        # Interface kelas Laporan Paralel
    └── ParallelReport.cpp      # Implementasi Threading Rekap Penonton



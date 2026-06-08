# Smart Cinema Ticket Booking System 🎬🎟️

A Native C++ Modular Application for Managing Cinema Ticket Queue, Cancellations, Scheduling, and Parallel Statistical Reporting.

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
4. Generate konfigurasi project menggunakan CMake:
   ```bash
   cmake ..
5. Kompilasi proyek menjadi file executable:
   ```bash
   cmake --build .
7. Jalankan aplikasi:
   ```bash
   .\Debug\CinemaBookingSystem.exe

---
## 💻 Alur Pengujian Fitur Program

Sebelum memulai pengujian, program ini telah memuat data jadwal film bawaan (acak) sebagai berikut untuk keperluan demonstrasi *sorting* dan *searching*:
* `[104]` Inception - 20:00 (Studio 2)
* `[101]` Interstellar - 13:00 (Studio 1)
* `[103]` Oppenheimer - 18:30 (Studio 3)
* `[102]` Dune: Part Two - 15:45 (Studio 4)

Gunakan skenario pengujian di bawah ini secara berurutan untuk memvalidasi performa struktur data dan algoritma sistem:

1. **Pengujian Queue (Antrean Masuk)**
   * **Pilih Menu 1** (Tambah Antrian Pemesanan) -> Masukkan Nama Pelanggan: `Kresna`, ID Film: `101`.
   * **Pilih Menu 1** (Tambah Antrian Pemesanan) -> Masukkan Nama Pelanggan: `Rakha`, ID Film: `104`.
   * **Pilih Menu 1** (Tambah Antrian Pemesanan) -> Masukkan Nama Pelanggan: `Mayo`, ID Film: `102`.
   * **Pilih Menu 5** (Lihat Antrian & Riwayat) -> Pastikan urutan antrean dari yang paling atas adalah Kresna, diikuti Rakha, dan Mayo. Ini memvalidasi prinsip **FIFO** (*First In, First Out*).

2. **Pengujian Stack (Pembatalan & Undo)**
   * **Pilih Menu 3** (Batalkan Antrian Depan) dua kali secara berturut-turut. Kresna dan Rakha akan terhapus dari antrean utama dan otomatis ditumpuk ke dalam memori Riwayat Pembatalan.
   * **Pilih Menu 5** (Lihat Antrian & Riwayat) -> Perhatikan bagian "Riwayat Pembatalan". Rakha harus berada di urutan paling atas karena ia yang paling terakhir dibatalkan (Prinsip **LIFO** - *Last In, First Out*). Antrean utama kini hanya tersisa Mayo.
   * **Pilih Menu 4** (Undo Pembatalan Terakhir) -> Rakha ditarik dari riwayat dan dikembalikan ke antrean utama. 

3. **Pengujian Divide & Conquer (Sorting & Searching)**
   * **Pilih Menu 6** (Cari Jadwal Film) -> Sistem akan otomatis mengeksekusi algoritma *Merge Sort* dan menampilkan jadwal film yang sudah terurut rapi dari ID 101 hingga 104.
   * Saat program meminta input ID yang dicari, masukkan angka `103`.
   * Sistem akan memotong ruang pencarian menggunakan *Binary Search* dan secara instan menampilkan: `Ditemukan: Oppenheimer di Studio 3`.

4. **Pengujian Multithreading (Laporan Paralel)**
   * **Pilih Menu 2** (Proses Pembelian) beberapa kali sampai seluruh antrean (Mayo dan Rakha) berhasil diproses dan dikosongkan dari daftar tunggu.
   * **Pilih Menu 7** (Laporan Paralel) -> Sistem akan memecah beban komputasi ke beberapa *thread* secara bersamaan (sejumlah studio) untuk mencari tiket yang cocok. Hasil akhirnya akan mencetak: Studio 4 mendapat 1 penonton (Mayo), Studio 2 mendapat 1 penonton (Rakha), dan studio lainnya 0.

5. **Pengujian Selesai**
   * **Pilih Menu 0** (Keluar) untuk menghentikan alur program dengan aman dan membersihkan alokasi memori.
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



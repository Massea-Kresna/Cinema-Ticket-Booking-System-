readme_content = """# Smart Cinema Ticket Booking System 🎬🎟️

A Native C++ Modular Application for Managing Cinema Ticket Queue, Cancellations, Scheduling, and Parallel Statistical Reporting.

Developed as a Final Project for the **Algorithm and Programming (Algoritma dan Pemrograman)** Course.

---

## 📌 Anggota Kelompok
* **Massea Kresna Aravena Putra Febrianto** - (NIM: 21120124120027) - *Teknik Komputer, Universitas Diponegoro*
* [Nama Anggota 2] - (NIM: [NIM Anggota 2])
* [Nama Anggota 3] - (NIM: [NIM Anggota 3])

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

## 📂 Struktur Direktori Proyek

Proyek ini dibangun menggunakan pendekatan **Modular Programming**, memisahkan definisi (*Interface/Header*) dengan implementasi (*Source Code*):

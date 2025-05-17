#include <iostream>
#include <string>
using namespace std;

class Peminjam;
class Admin;

class Buku {
private:
    string judul;
    string penulis;
    bool dipinjam;

public:
    Buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}
    friend class Petugas; 

    friend void lihatStatus(Buku* b, Admin* a);
};

class Peminjam {
private:
    string nama;
    int id;
    int totalPinjaman;

public:
    Peminjam(string n, int i) : nama(n), id(i), totalPinjaman(0) {}

    friend class Petugas;

    friend void lihatDataPeminjam(Peminjam* p, Admin* a);
};

class Petugas {
private:
    string nama;
    int idPetugas;
    string levelAkses;

public:
    Petugas(string n, int id, string akses) : nama(n), idPetugas(id), levelAkses(akses) {}

    void prosesPinjam(Buku* b, Peminjam* p) {
        if (!b->dipinjam) {
            b->dipinjam = true;
            p->totalPinjaman++;
            cout << "Buku berhasil dipinjam oleh: " << p->nama << endl;
        } else {
            cout << "Buku sudah dipinjam." << endl;
        }
    }
};
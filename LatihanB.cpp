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

    void prosesKembali(Buku* b, Peminjam* p) {
        if (b->dipinjam) {
            b->dipinjam = false;
            p->totalPinjaman--;
            cout << "Buku berhasil dikembalikan oleh: " << p->nama << endl;
        } else {
            cout << "Buku belum dipinjam." << endl;
        }
    }

    friend class Admin;
};

class Admin {
public:
    void ubahLevelAkses(Petugas* pet, string levelBaru) {
        pet->levelAkses = levelBaru;
        cout << "Level akses petugas diubah ke: " << levelBaru << endl;
    }

    void lihatStatistik(Buku* b, Peminjam* p) {
        lihatStatus(b, this);
        lihatDataPeminjam (p, this);
    }
};

void lihatStatus(Buku* b , Admin* a) {
    if (b->dipinjam) {
        cout << "Status buku: Dipinjam" << endl;
    } else {
        cout << "Status buku: Tersedia" << endl;
    }
}

void lihatDataPeminjam(Peminjam* p, Admin* a) {
    cout << "Data Peminjam: " << p->nama << endl;
    cout << "Total Pinjaman: " << p->totalPinjaman << endl;
    cout << endl;
}

int main() {
    Buku* buku1 = new Buku("Pemrograman Dasar", "Fahrezi");
    Buku* buku2 = new Buku("Algoritma","Hardanni");
    Peminjam* user1 = new Peminjam("Ghatan", 182);
    Peminjam* user2 = new Peminjam("Jehan", 188);
    Petugas* petugas1 = new Petugas("Tsaqif", 169, "biasa");
    Admin* admin1 = new Admin();

    petugas1->prosesPinjam(buku1, user1);
    admin1->lihatStatistik(buku1, user1);
    petugas1->prosesPinjam(buku2, user2);
    admin1->lihatStatistik(buku2, user2);

    petugas1->prosesKembali(buku1, user1);
    petugas1->prosesKembali(buku2, user2);

    admin1->ubahLevelAkses(petugas1, "Luar biasa");

    return 0;
}
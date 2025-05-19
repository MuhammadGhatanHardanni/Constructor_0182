#include <iostream>
using namespace std;

class mahasiswa{
    private:
        static int jmlmhs;
    public:
        string status;
        string nama;
        int nim;
        mahasiswa(string pnama, int pnim){
            status ="Mahasiswa Baru";
            nama = pnama;
            nim = pnim;
            cout << "Mahasiswa Dibuat" << nama << endl;
            cout << "Status = " << status << endl;
            ++jmlmhs;
        };
        ~mahasiswa(){
            cout << "Mahasiswa dengan nama" << nama << "dihancurkan" << endl;
            --jmlmhs;
        };
        static int gettotalmhs(){
            cout << "Jumlah Mahasiswa = " << jmlmhs << endl;

            return jmlmhs;
        };
};

int mahasiswa :: jmlmhs = 0;

int main(){ 
    cout << "Jumlah Mahasiswa = " << mahasiswa::gettotalmhs() << endl;
    mahasiswa mhs1("Rudi", 28);
    mahasiswa mhs2("Joko", 73);
    mhs2.status = "Mahasiswa uzur";
    cout << mhs2.status << endl;
    mahasiswa mhs3("Wobo", 69);
    cout << "Jumlah Mahasiswa = " << mahasiswa::gettotalmhs() << endl;
    {
        mahasiswa mhs4("dewo", 98);
        cout << "Jumlah Mahasiswa dalam bracket = " << mahasiswa::gettotalmhs() << endl;
    }
    cout << "Jumlah Mahasiswa = " << mahasiswa::gettotalmhs() << endl;
    return 0;
}
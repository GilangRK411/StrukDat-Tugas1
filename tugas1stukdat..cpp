#include <iostream>
#include <string>

using namespace std;

const int MAX_MAHASISWA = 10;

struct Mahasiswa {
    string nama;
    string nrp;
    int usia;
    string jeniskelamin;
    string hobi;
    string semester;
    string angkatan;
    string jurusan;
    string alamat;
    string tempatlahir;
};

void tampilkandatamahasiswa(const Mahasiswa mahasiswa[], int jumlahdata) {
    cout << "Data Mahasiswa:" << endl;
    for (int i = 0; i < jumlahdata; ++i) {
        cout << "Mahasiswa ke-" << (i + 1) << endl;
        cout << "NRP: " << mahasiswa[i].nrp << endl;
        cout << "Nama: " << mahasiswa[i].nama << endl;
        cout << "Usia: " << mahasiswa[i].usia << endl;
        cout << "Jenis Kelamin: " << mahasiswa[i].jeniskelamin << endl;
        cout << "Hobi: " << mahasiswa[i].hobi << endl;
        cout << "Semester: " << mahasiswa[i].semester << endl;
        cout << "Angkatan: " << mahasiswa[i].angkatan << endl;
        cout << "Jurusan: " << mahasiswa[i].jurusan << endl;
        cout << "Alamat: " << mahasiswa[i].alamat << endl;
        cout << "Tempat Lahir: " << mahasiswa[i].tempatlahir << endl;
        cout << endl;
    }
}

void tambahdatamahasiswa(Mahasiswa mahasiswa[], int &jumlahdata, int maksimaldata) {
    if (jumlahdata < maksimaldata) {
        cout << "Masukkan NRP Mahasiswa: ";
        cin >> mahasiswa[jumlahdata].nrp;
        cout << "Masukkan Nama Mahasiswa: ";
        cin.ignore();
        getline(cin, mahasiswa[jumlahdata].nama);
        cout << "Masukkan Usia Mahasiswa: ";
        cin >> mahasiswa[jumlahdata].usia;
        cout << "Masukkan Jenis Kelamin Mahasiswa (L/P): ";
        cin >> mahasiswa[jumlahdata].jeniskelamin;
        cout << "Masukkan Hobi Mahasiswa: ";
        cin.ignore();
        getline(cin, mahasiswa[jumlahdata].hobi);
        cout << "Masukkan Semester Mahasiswa: ";
        cin.ignore();
        getline(cin, mahasiswa[jumlahdata].semester);
        cout << "Masukkan Angkatan Mahasiswa: ";
        cin.ignore();
        getline(cin, mahasiswa[jumlahdata].angkatan);
        cout << "Masukkan Jurusan Mahasiswa: ";
        cin.ignore();
        getline(cin, mahasiswa[jumlahdata].jurusan);
        cout << "Masukkan Alamat Mahasiswa: ";
        cin.ignore();
        getline(cin, mahasiswa[jumlahdata].alamat);
        cout << "Masukkan Tempat Lahir Mahasiswa: ";
        cin.ignore();
        getline(cin, mahasiswa[jumlahdata].tempatlahir);
        jumlahdata++;
        cout << "Data mahasiswa berhasil ditambahkan." << endl;
    } else {
        cout << "Batas maksimum data mahasiswa telah tercapai." << endl;
    }
}

void hapusdatamahasiswa(Mahasiswa mahasiswa[], int &jumlahdata) {
    if (jumlahdata == 0) {
        cout << "Tidak ada data mahasiswa yang tersimpan." << endl;
    } else {
        cout << "Masukkan NRP Mahasiswa yang ingin dihapus:";
        string nrphapus;
        cin >> nrphapus;

        bool ditemukan = false;
        for (int i = 0; i < jumlahdata; ++i) {
            if (mahasiswa[i].nrp == nrphapus) {
                for (int j = i; j < jumlahdata - 1; ++j) {
                    mahasiswa[j] = mahasiswa[j + 1];
                }
                jumlahdata--;
                ditemukan = true;
                cout << "Data mahasiswa berhasil dihapus." << endl;
                break;
            }
        }

        if (!ditemukan) {
            cout << "NRP Mahasiswa tidak ditemukan." << endl;
        }
    }
}

void ubahdatamahasiswa(Mahasiswa mahasiswa[], int jumlahdata) {
    if (jumlahdata == 0) {
        cout << "Tidak ada data mahasiswa yang tersimpan." << endl;
    } else {
        cout << "Masukkan NRP Mahasiswa yang ingin diubah:";
        string nrpubah;
        cin >> nrpubah;

        bool ditemukan = false;
        for (int i = 0; i < jumlahdata; ++i) {
            if (mahasiswa[i].nrp == nrpubah) {
                cout << "Masukkan Nama Mahasiswa yang baru: ";
                cin.ignore();
                getline(cin, mahasiswa[i].nama);
                cout << "Masukkan Usia Mahasiswa yang baru: ";
                cin >> mahasiswa[i].usia;
                cout << "Masukkan Jenis Kelamin Mahasiswa yang baru (L/P): ";
                cin >> mahasiswa[i].jeniskelamin;
                cout << "Masukkan Hobi Mahasiswa yang baru: ";
                cin.ignore();
                getline(cin, mahasiswa[i].hobi);
                cout << "Masukkan Semester Mahasiswa yang baru: ";
                cin.ignore();
                getline(cin, mahasiswa[i].semester);
                cout << "Masukkan Angkatan Mahasiswa yang baru: ";
                cin.ignore();
                getline(cin, mahasiswa[i].angkatan);
                cout << "Masukkan Jurusan Mahasiswa yang baru: ";
                cin.ignore();
                getline(cin, mahasiswa[i].jurusan);
                cout << "Masukkan Alamat Mahasiswa yang baru: ";
                cin.ignore();
                getline(cin, mahasiswa[i].alamat);
                cout << "Masukkan Tempat Lahir Mahasiswa yang baru: ";
                cin.ignore();
                getline(cin, mahasiswa[i].tempatlahir);
                ditemukan = true;
                cout << "Data mahasiswa berhasil diubah." << endl;
                break;
            }
        }

        if (!ditemukan) {
            cout << "NRP Mahasiswa tidak ditemukan." << endl;
        }
    }
}

int tampilkanmenu() {
    cout << "Pilih operasi yang ingin dilakukan:" << endl;
    cout << "1. Tampilkan Data" << endl;
    cout << "2. Tambah Data Mahasiswa" << endl;
    cout << "3. Hapus Data Mahasiswa" << endl;
    cout << "4. Ubah Data Mahasiswa" << endl;
    cout << "5. Keluar" << endl;

    int pilihan;
    cin >> pilihan;
    return pilihan;
}

int main() {
    Mahasiswa mahasiswa[MAX_MAHASISWA];
    int jumlahdata = 0;

    while (true) {
        int pilihan = tampilkanmenu();

        switch (pilihan) {
            case 1:
                tampilkandatamahasiswa(mahasiswa, jumlahdata);
                break;
            case 2:
                tambahdatamahasiswa(mahasiswa, jumlahdata, MAX_MAHASISWA);
                break;
            case 3:
                hapusdatamahasiswa(mahasiswa, jumlahdata);
                break;
            case 4:
                ubahdatamahasiswa(mahasiswa, jumlahdata);
                break;
            case 5:
                cout << "Program selesai." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}

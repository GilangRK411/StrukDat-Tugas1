#include <iostream>
#include <string>

using namespace std;

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa {
    string nama;
    string nrp;
    int usia;
    string jenisKelamin;
};

// Fungsi untuk menampilkan data mahasiswa
void tampilkanData(const Mahasiswa mahasiswas[], int jumlahData) {
    cout << "Data Mahasiswa:" << endl;
    for (int i = 0; i < jumlahData; ++i) {
        cout << "Mahasiswa ke-" << (i + 1) << endl;
        cout << "NRP: " << mahasiswas[i].nrp << endl;
        cout << "Nama: " << mahasiswas[i].nama << endl;
        cout << "Usia: " << mahasiswas[i].usia << endl;
        cout << "Jenis Kelamin: " << mahasiswas[i].jenisKelamin << endl;
        cout << endl;
    }
}

// Fungsi untuk menambahkan data mahasiswa baru
void tambahData(Mahasiswa mahasiswas[], int &jumlahData, int maksimalMahasiswa) {
    if (jumlahData < maksimalMahasiswa) {
        cout << "Masukkan NRP Mahasiswa: ";
        cin >> mahasiswas[jumlahData].nrp;
        cout << "Masukkan Nama Mahasiswa: ";
        cin.ignore();
        getline(cin, mahasiswas[jumlahData].nama);
        cout << "Masukkan Usia Mahasiswa: ";
        cin >> mahasiswas[jumlahData].usia;
        cout << "Masukkan Jenis Kelamin Mahasiswa (L/P): ";
        cin >> mahasiswas[jumlahData].jenisKelamin;
        jumlahData++;
        cout << "Data mahasiswa berhasil ditambahkan." << endl;
    } else {
        cout << "Batas maksimum data mahasiswa telah tercapai." << endl;
    }
}

// Fungsi untuk menghapus data mahasiswa
void hapusData(Mahasiswa mahasiswas[], int &jumlahData) {
    if (jumlahData == 0) {
        cout << "Tidak ada data mahasiswa yang tersimpan." << endl;
    } else {
        cout << "Masukkan NRP Mahasiswa yang ingin dihapus: ";
        string nrpHapus;
        cin >> nrpHapus;

        bool ditemukan = false;
        for (int i = 0; i < jumlahData; ++i) {
            if (mahasiswas[i].nrp == nrpHapus) {
                for (int j = i; j < jumlahData - 1; ++j) {
                    mahasiswas[j] = mahasiswas[j + 1];
                }
                jumlahData--;
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

// Fungsi untuk mengubah data mahasiswa
void ubahData(Mahasiswa mahasiswas[], int jumlahData) {
    if (jumlahData == 0) {
        cout << "Tidak ada data mahasiswa yang tersimpan." << endl;
    } else {
        cout << "Masukkan NRP Mahasiswa yang ingin diubah: ";
        string nrpUbah;
        cin >> nrpUbah;

        bool ditemukan = false;
        for (int i = 0; i < jumlahData; ++i) {
            if (mahasiswas[i].nrp == nrpUbah) {
                cout << "Masukkan Nama Mahasiswa yang baru: ";
                cin.ignore();
                getline(cin, mahasiswas[i].nama);
                cout << "Masukkan Usia Mahasiswa yang baru: ";
                cin >> mahasiswas[i].usia;
                cout << "Masukkan Jenis Kelamin Mahasiswa yang baru (L/P): ";
                cin >> mahasiswas[i].jenisKelamin;
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

int main() {
    const int maksimalMahasiswa = 10;
    Mahasiswa mahasiswas[maksimalMahasiswa];
    int jumlahData = 0;

    while (true) {
        cout << "Pilih operasi yang ingin dilakukan:" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data Mahasiswa" << endl;
        cout << "3. Hapus Data Mahasiswa" << endl;
        cout << "4. Ubah Data Mahasiswa" << endl;
        cout << "5. Keluar" << endl;

        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData(mahasiswas, jumlahData);
                break;

            case 2:
                tambahData(mahasiswas, jumlahData, maksimalMahasiswa);
                break;

            case 3:
                hapusData(mahasiswas, jumlahData);
                break;

            case 4:
                ubahData(mahasiswas, jumlahData);
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

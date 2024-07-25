#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Buku {
public:
    int id;
    string judul;
    string penulis;
    int tahun;

    Buku(int id, string judul, string penulis, int tahun)
        : id(id), judul(judul), penulis(penulis), tahun(tahun) {}
};

class Perpustakaan {
private:
    vector<Buku> bukuBuku;
    int idBerikutnya = 1;

public:
    void tambahBuku(string judul, string penulis, int tahun) {
        bukuBuku.push_back(Buku(idBerikutnya++, judul, penulis, tahun));
        cout << "Buku berhasil ditambahkan!" << endl;
    }

    void daftarBuku() {
        if (bukuBuku.empty()) {
            cout << "Tidak ada buku tersedia." << endl;
            return;
        }
        for (const auto& buku : bukuBuku) {
            cout << "ID: " << buku.id << ", Judul: " << buku.judul
                 << ", Penulis: " << buku.penulis << ", Tahun: " << buku.tahun << endl;
        }
    }

    void perbaruiBuku(int id, string judul, string penulis, int tahun) {
        for (auto& buku : bukuBuku) {
            if (buku.id == id) {
                buku.judul = judul;
                buku.penulis = penulis;
                buku.tahun = tahun;
                cout << "Buku berhasil diperbarui!" << endl;
                return;
            }
        }
        cout << "Buku tidak ditemukan!" << endl;
    }

    void hapusBuku(int id) {
        for (auto it = bukuBuku.begin(); it != bukuBuku.end(); ++it) {
            if (it->id == id) {
                bukuBuku.erase(it);
                cout << "Buku berhasil dihapus!" << endl;
                return;
            }
        }
        cout << "Buku tidak ditemukan!" << endl;
    }
};

void menuAdmin(Perpustakaan& perpustakaan) {
    while (true) {
        cout << "\nMenu Admin:\n1. Tambah Buku\n2. Daftar Buku\n3. Perbarui Buku\n4. Hapus Buku\n5. Logout\nPilih opsi: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            string judul, penulis;
            int tahun;
            cout << "Masukkan judul: ";
            cin.ignore();
            getline(cin, judul);
            cout << "Masukkan penulis: ";
            getline(cin, penulis);
            cout << "Masukkan tahun: ";
            cin >> tahun;
            perpustakaan.tambahBuku(judul, penulis, tahun);
        } else if (pilihan == 2) {
            perpustakaan.daftarBuku();
        } else if (pilihan == 3) {
            int id;
            string judul, penulis;
            int tahun;
            cout << "Masukkan ID buku yang akan diperbarui: ";
            cin >> id;
            cout << "Masukkan judul baru: ";
            cin.ignore();
            getline(cin, judul);
            cout << "Masukkan penulis baru: ";
            getline(cin, penulis);
            cout << "Masukkan tahun baru: ";
            cin >> tahun;
            perpustakaan.perbaruiBuku(id, judul, penulis, tahun);
        } else if (pilihan == 4) {
            int id;
            cout << "Masukkan ID buku yang akan dihapus: ";
            cin >> id;
            perpustakaan.hapusBuku(id);
        } else if (pilihan == 5) {
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
}

void menuUser(Perpustakaan& perpustakaan) {
    while (true) {
        cout << "\nMenu User:\n1. Daftar Buku\n2. Logout\nPilih opsi: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            perpustakaan.daftarBuku();
        } else if (pilihan == 2) {
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
}

int main() {
    cout << "**********Selamat Datang di Perpustakaan************\n" << endl;
    Perpustakaan perpustakaan;
    while (true) {
        cout << "Sistem Perpustakaan\n1. Admin\n2. User\n3. Keluar\nPilih opsi: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            string password;
            cout << "Masukkan password admin: ";
            cin.ignore();
            getline(cin, password);
            if (password == "220220") {
                menuAdmin(perpustakaan);
            } else {
                cout << "Password salah." << endl;
            }
        } else if (pilihan == 2) {
            menuUser(perpustakaan);
        } else if (pilihan == 3) {
            cout << "Selamat tinggal!" << endl;
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
    return 0;
}
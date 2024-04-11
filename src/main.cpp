#include <iostream>
#include <string>
#include "Perpus.hpp"
#include "Pinjam.hpp"
using namespace std;

int MainMenu();

int main()
{
    system("cls");
    ArrPeminjam peminjam;
    ArrPerpustakaan perpustakaan;
    int menu = MainMenu();
    char iskembali;

    while (menu != 0)
    {
        switch (menu)
        {
        case 1:
            cout << "ADMIN" << endl;
            AdminPerpus(perpustakaan);
            break;
        case 2:
            cout << "PINJAM BUKU" << endl;
            PinjamBuku(peminjam, perpustakaan);
            break;

        default:
            break;
        }
        system("cls");
        menu = MainMenu();
    }

    return 0;
}

int MainMenu()
{
    int pilihan;
    cout << "Perpustakaan AKPRIND" << endl;
    cout << "1. Masuk Sebagai Admin" << endl;
    cout << "2. Masuk Sebagai Peminjam" << endl;
    cout << "0. keluar" << endl;
    cout << "Silahkan Pilih : ";
    cin >> pilihan;
    return pilihan;
}

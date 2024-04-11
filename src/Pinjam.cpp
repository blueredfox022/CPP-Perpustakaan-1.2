#include "Pinjam.hpp"

int MenuPinjam()
{
    int pilihan;

    std::cout << "Perpustakaan AKPRIND" << std::endl;
    std::cout << "1. Lihat Daftar Peminjam" << std::endl;
    std::cout << "2. Tambah Peminjam" << std::endl;
    std::cout << "0. keluar" << std::endl;
    std::cout << "Silahkan Pilih: ";
    std::cin >> pilihan;
    std::cin.ignore();
    return pilihan;
}

int getDataSizePeminjam(ArrPeminjam &peminjam)
{

    int size = 0;
    for (int i = 0; i < MAXSIZE; i++)
    {
        if (peminjam[i].namaPeminjam == "")
        {
            size = i;
            break;
        }
    }
    return size;
}

void TambahDatapeminjam(ArrPeminjam &peminjam, ArrPerpustakaan &perpustakaan)
{
    int size = getDataSizePeminjam(peminjam);
    int sizeBuku = getDataSizePerpus(perpustakaan);
    if (size >= MAXSIZE)
    {
        std::cout << "Data peminjam penuh, tunggu besok" << std::endl;
        return;
    }
    else if (sizeBuku == 0)
    {
        std::cout << "Tidak ada buku yang dapat dipinjam" << std::endl;
        return;
    }

    Peminjaman addpeminjam;
    std::cout << "Masukkan nama Anda : ";
    getline(std::cin, addpeminjam.namaPeminjam);
    LihatDaftarBuku(perpustakaan);
    int pilihBuku;
    std::cout << "Silahkan pilih buku yang ingin dipinjam ; ";
    std::cin >> pilihBuku;
    if (pilihBuku > sizeBuku || pilihBuku < 0)
    {
        std::cout << "Maaf Pilihan tidak ada" << std::endl;
        return;
    }
    pilihBuku -= 1;
    char isPinjam;

    Perpustakaan readBuku = ReadDataPerpus(perpustakaan, pilihBuku);
    std::cout << "data buku yang akan dipinjam" << std::endl;
    std::cout << "Judul Buku : " << readBuku.judulBuku << std::endl;
    std::cout << "Penerbit Buku : " << readBuku.penerbit << std::endl;
    std::cout << "Yakin ingin meminjam(y/n)? : ";
    std::cin >> isPinjam;
    if (isPinjam != 'y')
    {
        std::cout << "Peminjaman buku dibatalkan " << std::endl;
    }
    addpeminjam.bukuPeminjam = perpustakaan[pilihBuku];
    std::cout << "berhasil meminjam Buku!" << std::endl;

    peminjam[size] = addpeminjam; // menambhakan data ke dalam larik
}

Peminjaman ReadDatapeminjam(ArrPeminjam &peminjaman, int pos)
{
    Peminjaman readData;
    readData.namaPeminjam = peminjaman[pos].namaPeminjam;
    readData.bukuPeminjam = peminjaman[pos].bukuPeminjam;
    return readData;
}

void LihatDaftarPeminjam(ArrPeminjam &peminjaman)
{
    int size = getDataSizePeminjam(peminjaman);
    if (size == 0)
    {
        std::cout << "Maaf, data buku perpustakaan tidak ada" << std::endl;
        return;
    }
    std::cout << "\n|\tDaftar Buku perpustakaan" << std::endl;
    std::cout << "|-------------------------------------------" << std::endl;
    std::cout << "| NO | Nama Peminjam\t| Judul Buku\t| Penerbit Buku\t|" << std::endl;
    std::cout << "|-------------------------------------------" << std::endl;
    for (int i = 0; i < size; i++)
    {
        Peminjaman readData = ReadDatapeminjam(peminjaman, i);

        std::cout << "| " << i + 1 << ".  |"
                  << readData.namaPeminjam << "\t|"
                  << readData.bukuPeminjam.judulBuku << "\t"
                  << readData.bukuPeminjam.penerbit << std::endl;
    }
    std::cout << "|-------------------------------------------" << std::endl;
}

void PinjamBuku(ArrPeminjam &peminjaman, ArrPerpustakaan &perpustakaan)
{
    system("cls");

    int menu = MenuPinjam();
    char iskembali;

    while (menu != 0)
    {
        switch (menu)
        {
        case 1:
            std::cout << "Lihat Daftar Peminjam" << std::endl;
            LihatDaftarPeminjam(peminjaman);
            break;

        case 2:
            std::cout << "Tambah Data Peminjaman" << std::endl;
            TambahDatapeminjam(peminjaman, perpustakaan);
            break;
        default:
            std::cout << "Pilihan tidak valid" << std::endl;
            break;
        }

        std::cout << "ingin Kembali(Y/N)? : ";
        std::cin >> iskembali;
        if (iskembali != 'y')
        {
            break;
        }
        system("cls");
        menu = MenuPinjam();
    }
}

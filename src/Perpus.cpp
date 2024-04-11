#include "Perpus.hpp"

int MenuPerpus()
{
    int pilihan;

    std::cout << "Perpustakaan AKPRIND" << std::endl;
    std::cout << "1. Lihat Daftar Buku" << std::endl;
    std::cout << "2. Tambah Buku" << std::endl;
    std::cout << "3. Edit Data Buku" << std::endl;
    std::cout << "4. Hapus Data Buku" << std::endl;
    std::cout << "0. Keluar" << std::endl;
    std::cout << "Silahkan Pilih: ";
    std::cin >> pilihan;
    std::cin.ignore();
    return pilihan;
}
int getDataSizePerpus(ArrPerpustakaan &perpustakaan)
{
    int size = 0;
    for (int i = 0; i < MAXSIZE; i++)
    {
        if (perpustakaan[i].judulBuku == "")
        {
            size = i;
            break;
        }
    }

    return size;
}

void CreataDataBuku(ArrPerpustakaan &perpustakaan)
{
    int size = getDataSizePerpus(perpustakaan);
    Perpustakaan addBuku;
    if (size >= MAXSIZE)
    {
        std::cout << "Maaf data penuh" << std::endl;
        return;
    }

    std::cout << "Masukkan Judul Buku : ";
    getline(std::cin, addBuku.judulBuku);
    std::cout << "Masukkan nama Penerbit : ";
    getline(std::cin, addBuku.penerbit);

    perpustakaan[size] = addBuku; // menambahakan data perpustakaan ke dalam larik perpustakaan
    std::cout << "Berhasil menambahkan data buku ke perpustakaan" << std::endl;
}

void LihatDaftarBuku(ArrPerpustakaan &perpus)
{

    int size = getDataSizePerpus(perpus);
    if (size == 0)
    {
        std::cout << "Maaf, data buku perpustakaan tidak ada" << std::endl;
        return;
    }
    std::cout << "\n|\tDaftar Buku perpustakaan" << std::endl;
    std::cout << "|-------------------------------------------" << std::endl;
    std::cout << "| NO | Judul Buku\t| Penerbit Buku\t|" << std::endl;
    std::cout << "|-------------------------------------------" << std::endl;
    for (int i = 0; i < size; i++)
    {
        Perpustakaan readData = ReadDataPerpus(perpus, i);

        std::cout << "| " << i + 1 << ".  |"
                  << readData.judulBuku << "\t|"
                  << readData.penerbit << std::endl;
    }
    std::cout << "|-------------------------------------------" << std::endl;
}

Perpustakaan ReadDataPerpus(ArrPerpustakaan &perpustakaan, int pos)
{
    Perpustakaan readData;
    readData.judulBuku = perpustakaan[pos].judulBuku;
    readData.penerbit = perpustakaan[pos].penerbit;

    return readData;
}

void EditDataBuku(ArrPerpustakaan &perpustakaan)
{
    int size = getDataSizePerpus(perpustakaan);
    if (size == 0)
    {
        return;
    }
    int pilihan;
    std::cout << "pilih nomor buku yang ingin diedit : ";
    std::cin >> pilihan;
    std::cin.ignore();
    if (pilihan > size || pilihan < 0)
    {
        std::cout << "Maaf pilihan tidak ada" << std::endl;
        return;
    }
    pilihan -= 1;

    Perpustakaan readBuku, editBuku;
    readBuku = ReadDataPerpus(perpustakaan, pilihan);
    std::cout << "data buku yang mau diedit" << std::endl;
    std::cout << "Judul Buku : " << readBuku.judulBuku << std::endl;
    std::cout << "Penerbit Buku : " << readBuku.penerbit << std::endl;

    std::cout << "Edit Data Buku Perpus" << std::endl;
    std::cout << "Masukkan Judul Buku : ";
    getline(std::cin, editBuku.judulBuku);
    std::cout << "Masukkan Nama penerbit : ";
    getline(std::cin, editBuku.penerbit);

    char isGanti;
    std::cout << "Yaking ingin mengganti(y/n)?: ";
    std::cin >> isGanti;
    if (isGanti != 'y')
    {
        std::cout << "edit Buku perpustakaan dibatalkan !!" << std::endl;
    }
    else
    {
        perpustakaan[pilihan] = editBuku;
        std::cout << "pengeditan buku perpustakaan  berhasil!!" << std::endl;
    }
}

void DeleteDataPerpus(ArrPerpustakaan &perpustakaan, Perpustakaan &hapusData)
{
    int size = getDataSizePerpus(perpustakaan);
    bool isFound = false;
    Perpustakaan readData, blankData;

    for (int i = 0; i <= size; i++)
    {
        readData = ReadDataPerpus(perpustakaan, i);
        if (readData.judulBuku == hapusData.judulBuku)
        {
            isFound = true;
        }
        if (isFound)
        {
            perpustakaan[i] = perpustakaan[i + 1];
        }
    }
}

void HapusDataBuku(ArrPerpustakaan &perpustakaan)
{
    int size = getDataSizePerpus(perpustakaan);
    if (size == 0)
    {
        return;
    }
    int pilihan;
    std::cout << "pilih nomor buku yang ingin dihapus : ";
    std::cin >> pilihan;
    std::cin.ignore();
    if (pilihan > size || pilihan < 0)
    {
        std::cout << "Maaf pilihan tidak ada" << std::endl;
        return;
    }
    pilihan -= 1;

    Perpustakaan readBuku = ReadDataPerpus(perpustakaan, pilihan);
    std::cout << "data buku yang mau dihapus" << std::endl;
    std::cout << "Judul Buku : " << readBuku.judulBuku << std::endl;
    std::cout << "Penerbit Buku : " << readBuku.penerbit << std::endl;

    char isDelete;
    std::cout << "Yaking ingin menghapus(y/n)?: ";
    std::cin >> isDelete;
    if (isDelete != 'y')
    {
        std::cout << "Penghapusan data perpustakaan dibatalkan!" << std::endl;
        return;
    }
    DeleteDataPerpus(perpustakaan, readBuku);
    std::cout << "berhasil melakukan penghapusan Data perpustakaan" << std::endl;
}

void AdminPerpus(ArrPerpustakaan &perpustakaan)
{
    system("cls");

    int menu = MenuPerpus();
    char iskembali;

    while (menu != 0)
    {
        switch (menu)
        {
        case 1:
            std::cout << "Lihat Daftar Buku Perpustakaan" << std::endl;
            LihatDaftarBuku(perpustakaan);
            break;

        case 2:
            std::cout << "Tambah Data Buku perpustakaan" << std::endl;
            CreataDataBuku(perpustakaan);
            break;
        case 3:
            std::cout << "Edit Data Buku Perpustakaan" << std::endl;
            LihatDaftarBuku(perpustakaan);
            EditDataBuku(perpustakaan);
            break;
        case 4:
            std::cout << "Hapus Data Buku perpustakaan" << std::endl;
            LihatDaftarBuku(perpustakaan);
            HapusDataBuku(perpustakaan);
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
        menu = MenuPerpus();
        /* code */
    }
}
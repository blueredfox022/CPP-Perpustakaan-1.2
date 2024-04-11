#ifndef PINJAM_HPP
#define PINJAM_HPP
#include "Perpus.hpp"

struct Peminjaman
{
    std::string namaPeminjam;
    Perpustakaan bukuPeminjam;
};
typedef Peminjaman ArrPeminjam[MAXSIZE];
int MenuPinjam();
int getDataSizePeminjam(ArrPeminjam &peminjam);
void TambahDatapeminjam(ArrPeminjam &peminjam, ArrPerpustakaan &perpustakaan);
Peminjaman ReadDatapeminjam(ArrPeminjam &peminjaman, int pos);
void LihatDaftarPeminjam(ArrPeminjam &peminjaman);
void PinjamBuku(ArrPeminjam &peminjaman, ArrPerpustakaan &perpustakaan);

#endif
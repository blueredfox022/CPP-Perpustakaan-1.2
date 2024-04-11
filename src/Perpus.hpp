#ifndef PERPUS_HPP
#define PERPUS_HPP
#include <iostream>
#include <string>

struct Perpustakaan
{
    std::string judulBuku;
    std::string penerbit;
};
const int MAXSIZE = 10;
typedef Perpustakaan ArrPerpustakaan[MAXSIZE];

int MenuPerpus();
int getDataSizePerpus(ArrPerpustakaan &perpustakaan);
void CreataDataBuku(ArrPerpustakaan &perpustakaan);
void LihatDaftarBuku(ArrPerpustakaan &perpustakaan);
Perpustakaan ReadDataPerpus(ArrPerpustakaan &perpustakaan, int pos);
void EditDataBuku(ArrPerpustakaan &perpustakaan);
void DeleteDataPerpus(ArrPerpustakaan &perpustakaan, Perpustakaan &hapusData);
void HapusDataBuku(ArrPerpustakaan &perpustakaan);
void AdminPerpus(ArrPerpustakaan &perpustakaan);

#endif
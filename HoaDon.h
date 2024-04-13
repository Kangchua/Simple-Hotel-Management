#ifndef HOADON_H
#define HOADON_H

#include "NgayThang.h"
#include <iostream>
#include <string>
using namespace std;
class HoaDon
{
    protected:
        string MaHD;
        string MaPH;
        string MaKH; 
        NgayThang NgThue;
        NgayThang NgTra;

    public:
    HoaDon();
    HoaDon(string, string, string, NgayThang, NgayThang);
    HoaDon(const HoaDon&);
    ~HoaDon();
    friend istream& operator>>(istream&, HoaDon&);
    friend const ostream& operator<<(ostream&, const HoaDon&);
    string getMaHD() const;
    string getMaPH() const;
    string getMaKH() const;
    NgayThang getNgThue() const;
    NgayThang getNgTra() const;
};
#endif // HOADON_H
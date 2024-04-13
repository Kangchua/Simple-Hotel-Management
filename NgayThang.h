#ifndef NGAYTHANG_H
#define NGAYTHANG_H

#include <iostream>
using namespace std;

class NgayThang {
    public:
    int Ngay;
    int Thang;
    int Nam;
    public:

//bool KiemTra(NgayThang&);
bool KiemTra(NgayThang&);
int TinhSoNgay(const NgayThang&,const NgayThang&);
bool SoSanh(const NgayThang&, const NgayThang&);
};


#endif // NGAYTHANG_H
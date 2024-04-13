#include <iostream>
#include <string>
#include <stdbool.h>
#ifndef KHACHHANG_H
#define KHACHHANG_H

#include "NgayThang.h"
using namespace std;
class KhachHang
{
    protected:
        string MaKH; 
        string TenKH;
        NgayThang NgSinh;
        string CCCD;
        string SDT;
        bool Gender;
    public: 
        KhachHang();
        KhachHang(const KhachHang&);
        ~KhachHang();
        KhachHang(string, string, NgayThang, string, string, bool);
        friend ostream &operator<<(ostream&, const KhachHang&);
        friend istream &operator>>(istream&, KhachHang&);
        bool operator==(const KhachHang&) const;
        string getMaKH() const;
        string getTenKH() const;
        NgayThang getNgSinh() const;
        string getCCCD() const;
        string getSDT() const;
        bool getGender() const;
        
};
#endif // KHACHHANG_H
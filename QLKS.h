#include "Phong.h"
#include "KhachHang.h"
#include "HoaDon.h"
#include "Vector.h"
#include "NgayThang.h"
#include <fstream>
#include <string.h>
class QLKS
{
protected:
    Vector<Phong> danhSachPhong;
    Vector<KhachHang> danhSachKhachHang;
    Vector<HoaDon> danhSachHoaDon;
public:
    QLKS();
    ~QLKS();
    // Default constructor
    void InputFromFile(int);
    
    void LuuDuLieuVaoFile();

    void InHoaDon(const string&);

    void ThemPhong(const Phong&);

    void SuaPhong(const string&, const Phong&);

    void InDanhSachPhong();

    void XoaPhong(const string&);

    
    void ThemKhachHang(const KhachHang&);
  
    void InDanhSachKhachHang();

    void TimKiemKhachHang(const std::string&) const;

    void SuaKhachHang(const string&);

    void XoaKhachHang(const string&);

    void ThuePhong(const HoaDon&);

    void TimPhongTrong();

    int TinhGiaTien(const string&);

    void InDanhSachHoaDon();

};


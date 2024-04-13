#include "HoaDon.h"
#include <iomanip>
using namespace std;
HoaDon::HoaDon()
    :   MaHD(""), MaPH(""), MaKH(""), NgThue({0, 0, 0}), NgTra({0, 0, 0})
{

}
HoaDon::HoaDon(string maHD, string maPH, string maKH, NgayThang ngThue, NgayThang ngTra)
    :   MaHD(maHD), MaPH(maPH), MaKH(maKH), NgThue(ngThue), NgTra(ngTra)
{

} 

HoaDon::HoaDon(const HoaDon& other)
    : MaHD(other.MaHD), MaPH(other.MaPH), MaKH(other.MaKH),
      NgThue(other.NgThue), NgTra(other.NgTra)
      
{

}

HoaDon::~HoaDon()
{
    
}
istream& operator>>(istream& is, HoaDon& hd)
{
        cout << left << setw(46) << " " <<"Nhap MaHD: ";
        is >> hd.MaHD;
        cout << left << setw(46) << " " <<"Nhap MaPH: ";
        is >> hd.MaPH;
        cout << left << setw(46) << " " <<"Nhap MaKH: ";
        is >> hd.MaKH;
        bool kt = true;
        do
        {
            bool kt1 = true;
            do
            {
                cout << left << setw(46) << " " <<"Nhap Ngay Thue Phong (Ngay Thang Nam): ";
                is >> hd.NgThue.Ngay >> hd.NgThue.Thang >> hd.NgThue.Nam;
                NgayThang tempNgThue;
                kt1 = tempNgThue.KiemTra(hd.NgThue);
            } while (kt1 == false);
            bool kt2 = true;
            do
            {
                cout << left << setw(46) << " " <<"Nhap Ngay Tra Phong (Ngay Thang Nam): ";
                is >> hd.NgTra.Ngay >> hd.NgTra.Thang >> hd.NgTra.Nam;
                NgayThang tempNgTra;
                kt2 = tempNgTra.KiemTra(hd.NgTra);
            } while (kt2 == false);
            NgayThang TempSS;
            kt = TempSS.SoSanh(hd.NgThue, hd.NgTra);
        } while (kt == false);
        return is;
}

const ostream& operator<<(ostream& os, const HoaDon& hd)
{       cout << left << setw(44) << " " << "___________________________\n";
        cout << left << setw(43) << " " << "|" << left << setw(27) << " " << "|\n";
        os << left << setw(43) << " " <<"|   MaHD: " << left << setw(18) << hd.MaHD << "|\n";
        os << left << setw(43) << " " <<"|   MaPH: " << left << setw(18) << hd.MaPH << "|\n";
        os << left << setw(43) << " " <<"|   MaKH: " << left << setw(18) << hd.MaKH << "|\n";
        os << left << setw(43) << " " <<"|   Ngay Thue: " << left << setw(2)<< hd.NgThue.Ngay << "/" << setw(2) << hd.NgThue.Thang << "/" << left << setw(4) << hd.NgThue.Nam << left << setw(3) << " " << "|\n";
        os << left << setw(43) << " " <<"|   Ngay Tra: " << left << setw(2)<< hd.NgTra.Ngay << "/" << setw(2) << hd.NgTra.Thang << "/" << left << setw(4) << hd.NgTra.Nam << left << setw(4) << " " << "|\n";
        cout << left << setw(43) << " " << "|___________________________|\n";
        return os;
}
string HoaDon::getMaHD() const {
    return MaHD;
}

// Getter for MaPH
string HoaDon::getMaPH() const {
    return MaPH;
}

// Getter for MaKH
string HoaDon::getMaKH() const {
    return MaKH;
}

// Getter for NgThue
NgayThang HoaDon::getNgThue() const {
    return NgThue;
}

// Getter for NgTra
NgayThang HoaDon::getNgTra() const {
    return NgTra;
}
#include "KhachHang.h"
#include <iomanip>
KhachHang::KhachHang() : MaKH(""), TenKH(""), NgSinh({0, 0, 0}), CCCD(""), SDT(""), Gender(0)
{

}
KhachHang::KhachHang(string maKH, string tenKH, NgayThang ngSinh, string cccd, string sdt, bool gender)
        : MaKH(maKH), TenKH(tenKH), NgSinh(ngSinh), CCCD(cccd), SDT(sdt) , Gender(gender)
{

}
KhachHang::KhachHang(const KhachHang& other)
    : MaKH(other.MaKH), TenKH(other.TenKH), NgSinh(other.NgSinh),
      CCCD(other.CCCD), SDT(other.SDT), Gender(other.Gender)
{
    
}
KhachHang::~KhachHang()
{
    
}
ostream &operator<<(ostream &out, const KhachHang &kh)
    {   cout << left << setw(44) << " " << "___________________________\n";
        cout << left << setw(43) << " " << "|" << left << setw(27) << " " << "|\n";
        cout << left << setw(43) << " " << "|   MaKH: " << left << setw(18) << kh.MaKH << "|\n";
        cout << left << setw(43) << " " << "|   TenKH: " << left << setw(17) << kh.TenKH << "|\n";
        cout << left << setw(43) << " " << "|   Ngay Sinh: "<< left << setw(2)<< kh.NgSinh.Ngay << "/" << setw(2) << kh.NgSinh.Thang << "/" << left << setw(4) << kh.NgSinh.Nam << left << setw(3) << " " << "|\n";
        cout << left << setw(43) << " " << "|   CCCD: " << left << setw(18) << kh.CCCD << "|\n";
        cout << left << setw(43) << " " << "|   SDT: " << left << setw(19) << kh.SDT << "|\n";
        cout << left << setw(43) << " " << "|   Gioi Tinh: ";
        if (kh.Gender == 0) cout << left << setw(10) << "Nam" << left << setw(3) << " " << "|\n";
        else cout << left << setw(10) << "Nu" << left << setw(3) << " " << "|\n";
        cout << left << setw(43) << " " << "|___________________________|\n";
        return out;
    }
istream &operator>>(istream &in, KhachHang &kh)
    {
        cout << left << setw(43) << " " <<"Nhap MaKH: ";
        cin >> kh.MaKH;
        cout << left << setw(43) << " " <<"Nhap TenKH: ";
        cin.ignore(); // Đọc ký tự '\n' thừa từ bước trước
        getline(in, kh.TenKH);
        bool kt = true; 
        NgayThang tempNgSinh;
        do
        {
        cout << left << setw(43) << " " <<"Nhap Ngay Sinh (Ngay Thang Nam): ";
        cin >> kh.NgSinh.Ngay >> kh.NgSinh.Thang >> kh.NgSinh.Nam;
        kt = tempNgSinh.KiemTra(kh.NgSinh);
        } while ( kt == false );
        cout << left << setw(43) << " " <<"Nhap CCCD: ";
        cin >> kh.CCCD;
        cout << left << setw(43) << " " <<"Nhap SDT: ";
        cin >> kh.SDT;
        int tempGT = -1;
        do 
        {
        cout << left << setw(43) << " " <<"Nhap Gioi Tinh(Nam = 0, Nu = 1): ";
        cin >> tempGT;
        if (tempGT == 0 || tempGT == 1){
        kh.Gender = tempGT;
        }
        else cout << left << setw(43) << " " <<"GT khong hop le\n";
        } while (tempGT != 0 && tempGT != 1);
        return in;
    }
    bool KhachHang::operator==(const KhachHang& other) const {
        return (MaKH == other.MaKH) && (CCCD == other.CCCD); 
    }
string KhachHang::getMaKH() const {
    return MaKH;
}

string KhachHang::getTenKH() const {
    return TenKH;
}

NgayThang KhachHang::getNgSinh() const {
    return NgSinh;
}

string KhachHang::getCCCD() const {
    return CCCD;
}

string KhachHang::getSDT() const {
    return SDT;
}

bool KhachHang::getGender() const {
    return Gender;
}
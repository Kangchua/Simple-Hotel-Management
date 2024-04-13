#include "Phong.h"
#include <iomanip>
Phong::Phong()
    : MaPh("NULL"), LoaiPh("NULL"), GiaPh(0), SLMax(0), TT(1)
{

}
Phong::Phong(string MPh, string LPh, int GP, int SL, bool TT)
    : MaPh(MPh), LoaiPh(LPh), GiaPh(GP), SLMax(SL), TT(TT)
{

}
Phong::Phong(const Phong &other) 
    : MaPh(other.MaPh), LoaiPh(other.LoaiPh), GiaPh(other.GiaPh), SLMax(other.SLMax), TT(other.TT)
{
    
}
Phong::~Phong()
{
    
}
ostream &operator<<(ostream &out, const Phong &phong)
    {   out << "_____________________\n";
        out << setw(45) << " " << "|   MaPh: " << phong.MaPh << left << setw(10) << " " <<"|\n";
        out << setw(45) << " " << "|   LoaiPh: " << left << setw(10) << phong.LoaiPh <<"|\n";
        out << setw(45) << " " << "|   GiaPh: " << left << setw(11) << phong.GiaPh << "|\n";
        out << setw(45) << " " << "|   SLMax: " << left << setw(10) << phong.SLMax << " " <<"|\n";
        out << setw(45) << " " << "|   TT: " << left << setw(13) << (phong.TT ? "true" : "false") <<" " <<"|\n";
        out << setw(45) << " " << "|_____________________|";
        return out;
    }
istream &operator>>(istream &in, Phong &phong)
    {   
        cout << setw(46) << " " << "_______________________\n";
        cout << setw(46) << " " << "Nhap MaPh: ";
        in >> phong.MaPh;
        cout << setw(46) << " " << "Nhap LoaiPh: (Standard, Deluxe, Superior, Suite, Premier): ";
        in.ignore(); // Đọc ký tự '\n' thừa từ bước trước
        getline(in, phong.LoaiPh);
        phong.GiaPh = -1;
        do 
        {
        cout << setw(46) << " " << "Nhap GiaPh: ";
        in >> phong.GiaPh;
        if (phong.GiaPh <= 0){
            cout << setw(46) << " " << "GiaPh khong hop le\n";
        }
        } while (phong.GiaPh <= 0);
        phong.SLMax = -1;
        do
        {
        cout << setw(46) << " " << "Nhap SLMax: ";
        in >> phong.SLMax;
        if (phong.SLMax <= 0){
            cout << setw(46) << " " << "So luong nguoi toi da khong hop le\n";
        }
        } while (phong.SLMax <= 0);
        int tempPh = -1;
        do 
        {
        cout << setw(46) << " " << "Nhap TT (1: true, 0: false): ";
        cin >> tempPh;
        if (tempPh == 0 || tempPh == 1){
        phong.TT = tempPh;
        }
        else cout << left << setw(46) << " " <<"Tinh trang khong hop le\n";
        } while (tempPh != 0 && tempPh != 1);
        return in;
    }
bool Phong::operator==(const Phong& other) const {
    return (MaPh == other.MaPh);
}
std::string Phong::getMaPh() const {
        return MaPh;
    }

std::string Phong::getLoaiPh() const {
        return LoaiPh;
    }

    int Phong::getGiaPh() const {
        return GiaPh;
    }

    int Phong::getSLMax() const {
        return SLMax;
    }

    bool Phong::getTT() const {
        return TT;
    }
    void Phong::setTT() {
        TT = true; 
    }
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "QLKS.h"
#include "NgayThang.h"
using namespace std;

QLKS::QLKS()
{

}

QLKS::~QLKS()
{

}

void QLKS::ThemPhong(const Phong &phong)
{   
    string tempMPh = phong.getMaPh();
    for (int i = 0; i < danhSachPhong.getSize(); ++i)
    {
        if (tempMPh == danhSachPhong.at(i).getMaPh())
        {
            cout << left << setw(45) << " " << "Da ton tai phong co ma " << tempMPh;
            return;
        }
    }
    danhSachPhong.push_back(phong);
}

void QLKS::SuaPhong(const string& maPhong, const Phong& newPhong) 
{
    for (int i = 0; i < danhSachPhong.getSize(); ++i) {
        if (danhSachPhong.at(i).getMaPh() == maPhong) {
            // Found the room, update it
            danhSachPhong.at(i) = newPhong;
            return;
        }
    }
    // Room not found
    cout << left << setw(46) << " " << "Khong tim thay phong voi MaPh " << maPhong << endl;
}

void QLKS::XoaPhong(const string& maPhong) {
    Vector<Phong> newDanhSachPhong;
    bool kt = false;

    // Iterate through the existing danhSachPhong
    for (int i = 0; i < danhSachPhong.getSize(); ++i) {
        if (danhSachPhong.at(i).getMaPh() != maPhong) {
            newDanhSachPhong.push_back(danhSachPhong.at(i));
        } else {
            kt = true;
        }
    }

    if (!kt) {
        cout << setw(45) << " " << "_________________________\n";
        cout << left << setw(46) << " " << "Khong tim thay ma phong\n";
        return;
    }

    // Update the danhSachPhong after removal
    danhSachPhong = newDanhSachPhong;


    cout << left << setw(46) << " " << "Xoa phong thanh cong!" << endl;
}

void QLKS::ThemKhachHang(const KhachHang &khachHang) 
{
    string tempMKh = khachHang.getMaKH();
    string tempCCCD = khachHang.getCCCD();
    for (int i = 0; i < danhSachKhachHang.getSize(); ++i) {
        if (tempMKh == danhSachKhachHang.at(i).getMaKH()) {
            cout << left << setw(43) << " " <<"Da ton tai khach hang co ma " << tempMKh << "\n";
            return;
        } else if (tempCCCD == danhSachKhachHang.at(i).getCCCD()) {
            cout << left << setw(43) << " " <<"Da ton tai khach hang co CCCD " << tempCCCD << "\n";
            return;
        }
    }
    danhSachKhachHang.push_back(khachHang);
}

void QLKS::InDanhSachPhong()
{
    for (int i = 0; i < danhSachPhong.getSize(); ++i)
    {
        cout << left << setw(46) << " " << danhSachPhong.at(i) << "\n";
    }
}

void QLKS::InDanhSachKhachHang()
{
    for (int i = 0; i < danhSachKhachHang.getSize(); ++i)
    {
        cout << danhSachKhachHang.at(i) << "\n";
    }
}

void QLKS::TimKiemKhachHang(const string& CCCD) const {
    bool found = false;
    for (int i = 0; i < danhSachKhachHang.getSize(); ++i) {
        if (danhSachKhachHang.at(i).getCCCD() == CCCD) {
            cout << left << setw(46) << " " << "Thong tin khach hang:\n";
            cout << danhSachKhachHang.at(i) << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << left << setw(43) << " " << "Khong tim thay khach hang voi CCCD: " << CCCD << "\n";
    }
}

void QLKS::SuaKhachHang(const string& maKhachHang) {
    for (int i = 0; i < danhSachKhachHang.getSize(); ++i) {
        if (danhSachKhachHang.at(i).getMaKH() == maKhachHang) {
            // Modify the information of the customer
            cout << left << setw(43) << " " <<"Nhap thong tin khach hang moi:\n";
            cout << left << setw(40) << " " <<"_________________________\n";
            cin >> danhSachKhachHang.at(i);
            cout << left << setw(43) << " " <<"Cap nhat thong tin khach hang thanh cong!" << endl;
            return; // Exit the function once the update is done
        }
    }

    cout << left << setw(43) << " " <<"Khong tim thay khach hang co ma " << maKhachHang << endl;
}

void QLKS::XoaKhachHang(const string& maKhachHang) {
    if (maKhachHang.empty()) {
        cout << left << setw(43) << " " << "Ma khach hang khong hop le." << endl;
        return;
    }

    Vector<KhachHang> newDanhSachKhachHang;

    // Iterate through the existing danhSachKhachHang
    bool found = false;
    for (int i = 0; i < danhSachKhachHang.getSize(); ++i) {
        if (danhSachKhachHang.at(i).getMaKH() == maKhachHang) {
            // Set found to true if the customer is found
            found = true;
        } else {
            // Copy the customer to the new vector if it's not the one to be deleted
            newDanhSachKhachHang.push_back(danhSachKhachHang.at(i));
        }
    }

    if (!found) {
        cout << left << setw(43) << " " << "Khong tim thay khach hang co ma " << maKhachHang << endl;
        return;
    }

    // Update danhSachKhachHang with the new vector
    danhSachKhachHang = newDanhSachKhachHang;

    cout << left << setw(43) << " " << "Xoa thong tin khach hang thanh cong!" << endl;
}

void QLKS::InputFromFile(int T)
{
    string FileName;
    struct TempNgThang
    {
        string Ngay;
        string Thang;
        string Nam;
    };

    if (T == 1)
    {
        // input room
        FileName = "Phong.txt"; // Thay đổi tên file nếu cần
        ifstream fp(FileName);
        if (!fp.is_open())
        {
            throw runtime_error("File " + FileName + " khong ton tai");
        }
        string INPUT;
        string MaPh, LoaiPh;
        int GiaPh, SL;
        bool TTPh;
        while (getline(fp, INPUT))
        {
            istringstream iss(INPUT);
            getline(iss, MaPh, ';');
            getline(iss, LoaiPh, ';');
            string tempGiaPh, tempSL;
            getline(iss, tempGiaPh, ';');
            GiaPh = stoi(tempGiaPh);
            getline(iss, tempSL, ';');
            SL = stoi(tempSL);
            string tempTTPh;
            getline(iss, tempTTPh, ';');
            TTPh = (tempTTPh == "1") ? true : false;
            Phong NewPhong(MaPh, LoaiPh, GiaPh, SL, TTPh);
            danhSachPhong.push_back(NewPhong);
        }
    }
    else if (T == 2)
    {
        // input customer
        FileName = "KhachHang.txt"; // Thay đổi tên file nếu cần
        ifstream fp(FileName);
        if (!fp.is_open())
        {
            throw runtime_error("File " + FileName + " khong ton tai");
        }
        string INPUT;
        string MaKH, TenKH, CCCD, SDT;
        TempNgThang TempNgSinh;
        NgayThang NgSinh;
        bool Gender;
        while (getline(fp, INPUT))
        {
            istringstream iss(INPUT);
            getline(iss, MaKH, ';');
            getline(iss, TenKH, ';');
            getline(iss, TempNgSinh.Ngay, ' ');
            getline(iss, TempNgSinh.Thang, ' ');
            getline(iss, TempNgSinh.Nam, ';');

            // Convert string to integer with error handling
            try
            {
                NgSinh.Ngay = stoi(TempNgSinh.Ngay);
                NgSinh.Thang = stoi(TempNgSinh.Thang);
                NgSinh.Nam = stoi(TempNgSinh.Nam);
            }
            catch (const std::invalid_argument &e)
            {
                cerr << "Invalid argument: " << e.what() << endl;
                continue;
            }
            catch (const std::out_of_range &e)
            {
                cerr << "Out of range error: " << e.what() << endl;
                continue;
            }
            getline(iss, CCCD, ';');
            getline(iss, SDT, ';');
            string tempGender;
            getline(iss, tempGender, ';');
            Gender = (tempGender == "1") ? true : false;
            KhachHang NewKhachHang(MaKH, TenKH, NgSinh, CCCD, SDT, Gender);
            danhSachKhachHang.push_back(NewKhachHang);
        }
    }
    else if (T == 3)
{
    // input Loan
    FileName = "HoaDon.txt"; // Thay đổi tên file nếu cần
    ifstream fp(FileName);
    if (!fp.is_open())
    {
        throw runtime_error("File " + FileName + " khong ton tai");
    }
    string INPUT;
    string MaHD, MaPH, MaKH;
    NgayThang NgThue, NgTra;
    TempNgThang TempNgThue, TempNgTra;
        while (getline(fp, INPUT))
        {
            istringstream iss(INPUT);
            getline(iss, MaHD, ';');
            getline(iss, MaPH, ';');
            getline(iss, MaKH, ';');
            getline(iss, TempNgThue.Ngay, ' ');
            getline(iss, TempNgThue.Thang, ' ');
            getline(iss, TempNgThue.Nam, ';');

            // Convert string to integer with error handling
            try
            {
                NgThue.Ngay = stoi(TempNgThue.Ngay);
                NgThue.Thang = stoi(TempNgThue.Thang);
                NgThue.Nam = stoi(TempNgThue.Nam);
            }
            catch (const std::invalid_argument &e)
            {
                cerr << "Invalid argument: " << e.what() << endl;
                continue;
            }
            catch (const std::out_of_range &e)
            {
                cerr << "Out of range error: " << e.what() << endl;
                continue;
            }

            getline(iss, TempNgTra.Ngay, ' ');
            getline(iss, TempNgTra.Thang, ' ');
            getline(iss, TempNgTra.Nam, ';');
            try
            {
                NgTra.Ngay = stoi(TempNgTra.Ngay);
                NgTra.Thang = stoi(TempNgTra.Thang);
                NgTra.Nam = stoi(TempNgTra.Nam);
            }
            catch (const std::invalid_argument &e)
            {
                cerr << "Invalid argument: " << e.what() << endl;
                continue;
            }
            catch (const std::out_of_range &e)
            {
                cerr << "Out of range error: " << e.what() << endl;
                continue;
            }

            HoaDon NewHoaDon(MaHD, MaPH, MaKH, NgThue, NgTra);
            danhSachHoaDon.push_back(NewHoaDon);
        }

    // Close the try block for creating HoaDon objects
    }
}


void QLKS::LuuDuLieuVaoFile() {
    // Save danhSachPhong to Phong.txt
    ofstream phongFile("Phong.txt");
    for (int i = 0; i < danhSachPhong.getSize(); ++i) {
        Phong ph = danhSachPhong.at(i);
        phongFile << ph.getMaPh() << ';' << ph.getLoaiPh() << ';' << ph.getGiaPh()
                  << ';' << ph.getSLMax() << ';' << (ph.getTT() ? "1" : "0") << '\n';
        } 
    phongFile.close();
    // Save danhSachKhachHang to KhachHang.txt
    ofstream khachHangFile("KhachHang.txt");
    for (int i = 0; i < danhSachKhachHang.getSize(); ++i) {
        KhachHang kh = danhSachKhachHang.at(i);
        NgayThang TempNgSinh = kh.getNgSinh();
        khachHangFile << kh.getMaKH() << ';' << kh.getTenKH() << ';' << TempNgSinh.Ngay << " " << TempNgSinh.Thang << " " 
                      << TempNgSinh.Nam << ';' << kh.getCCCD() << ';' << (kh.getGender() ? "1" : "0") << '\n';
    }
    khachHangFile.close();

    // Save danhSachHoaDon to HoaDon.txt
    ofstream hoaDonFile("HoaDon.txt");
    for (int i = 0; i < danhSachHoaDon.getSize(); ++i) {
        HoaDon hd = danhSachHoaDon.at(i);
        NgayThang TempNgThue = hd.getNgThue(), TempNgTra = hd.getNgTra();
        hoaDonFile << hd.getMaHD() << ";" << hd.getMaPH() << ';' << hd.getMaKH() << ';' 
                   << TempNgThue.Ngay << " " << TempNgThue.Thang << " " << TempNgThue.Nam << ';'
                   << TempNgTra.Ngay << " " << TempNgTra.Thang << " " << TempNgTra.Nam << ';' << '\n';
    }
    hoaDonFile.close();
}

void QLKS::ThuePhong(const HoaDon &hoadon) {
    int khachHangIndex = -1;
    int phongIndex = -1;

    // Tìm kiếm khách hàng
    for (int i = 0; i < danhSachKhachHang.getSize(); ++i) {
        if (danhSachKhachHang.at(i).getMaKH() == hoadon.getMaKH()) {
            khachHangIndex = i;
            break;
        }
    }

    // Kiểm tra khách hàng có tồn tại không
    if (khachHangIndex == -1) {
        cout << left << setw(46) << " " << "Khong tim thay khach hang.\n";
        return;
    }

    // Tìm kiếm phòng
    for (int i = 0; i < danhSachPhong.getSize(); ++i) {
        if (danhSachPhong.at(i).getMaPh() == hoadon.getMaPH()) {
            phongIndex = i;
            break;
        }
    }

    // Kiểm tra phòng có tồn tại và chưa được thuê không
    if (phongIndex == -1) {
        cout << left << setw(46) << " " << "Khong tim thay phong.\n";
        return;
    }

    if (danhSachPhong.at(phongIndex).getTT()) {
        cout << left << setw(46) << " " << "Phong da duoc thue.\n";
        return;
    }

    // Thực hiện thuê phòng
    cout << left << setw(46) << " " << "Da thue phong thanh cong.\n";
    danhSachHoaDon.push_back(hoadon);
    danhSachPhong.at(phongIndex).setTT();
}

    void QLKS::TimPhongTrong() 
{
    cout << left << setw(46) << " " <<"Danh sach phong trong:\n";
    for (int i = 0; i < danhSachPhong.getSize(); ++i) {
        if (!danhSachPhong.at(i).getTT()) {
            cout << left << setw(46) << " " ;
            cout << danhSachPhong.at(i) << "\n";
        }
    }
}
    int QLKS::TinhGiaTien(const string& maHD) {
    int phongIndex = -1, hoadonIndex = -1;

    // Find the index of the invoice in danhSachHoaDon
    for (int i = 0; i < danhSachHoaDon.getSize(); ++i) {
        if (danhSachHoaDon.at(i).getMaHD() == maHD) {
            hoadonIndex = i;
            break;
        }
    }

    if (hoadonIndex == -1) {
        throw runtime_error("Khong tim thay hoa don with MaHD: " + maHD);
    }

    HoaDon TempHD = danhSachHoaDon.at(hoadonIndex);

    // Find the index of the room in danhSachPhong
    for (int i = 0; i < danhSachPhong.getSize(); ++i) {
        if (danhSachPhong.at(i).getMaPh() == TempHD.getMaPH()) {
            phongIndex = i;
            break;
        }
    }

    // Check if the room was found
    if (phongIndex == -1) {
        throw runtime_error("Khong tim thay phong with MaPH: " + TempHD.getMaPH());
    }

    Phong TempPh = danhSachPhong.at(phongIndex);

    // Calculate the rental cost based on the GiaPh of the room
    NgayThang ngayThue = TempHD.getNgThue();
    NgayThang ngayTra = TempHD.getNgTra();
    NgayThang tempTinhSoNgay;
    int soNgayThue = tempTinhSoNgay.TinhSoNgay(ngayThue, ngayTra);
    int giaTien = soNgayThue * TempPh.getGiaPh();
    return giaTien;
}

void QLKS::InHoaDon(const string& maHD) {
    int hoadonIndex = -1;

    // Find the index of the invoice in danhSachHoaDon
    for (int i = 0; i < danhSachHoaDon.getSize(); ++i) {
        if (danhSachHoaDon.at(i).getMaHD() == maHD) {
            hoadonIndex = i;
            break;
        }
    }

    if (hoadonIndex == -1) {
        cout << left << setw(46) << " " <<"Khong tim thay hoa don\n";
        return;
    }

    cout << danhSachHoaDon.at(hoadonIndex);
    cout << left << setw(46) << " " <<"Gia Tien = " << TinhGiaTien(maHD) << "\n";
}

void QLKS::InDanhSachHoaDon()
{
    for (int i = 0; i < danhSachHoaDon.getSize(); ++i)
    {
        cout << danhSachHoaDon.at(i);
        cout << endl;
    }
}


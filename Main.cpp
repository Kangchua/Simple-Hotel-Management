#include "Vector.h"
#include <iomanip>
#include "QLKS.h"
int main()
{
    QLKS quanLyKhachSan;
    try
    {
        quanLyKhachSan.InputFromFile(1);
        quanLyKhachSan.InputFromFile(2);
        quanLyKhachSan.InputFromFile(3);
    }
    catch (const exception &e)
    {
        cerr << "Input error: " << e.what() << endl;
        return 1; // Indicate an error occurred
    }
        int choice;
    do {
        mainmenu:
        cout <<"\n\n";
        cout << left << left << setw(44) << " " <<"PHAN MEM QUAN LY KHACH SAN \n";
        cout << left << setw(43) << " " <<" ___________________________\n";
        cout << left << setw(43) << " " <<"|                           |\n";
        cout << left << setw(43) << " " <<"|   1. Quan Ly Phong        |\n";
        cout << left << setw(43) << " " <<"|   2. Quan Ly Khach Hang   |\n";
        cout << left << setw(43) << " " <<"|   3. Quan Ly Thue Phong   |\n";
        cout << left << setw(43) << " " <<"|   0. Thoat chuong trinh   |\n";
        cout << left << setw(43) << " " <<"|___________________________|\n";
        cout << left << setw(46) << " " <<"Nhap lua chon cua ban: ";
        cin >> choice; 
        cout << endl;
        switch (choice) {
            case 1: {
                int choice1;
                do {
                cout << left << setw(43) << " " <<" ___________________________\n";
                cout << left << setw(43) << " " <<"|                           |\n";
                cout << left << setw(43) << " " <<"|   1. Them Phong           |\n";
                cout << left << setw(43) << " " <<"|   2. In danh sach phong   |\n";
                cout << left << setw(43) << " " <<"|   3. Sua Phong            |\n";
                cout << left << setw(43) << " " <<"|   4. Xoa Phong            |\n";
                cout << left << setw(43) << " " <<"|   0. Quay tro lai Menu    |\n";
                cout << left << setw(43) << " " <<"|___________________________|\n";
                cout << left << setw(46) << " " <<"Nhap lua chon cua ban: ";
                cin >> choice1;
                cout << endl;
                switch (choice1) {
                    case 1:  {
                        Phong newPhong;
                        cin >> newPhong;
                        quanLyKhachSan.ThemPhong(newPhong);
                        break;
                    }
                    case 2: 
                        quanLyKhachSan.InDanhSachPhong();
                        break;
                    case 3: {
                        string MaPh;
                        Phong newPhong;
                        cout << left << setw(46) << " " <<"Nhap ma phong can sua: ";
                        cin >> MaPh;
                        cout << left << setw(46) << " " <<"Nhap phong moi: \n";
                        cout << left << setw(46) << " " ;cin >> newPhong;
                        quanLyKhachSan.SuaPhong(MaPh, newPhong);
                        break;
                    }
                    case 4: {
                        string MaPh;
                        cout << left << setw(46) << " " <<"Nhap ma phong can Xoa: ";
                        cin >> MaPh;
                        quanLyKhachSan.XoaPhong(MaPh);
                        break;
                    } 
                    case 0: {
                        quanLyKhachSan.LuuDuLieuVaoFile();
                        goto mainmenu;
                        break;
                    }
                    default:
                        cout << left << setw(46) << " " <<"Lua chon khong hop le. Vui long chon lai.\n";
                        break;
                    }
                } while (choice1 != 0);
            }
            case 2 : {
                int choice2;
                do {
                cout << left << setw(40) << " " <<" _________________________________\n";
                cout << left << setw(40) << " " <<"|                                 |\n";
                cout << left << setw(40) << " " <<"|   1. Them khach hang            |\n";
                cout << left << setw(40) << " " <<"|   2. In danh sach khach hang    |\n";
                cout << left << setw(40) << " " <<"|   3. Sua thong tin khach hang   |\n";
                cout << left << setw(40) << " " <<"|   4. Xoa thong tin khach hang   |\n";
                cout << left << setw(40) << " " <<"|   5. Tim kiem khach hang        |\n";
                cout << left << setw(40) << " " <<"|   0. Quay tro lai Menu          |\n";
                cout << left << setw(40) << " " <<"|_________________________________|\n";
                cout << left << setw(46) << " " <<"Nhap lua chon cua ban: ";
                cin >> choice2;
                cout << endl;
                switch (choice2) {
                    case 1:  {
                        KhachHang newKhachHang;
                        cin >> newKhachHang;
                        quanLyKhachSan.ThemKhachHang(newKhachHang);
                        break;
                    }
                    case 2: 
                        quanLyKhachSan.InDanhSachKhachHang();
                        break;
                    case 3: {
                        string MaKH;
                        cout << left << setw(46) << " " <<"Nhap ma khach hang can sua: ";
                        cin >> MaKH;
                        quanLyKhachSan.SuaKhachHang(MaKH);
                        break;
                    }
                    case 4: {
                        string MaPh;
                        cout << left << setw(46) << " " <<"Nhap ma khach hang can Xoa: ";
                        cin >> MaPh;
                        quanLyKhachSan.XoaKhachHang(MaPh);
                        break;
                    } 
                    case 5: {
                        string cccd;
                        cout << left << setw(46) << " " <<"Nhap CCCD cua KH can tim: ";
                        cin >> cccd;
                        quanLyKhachSan.TimKiemKhachHang(cccd);
                        break;
                    }
                    case 0: {
                        quanLyKhachSan.LuuDuLieuVaoFile();
                        goto mainmenu;
                        break;
                    }
                    default:
                        cout << left << setw(46) << " " <<"Lua chon khong hop le. Vui long chon lai.\n";
                        break;
                    }
                } while (choice2 != 0);
            }
            case 3 : {
                int choice3;
                do {
                cout << left << setw(43) << " " <<" ____________________________\n";
                cout << left << setw(43) << " " <<"|                            |\n";
                cout << left << setw(43) << " " <<"|   1. Thue Phong            |\n";
                cout << left << setw(43) << " " <<"|   2. Tim Phong Trong       |\n";
                cout << left << setw(43) << " " <<"|   3. In Hoa Don            |\n";
                cout << left << setw(43) << " " <<"|   4. In Danh Sach Hoa Don  |\n";
                cout << left << setw(43) << " " <<"|   0. Quay tro lai Menu     |\n";
                cout << left << setw(43) << " " <<"|____________________________|\n";
                cout << left << setw(46) << " " <<"Nhap lua chon cua ban: ";
                cin >> choice3;
                cout << endl; 
                switch (choice3) {
                    case 1:  {
                        HoaDon newHoaDon;
                        cin >> newHoaDon;
                        quanLyKhachSan.ThuePhong(newHoaDon);
                        break;
                    }
                    
                    case 2: 
                        quanLyKhachSan.TimPhongTrong();
                        break;
                    case 3: {
                        string MaHD;
                        cout << left << setw(46) << " " << "Nhap ma hoa don: ";
                        cin >> MaHD;
                        quanLyKhachSan.InHoaDon(MaHD);
                    break;
                    }
                    case 4: 
                        {
                        cout << left << setw(46) << " " << "Danh sach hoa don:\n";
                        quanLyKhachSan.InDanhSachHoaDon();
                        cout << left << setw(43) << " " <<" ____________________________\n";
                        break;
                    }
                    case 0: {
                        quanLyKhachSan.LuuDuLieuVaoFile();
                        goto mainmenu;
                        break;
                    }
                    default:
                        cout << left << setw(46) << " " << "Lua chon khong hop le. Vui long chon lai.\n";
                        break;
                    }
                } while (choice3 != 0);
            }
            case 0:
                cout << left << setw(46) << " " << "Chuong trinh ket thuc.\n";
                break;
            default:
                cout << left << setw(46) << " " << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
            }     

    } while (choice != 0);
}
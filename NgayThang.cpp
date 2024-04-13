#include "NgayThang.h"
#include <iomanip>
#include <stdbool.h>
bool NgayThang::KiemTra(NgayThang& DMY)
{
     if (DMY.Thang< 1 || DMY.Thang > 12) {
        cout << left << setw(43) << " " <<"Thang khong hop le\n";
        return false;
    }

    if (DMY.Ngay < 1 || DMY.Ngay > 31) {
        cout << left << setw(43) << " " <<"Ngay khong hop le\n";
        return false;
    }

    if ((DMY.Thang == 2 || DMY.Thang == 4 || DMY.Thang == 6 || DMY.Thang == 7 || DMY.Thang == 8 || DMY.Thang == 9 || DMY.Thang == 11) && DMY.Ngay > 30) {
        cout << left << setw(43) << " " <<"Ngay khong hop le\n";
        return false;
    }

    /*if (DMY.Nam > 2024) {
        cout << "Nam khong hop le\n";
        return false;
    } 
    */
    if (DMY.Thang == 2 && DMY.Ngay > 28) {
        if (DMY.Nam % 4 == 0 ) {
            if (DMY.Ngay > 29) {
                cout << left << setw(43) << " " <<"Ngay khong hop le\n";
                return false;
            }
        } else if (DMY.Ngay > 28) {
            cout << left << setw(43) << " " <<"Ngay khong hop le\n";
            return false;
        }
    }
    return true;
}
int NgayThang::TinhSoNgay(const NgayThang& ngay1, const NgayThang& ngay2)
{
        double days1, days2;
        days1 = ngay1.Nam * 365 + ngay1.Thang * 30 + ngay1.Ngay;
        days2 = ngay2.Nam * 365 + ngay2.Thang * 30 + ngay2.Ngay;
        return days2 - days1;    
}

bool NgayThang::SoSanh(const NgayThang& ngay1, const NgayThang& ngay2) {
    if (ngay1.Nam > ngay2.Nam) {
        cout << left << setw(43) << " " <<"Khong hop le \n";
        return false;
    } else if (ngay1.Nam == ngay2.Nam && ngay1.Thang > ngay2.Thang) {
        cout << left << setw(43) << " " <<"Khong hop le \n";
        return false;
    } else if (ngay1.Nam == ngay2.Nam && ngay1.Thang == ngay2.Thang && ngay1.Ngay >= ngay2.Ngay) {
        cout << left << setw(43) << " " <<"Khong hop le \n";
        return false;
    }
    
    return true;
}
#include "CTime.h"

int main() {
    CTime t;

    cout << "Nhap thoi gian (Gio Phut Giay): ";
    cin >> t;

    cout << "Thoi gian sau khi ++t: " << ++t << endl;

    cout << "Thoi gian sau khi --t: " << --t << endl;

    return 0;
}

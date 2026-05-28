#include "PhanSo.h"

int main() {
    PhanSo ps1, ps2;
    cout << "Nhap phan so 1:"; cin >> ps1;
    cout << "Nhap phan so 2:"; cin >> ps2;
    cout << "Tong:    " << ps1 + ps2 << endl;
    cout << "Hieu:    " << ps1 - ps2 << endl;
    cout << "Tich:    " << ps1 * ps2 << endl;
    cout << "Thuong:  " << ps1 / ps2 << endl;
    if (ps1 > ps2) cout << ps1 << " lon hon " << ps2 << endl;
    else if (ps1 < ps2) cout << ps1 << " nho hon " << ps2 << endl;
    else cout << "Hai phan so bang nhau" << endl;

    return 0;
}

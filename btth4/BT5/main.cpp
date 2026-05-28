#include "DaThuc.h"
int main() {
    DaThuc dt1, dt2;
    cout << "Nhap da thuc 1:\n"; cin >> dt1;
    cout << "Nhap da thuc 2:\n"; cin >> dt2;
    cout << "\nDT1: " << dt1;
    cout << "\nDT2: " << dt2;
    cout << "\n\nTong: " << dt1 + dt2;
    cout << "\nHieu: " << dt1 - dt2;
    cout << "\nTich: " << dt1 * dt2 << endl;
    return 0;
}


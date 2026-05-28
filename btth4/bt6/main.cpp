#include "CVector.h"

int main() {
    int n;
    cout << "Nhap so chieu cua vector: "; cin >> n;

    CVector v1(n), v2(n);
    cout << "Nhap vector 1: "; cin >> v1;
    cout << "Nhap vector 2: "; cin >> v2;

    cout << "v1 + v2 = " << v1 + v2 << endl;
    cout << "v1 - v2 = " << v1 - v2 << endl;
    cout << "v1 * v2 (Tich vo huong) = " << v1 * v2 << endl;

    return 0;
}

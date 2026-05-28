#include "CMatrix.h"

int main() {
    CMatrix A, B;

    cout << "Nhap ma tran A:\n";
    cin >> A;

    // Test Tích Ma trận x Ma trận
    cout << "Nhap ma tran B de tinh A * B:\n";
    cin >> B;
    CMatrix C = A.TichMaTran(B);
    if (C.getRows() > 0) {
        cout << "Ket qua A * B:\n" << C;
    } else {
        cout << "Khong the nhan hai ma tran!\n";
    }

    // Test Tích Ma trận x Vector
    int n;
    cout << "\nNhap kich thuoc vector v: ";
    cin >> n;
    vector<double> v(n);
    cout << "Nhap cac phan tu cua vector: ";
    for (int i = 0; i < n; ++i) cin >> v[i];

    vector<double> resV = A.TichVector(v);
    if (!resV.empty()) {
        cout << "Ket qua A * v: ";
        for (double x : resV) cout << x << " ";
        cout << endl;
    } else {
        cout << "Kich thuoc vector khong khop voi ma tran A!\n";
    }

    return 0;
}

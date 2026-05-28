#include "SoPhuc.h"

int main()
{
    SoPhuc sp1, sp2;

    cout << "Nhap so phuc 1:\n";
    cin >> sp1;
    cout << "Nhap so phuc 2:\n";
    cin >> sp2;

    cout << "\nTong: " << sp1 + sp2;
    cout << "\nHieu: " << sp1 - sp2;
    cout << "\nTich: " << sp1 * sp2;
    cout << "\nThuong: " << sp1 / sp2;

    if (sp1 == sp2) cout << "Hai so phuc bang nhau.";
    else cout << "Hai so phuc khac nhau.";

    SoPhuc spThuc(5);
    cout << "\nSo phuc tu so thuc: " << spThuc << endl;

    return 0;
}

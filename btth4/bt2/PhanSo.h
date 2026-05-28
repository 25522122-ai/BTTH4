#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>
using namespace std;

class PhanSo {
private:
    int iTu, iMau;
    void RutGon();
public:
    PhanSo(int tu = 0, int mau = 1);
    PhanSo operator+(const PhanSo& ps) const;
    PhanSo operator-(const PhanSo& ps) const;
    PhanSo operator*(const PhanSo& ps) const;
    PhanSo operator/(const PhanSo& ps) const;
    bool operator==(const PhanSo& ps) const;
    bool operator>(const PhanSo& ps) const;
    bool operator<(const PhanSo& ps) const;
    friend istream& operator>>(istream& in, PhanSo& ps);
    friend ostream& operator<<(ostream& out, const PhanSo& ps);
};
#endif

#include "PhanSo.h"
#include <cmath>
long long TimUCLN(long long a, long long b) {
    a = std::abs(a); b = std::abs(b);
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return (a == 0) ? 1 : a;
}
PhanSo::PhanSo(int tu, int mau) : iTu(tu), iMau(mau == 0 ? 1 : mau) {
    RutGon();
}
void PhanSo::RutGon() {
    long long ucln = TimUCLN(iTu, iMau);
    iTu /= (int)ucln;
    iMau /= (int)ucln;
    if (iMau < 0) { iTu = -iTu; iMau = -iMau; }
    if (iTu == 0) iMau = 1;
}
PhanSo PhanSo::operator+(const PhanSo& ps) const {
    long long tu = (long long)iTu * ps.iMau + (long long)ps.iTu * iMau;
    long long mau = (long long)iMau * ps.iMau;
    return PhanSo((int)tu, (int)mau); // Constructor sẽ tự gọi RutGon an toàn
}
PhanSo PhanSo::operator-(const PhanSo& ps) const {
    long long tu = (long long)iTu * ps.iMau - (long long)ps.iTu * iMau;
    long long mau = (long long)iMau * ps.iMau;
    return PhanSo((int)tu, (int)mau);
}

PhanSo PhanSo::operator*(const PhanSo& ps) const {
    long long tu = (long long)iTu * ps.iTu;
    long long mau = (long long)iMau * ps.iMau;
    return PhanSo((int)tu, (int)mau);
}
PhanSo PhanSo::operator/(const PhanSo& ps) const {
    if (ps.iTu == 0) return PhanSo(0, 1); // Tránh chia cho 0
    long long tu = (long long)iTu * ps.iMau;
    long long mau = (long long)iMau * ps.iTu;
    return PhanSo((int)tu, (int)mau);
}

bool PhanSo::operator==(const PhanSo& ps) const {
    return iTu == ps.iTu && iMau == ps.iMau;
}

bool PhanSo::operator>(const PhanSo& ps) const {
    return (long long)iTu * ps.iMau > (long long)ps.iTu * iMau;
}

bool PhanSo::operator<(const PhanSo& ps) const {
    return (long long)iTu * ps.iMau < (long long)ps.iTu * iMau;
}

istream& operator>>(istream& in, PhanSo& ps) {
    in >> ps.iTu >> ps.iMau;
    if (ps.iMau == 0) ps.iMau = 1;
    ps.RutGon();
    return in;
}
ostream& operator<<(ostream& out, const PhanSo& ps) {
    if (ps.iTu == 0) out << 0;
    else if (ps.iMau == 1) out << ps.iTu;
    else out << ps.iTu << "/" << ps.iMau;
    return out;
}


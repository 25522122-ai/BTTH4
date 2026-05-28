#include "DaThuc.h"
#include <algorithm>
DaThuc::DaThuc(int bac) : n(bac) {
    a = new double[n + 1];
    for (int i = 0; i <= n; i++) a[i] = 0;
}
DaThuc::~DaThuc() {
    delete[] a;
}
DaThuc::DaThuc(const DaThuc &dt) {
    n = dt.n;
    a = new double[n + 1];
    for (int i = 0; i <= n; i++) a[i] = dt.a[i];
}
DaThuc& DaThuc::operator=(const DaThuc &dt) {
    if (this != &dt) {
        delete[] a;
        n = dt.n;
        a = new double[n + 1];
        for (int i = 0; i <= n; i++) a[i] = dt.a[i];
    }
    return *this;
}
DaThuc DaThuc::operator+(const DaThuc &dt) const {
    int maxBac = max(n, dt.n);
    DaThuc res(maxBac);
    for (int i = 0; i <= maxBac; i++) {
        double v1 = (i <= n) ? a[i] : 0;
        double v2 = (i <= dt.n) ? dt.a[i] : 0;
        res.a[i] = v1 + v2;
    }
    return res;
}
DaThuc DaThuc::operator-(const DaThuc &dt) const {
    int maxBac = max(n, dt.n);
    DaThuc res(maxBac);
    for (int i = 0; i <= maxBac; i++) {
        double v1 = (i <= n) ? a[i] : 0;
        double v2 = (i <= dt.n) ? dt.a[i] : 0;
        res.a[i] = v1 - v2;
    }
    return res;
}
DaThuc DaThuc::operator*(const DaThuc &dt) const {
    DaThuc res(n + dt.n);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= dt.n; j++)
            res.a[i + j] += a[i] * dt.a[j];
    return res;
}

istream& operator>>(istream& in, DaThuc& dt) {
    cout << "Nhap bac cua da thuc: "; in >> dt.n;
    delete[] dt.a;
    dt.a = new double[dt.n + 1];
    for (int i = dt.n; i >= 0; i--) {
        cout << "He so bac " << i << ": ";
        in >> dt.a[i];
    }
    return in;
}
ostream& operator<<(ostream& out, const DaThuc& dt) {
    for (int i = dt.n; i >= 0; i--) {
        if (dt.a[i] != 0) {
            out << (dt.a[i] > 0 && i != dt.n ? " + " : "") << dt.a[i];
            if (i > 0) out << "x^" << i;
        }
    }
    return out;
}

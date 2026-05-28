#include "CVector.h"

CVector::CVector(int chieu) : n(chieu) {
    v = new double[n];
    for (int i = 0; i < n; i++) v[i] = 0;
}

CVector::~CVector() {
    delete[] v;
}

CVector::CVector(const CVector& other) : n(other.n) {
    v = new double[n];
    for (int i = 0; i < n; i++) v[i] = other.v[i];
}

CVector& CVector::operator=(const CVector& other) {
    if (this != &other) {
        delete[] v;
        n = other.n;
        v = new double[n];
        for (int i = 0; i < n; i++) v[i] = other.v[i];
    }
    return *this;
}

CVector CVector::operator+(const CVector& other) const {
    if (n != other.n) return CVector(0);
    CVector res(n);
    for (int i = 0; i < n; i++) res.v[i] = v[i] + other.v[i];
    return res;
}

CVector CVector::operator-(const CVector& other) const {
    if (n != other.n) return CVector(0);
    CVector res(n);
    for (int i = 0; i < n; i++) res.v[i] = v[i] - other.v[i];
    return res;
}

double CVector::operator*(const CVector& other) const {
    double res = 0;
    if (n == other.n) {
        for (int i = 0; i < n; i++) res += v[i] * other.v[i];
    }
    return res;
}

istream& operator>>(istream& in, CVector& vec) {
    for (int i = 0; i < vec.n; i++) {
        in >> vec.v[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const CVector& vec) {
    out << "(";
    for (int i = 0; i < vec.n; i++) {
        out << vec.v[i] << (i == vec.n - 1 ? "" : ", ");
    }
    out << ")";
    return out;
}

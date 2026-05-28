#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
using namespace std;

class CVector {
private:
    int n;
    double* v;
public:
    CVector(int chieu = 0);
    ~CVector();
    CVector(const CVector& other);
    CVector& operator=(const CVector& other);

    CVector operator+(const CVector& other) const;
    CVector operator-(const CVector& other) const;
    double operator*(const CVector& other) const; // Tich vo huong

    friend istream& operator>>(istream& in, CVector& vec);
    friend ostream& operator<<(ostream& out, const CVector& vec);
};

#endif

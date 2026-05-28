#ifndef SOPHUC_H
#define SOPHUC_H
#include <iostream>
using namespace std;

class SoPhuc
{
private:
    double dThuc, dAo;

public:
    SoPhuc(double thuc  = 0, double ao = 0);

    SoPhuc operator+(const SoPhuc& a) const;
    SoPhuc operator-(const SoPhuc& a) const;
    SoPhuc operator*(const SoPhuc& a) const;
    SoPhuc operator/(const SoPhuc& a) const;


    bool operator==(const SoPhuc& a) const;
    bool operator!=(const SoPhuc& a) const;


    friend istream& operator>>(istream& in, SoPhuc& sp);
    friend ostream& operator<<(ostream& out, const SoPhuc& sp);
};

#endif

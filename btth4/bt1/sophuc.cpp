#include "SoPhuc.h"
SoPhuc::SoPhuc(double thuc, double ao) : dThuc(thuc), dAo(ao) {}

SoPhuc SoPhuc::operator+(const SoPhuc& a) const
{
    return SoPhuc(dThuc + a.dThuc, dAo + a.dAo);
}

SoPhuc SoPhuc::operator-(const SoPhuc& a) const
{
    return SoPhuc(dThuc - a.dThuc, dAo - a.dAo);
}


SoPhuc SoPhuc::operator*(const SoPhuc& a) const
{
    return SoPhuc(dThuc * a.dThuc - dAo * a.dAo, dThuc * a.dAo + dAo * a.dThuc);
}


SoPhuc SoPhuc::operator/(const SoPhuc& a) const
{
    double mau = a.dThuc * a.dThuc + a.dAo * a.dAo;
    return SoPhuc((dThuc * a.dThuc + dAo * a.dAo) / mau, (dAo * a.dThuc - dThuc * a.dAo) / mau);
}

bool SoPhuc::operator==(const SoPhuc& a) const
{
    return (dThuc == a.dThuc && dAo == a.dAo);
}

bool SoPhuc::operator!=(const SoPhuc& a) const
{
    return !(*this == a);
}


istream& operator>>(istream& in, SoPhuc& sp)
{
    cout << "Nhap phan thuc: ";
    in >> sp.dThuc;
    cout << "Nhap phan ao: ";
    in >> sp.dAo;
    return in;
}


ostream& operator<<(ostream& out, const SoPhuc& sp)
{
    out << sp.dThuc << (sp.dAo >= 0 ? " + " : " - ") << abs(sp.dAo) << "i";
    return out;
}

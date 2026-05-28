#include "CDate.h"
#include <cmath>
CDate::CDate(int d, int m, int y) : iNgay(d), iThang(m), iNam(y) {}
bool CDate::LaNamNhuan(int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}
int CDate::TimSoNgayTrongThang(int m, int y) const {
    int ngay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && LaNamNhuan(y)) return 29;
    return ngay[m];
}
CDate& CDate::operator++() {
    iNgay++;
    if (iNgay > TimSoNgayTrongThang(iThang, iNam)) {
        iNgay = 1;
        iThang++;
        if (iThang > 12) {
            iThang = 1;
            iNam++;
        }
    }
    return *this;
}
CDate& CDate::operator--() {
    iNgay--;
    if (iNgay < 1) {
        iThang--;
        if (iThang < 1) {
            iThang = 12;
            iNam--;
        }
        iNgay = TimSoNgayTrongThang(iThang, iNam);
    }
    return *this;
}
CDate CDate::operator+(int ngay) const {
    CDate res = *this;
    for (int i = 0; i < ngay; i++) ++res;
    return res;
}
CDate CDate::operator-(int ngay) const {
    CDate res = *this;
    for (int i = 0; i < ngay; i++) --res;
    return res;
}
long CDate::ToAbsoluteDays() const {
    long total = iNgay;
    for (int y = 1; y < iNam; y++) total += (LaNamNhuan(y) ? 366 : 365);
    for (int m = 1; m < iThang; m++) total += TimSoNgayTrongThang(m, iNam);
    return total;
}
int CDate::operator-(const CDate& d2) const {
    return abs(this->ToAbsoluteDays() - d2.ToAbsoluteDays());
}
istream& operator>>(istream& in, CDate& d) {
    in >> d.iNgay >> d.iThang >> d.iNam;
    return in;
}
ostream& operator<<(ostream& out, const CDate& d) {
    out << d.iNgay << "/" << d.iThang << "/" << d.iNam;
    return out;
}

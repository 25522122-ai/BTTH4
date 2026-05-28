#ifndef CDATE_H
#define CDATE_H
#include <iostream>
using namespace std;
class CDate {
private:
    int iNgay, iThang, iNam;
    bool LaNamNhuan(int y) const;
    int TimSoNgayTrongThang(int m, int y) const;
    long ToAbsoluteDays() const;
public:
    CDate(int d = 1, int m = 1, int y = 1);
    CDate operator+(int ngay) const;
    CDate operator-(int ngay) const;
    CDate& operator++();
    CDate& operator--();
    int operator-(const CDate& d2) const;
    friend istream& operator>>(istream& in, CDate& d);
    friend ostream& operator<<(ostream& out, const CDate& d);
};
#endif

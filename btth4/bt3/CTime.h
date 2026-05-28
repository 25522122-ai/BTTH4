#ifndef CTIME_H
#define CTIME_H

#include <iostream>
#include <iomanip>
using namespace std;

class CTime {
private:
    int iGio, iPhut, iGiay;
    void ChuanHoa();
public:

    CTime(int gio = 0, int phut = 0, int giay = 0);

    CTime operator+(int giay) const;
    CTime operator-(int giay) const;

    CTime& operator++();      // ++t
    CTime operator++(int);    // t++
    CTime& operator--();      // --t
    CTime operator--(int);    // t--

    friend istream& operator>>(istream& in, CTime& t);
    friend ostream& operator<<(ostream& out, const CTime& t);
};

#endif

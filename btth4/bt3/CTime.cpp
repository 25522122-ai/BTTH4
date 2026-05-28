#include "CTime.h"

CTime::CTime(int gio, int phut, int giay) : iGio(gio), iPhut(phut), iGiay(giay) {
    ChuanHoa();
}

void CTime::ChuanHoa() {

    long long tongGiay = (long long)iGio * 3600 + iPhut * 60 + iGiay;

    while (tongGiay < 0) tongGiay += 86400;
    tongGiay %= 86400;

    iGio = tongGiay / 3600;
    tongGiay %= 3600;
    iPhut = tongGiay / 60;
    iGiay = tongGiay % 60;
}

CTime CTime::operator+(int giay) const {
    return CTime(iGio, iPhut, iGiay + giay);
}

CTime CTime::operator-(int giay) const {
    return CTime(iGio, iPhut, iGiay - giay);
}

CTime& CTime::operator++() {
    iGiay++;
    ChuanHoa();
    return *this;
}

CTime CTime::operator++(int) {
    CTime temp = *this;
    ++(*this);
    return temp;
}

CTime& CTime::operator--() {
    iGiay--;
    ChuanHoa();
    return *this;
}

CTime CTime::operator--(int) {
    CTime temp = *this;
    --(*this);
    return temp;
}

istream& operator>>(istream& in, CTime& t) {
    in >> t.iGio >> t.iPhut >> t.iGiay;
    t.ChuanHoa();
    return in;
}

ostream& operator<<(ostream& out, const CTime& t) {
    out << setfill('0') << setw(2) << t.iGio << ":"
        << setfill('0') << setw(2) << t.iPhut << ":"
        << setfill('0') << setw(2) << t.iGiay;
    return out;
}

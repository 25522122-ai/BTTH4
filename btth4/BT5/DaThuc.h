#ifndef DATHUC_H
#define DATHUC_H
#include <iostream>
using namespace std;
class DaThuc {
private:
    int n;
    double *a;
public:
    DaThuc(int bac = 0);
    ~DaThuc();
    DaThuc(const DaThuc &dt);
    DaThuc operator+(const DaThuc &dt) const;
    DaThuc operator-(const DaThuc &dt) const;
    DaThuc operator*(const DaThuc &dt) const;
    DaThuc& operator=(const DaThuc &dt);
    friend istream& operator>>(istream& in, DaThuc& dt);
    friend ostream& operator<<(ostream& out, const DaThuc& dt);
};
#endif

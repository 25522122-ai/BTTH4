#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include <vector>
using namespace std;

class CMatrix {
private:
    int rows, cols;
    vector<vector<double>> data;

public:
    CMatrix(int r = 0, int c = 0);

    // Nhập xuất ma trận
    friend istream& operator>>(istream& in, CMatrix& mat);
    friend ostream& operator<<(ostream& out, const CMatrix& mat);

    // Tính toán
    vector<double> TichVector(const vector<double>& v) const;
    CMatrix TichMaTran(const CMatrix& other) const;

    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

#endif

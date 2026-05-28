#include "CMatrix.h"

CMatrix::CMatrix(int r, int c) : rows(r), cols(c) {
    data.resize(r, vector<double>(c, 0));
}

istream& operator>>(istream& in, CMatrix& mat) {
    cout << "Nhap so hang va so cot: ";
    in >> mat.rows >> mat.cols;
    mat.data.assign(mat.rows, vector<double>(mat.cols, 0));
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            in >> mat.data[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const CMatrix& mat) {
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            out << mat.data[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

// Tích Ma trận x Vector
vector<double> CMatrix::TichVector(const vector<double>& v) const {
    if (cols != (int)v.size()) {
        return {}; // Kích thước không khớp
    }
    vector<double> res(rows, 0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            res[i] += data[i][j] * v[j];
        }
    }
    return res;
}


CMatrix CMatrix::TichMaTran(const CMatrix& other) const {
    if (this->cols != other.rows) {
        return CMatrix(0, 0);
    }
    CMatrix res(this->rows, other.cols);
    for (int i = 0; i < res.rows; ++i) {
        for (int j = 0; j < res.cols; ++j) {
            for (int k = 0; k < this->cols; ++k) {
                res.data[i][j] += this->data[i][k] * other.data[k][j];
            }
        }
    }
    return res;
}

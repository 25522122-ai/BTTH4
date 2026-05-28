#include <iostream>
#include "CDate.h"
using namespace std;
int main() {
    CDate d1, d2;
    int n;
    cin >> d1;
    cin >> d2;
    cin >> n;
    cout << d1 + n << endl;
    cout << d1 - n << endl;
    cout << ++d1 << endl;
    cout << --d1 << endl;
    cout << d1 - d2 << endl;
    return 0;
}

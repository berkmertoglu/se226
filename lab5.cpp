#include <iostream>
#include <cmath>
using namespace std;

double geometricSum(int n, double r) {
    
    if (n == 0)
        return 1; 

    return pow(r, n) + geometricSum(n - 1, r);
}

int main() {
    int n;
    double r;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter common ratio r: ";
    cin >> r;

    double result = geometricSum(n, r);

    cout << "Geometric Sum: " << result << endl;

    return 0;
}

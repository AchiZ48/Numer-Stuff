#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int size = 4;
    double A[4][4] = {
        {5, 2, 0, 0},
        {2, 5, 2, 0},
        {0, 2, 5, 2},
        {0, 0, 2, 5}
    };
    double b[4] = {12, 17, 14, 7};
    double x[4] = {0.0, 0.0, 0.0, 0.0};
    double x_new[4] = {0.0, 0.0, 0.0, 0.0};
    int maxIter = 100;
    double tol = 0.001;
    double err = 1.0;
    int iteration = 0;
    while (err > tol && iteration < maxIter) {
        err = 0.0;
        for (int i = 0; i < size; ++i) {
            double sum = 0.0;
            for (int j = 0; j < size; ++j) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
            err += fabs((x_new[i] - x[i]) / x_new[i]) * 100.0;
            x[i] = x_new[i];
        }
        iteration++;
    }
    cout << "Solution after " << iteration << " iterations:" << endl;
    for (int i = 0; i < size; ++i)
        cout << "x[" << i << "] = " << x[i] << endl;
    return 0;
}

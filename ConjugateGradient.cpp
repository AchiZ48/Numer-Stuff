#include <iostream>
#include <cmath>
using namespace std;

double dotProduct(double* A, double* B, int size) {
    double result = 0.0;
    for (int i = 0; i < size; i++) {
        result += A[i] * B[i];
    }
    return result;
}

void multiplyMatrixVector(double A[][4], double* X, double* result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = 0.0;
        for (int j = 0; j < size; j++) {
            result[i] += A[i][j] * X[j];
        }
    }
}

void addVectors(double* A, double* B, double* result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = A[i] + B[i];
    }
}

void subtractVectors(double* A, double* B, double* result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = A[i] - B[i];
    }
}

void multiplyScalar(double* A, double scalar, double* result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = A[i] * scalar;
    }
}

double computeError(double* R, int size) {
    return sqrt(dotProduct(R, R, size));
}

int main() {
    int size = 4;
    // เมทริกซ์ A
    double A[4][4] = {
        {5, 2, 0, 0},
        {2, 5, 2, 0},
        {0, 2, 5, 2},
        {0, 0, 2, 5}
    };
    // เวกเตอร์ B
    double B[4] = {12, 17, 14, 7};
    // ค่าเริ่มต้นของ X
    double X[4] = {0.0, 0.0, 0.0, 0.0};

    double R[4], D[4], AD[4];
    double alpha, beta, error = 1.0;
    int iteration = 0;
    double tol = 1e-6;

    // R0 = B - A*X0
    double temp[4];
    multiplyMatrixVector(A, X, temp, size);
    subtractVectors(B, temp, R, size);

    // D0 = R0
    for (int i = 0; i < size; i++) D[i] = R[i];

    double rr_old = dotProduct(R, R, size);

    while (error > tol && iteration < 1000) {
        // AD = A*D
        multiplyMatrixVector(A, D, AD, size);

        // alpha = (r^T r) / (d^T A d)
        alpha = rr_old / dotProduct(D, AD, size);

        // X = X + alpha*D
        multiplyScalar(D, alpha, temp, size);
        addVectors(X, temp, X, size);

        // R = R - alpha*AD
        multiplyScalar(AD, alpha, temp, size);
        subtractVectors(R, temp, R, size);

        // เช็ก error = ||R||
        error = computeError(R, size);

        // beta = (r_new^T r_new) / (r_old^T r_old)
        double rr_new = dotProduct(R, R, size);
        beta = rr_new / rr_old;
        rr_old = rr_new;

        // D = R + beta*D
        multiplyScalar(D, beta, temp, size);
        addVectors(R, temp, D, size);

        cout << "Iteration " << iteration + 1 << ": ";
        for (int i = 0; i < size; i++) {
            cout << X[i] << " ";
        }
        cout << " | Error = " << error << endl;

        iteration++;
    }

    cout << "\nSolution X: ";
    for (int i = 0; i < size; i++) cout << X[i] << " ";
    cout << endl;

    return 0;
}

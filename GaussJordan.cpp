#include <bits/stdc++.h>
using namespace std;

const int N = 3;

void printMatrix(float A[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        cout << "| ";
        for (int j = 0; j < N; j++)
            cout << setw(8) << fixed << setprecision(4) << A[i][j] << " ";
        cout << " | " << setw(8) << A[i][N] << " |\n";
    }
    cout << "-----------------------------\n";
}

int main() {
    float A[N][N + 1], x[N];

    cout << "Enter the augmented matrix (3x4):" << endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N + 1; j++)
            cin >> A[i][j];

    cout << "\nInitial Matrix:\n";
    printMatrix(A);

    for (int i = 0; i < N; i++) {
        float pivot = A[i][i];
        cout << "\nNormalize row " << i + 1 << " (make pivot = 1):\n";
        for (int j = 0; j <= N; j++)
            A[i][j] /= pivot;
        printMatrix(A);

        for (int k = 0; k < N; k++) {
            if (k != i) {
                float factor = A[k][i];
                cout << "R" << k + 1 << " -> R" << k + 1 << " - (" << factor << ") * R" << i + 1 << endl;
                for (int j = 0; j <= N; j++)
                    A[k][j] -= factor * A[i][j];
                printMatrix(A);
            }
        }
    }

    for (int i = 0; i < N; i++)
        x[i] = A[i][N];

    cout << "\nSolutions:\n";
    for (int i = 0; i < N; i++)
        cout << "x" << i + 1 << " = " << fixed << setprecision(4) << x[i] << endl;

    return 0;
}


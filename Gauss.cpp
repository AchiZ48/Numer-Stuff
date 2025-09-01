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

    cout << "Enter the augmented matrix (3x4):\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N + 1; j++)
            cin >> A[i][j];

    cout << "\nInitial Matrix:\n";
    printMatrix(A);

    for (int i = 0; i < N; i++) {
        float pivot = A[i][i];

        cout << "\nStep " << i + 1 << ": Normalize row " << i + 1 << "\n";
        for (int j = i; j <= N; j++)
            A[i][j] /= pivot;
        printMatrix(A);

        for (int k = i + 1; k < N; k++) {
            float factor = A[k][i];
            cout << "Eliminate A"<< k + 1 << i + 1 << " using R" << i + 1
                 << " with factor = " << factor << "\n";
            for (int j = i; j <= N; j++)
                A[k][j] -= factor * A[i][j];
            printMatrix(A);
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        x[i] = A[i][N];
        for (int j = i + 1; j < N; j++)
            x[i] -= A[i][j] * x[j];
    }

    cout << "\nSolutions:\n";
    for (int i = 0; i < N; i++)
        cout << "x" << i + 1 << " = " << fixed << setprecision(4) << x[i] << endl;

    return 0;
}


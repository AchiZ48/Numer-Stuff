#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return (7+x)/(x+1);
}
int main() {
	double x = 0;
    double x0;
    double tol = 0.000001;
    double x1;
    double check;
    int max_iter = 100, iter = 0;
    do {
    	x0 = x;
        x = f(x);
		x1 = x;
		check = abs(x1-x0);
        iter++;
        cout <<setprecision(7)<< "Iteration " <<iter<<" "<< x0 << " " << f(x0)<<endl;
    } while (check > tol && iter < max_iter);
    cout <<setprecision(7)<< "sqrt(7) = " << x1 << endl;
    cout << "Iterations: " << iter << endl;
    return 0;
}


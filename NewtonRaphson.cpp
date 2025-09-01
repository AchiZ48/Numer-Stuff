#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return x * x - 7.0;
}

double f_prime(double x) {
    return 2.0 * x;
}

int main() {
    double x = 2.0;
    double tolerance = 0.000001;
    double x0;
    int iteration = 0;
    double error;   
    do {
        x0 = x;
        double fx = f(x);
        double fpx = f_prime(x);
        x = x - fx / fpx;        
        error = abs((x - x0)/x);
        cout<<fixed<<setprecision(6)<<"f(x) : "<<fx<<endl;
        cout<<fixed<<setprecision(6)<<"f'(x) : "<<fpx<<endl;
        cout<<fixed<<setprecision(6)<<"xi+1 : "<<x<<endl;
        cout<<"iteration : "<<iteration<<endl;
        cout<<setprecision(6)<<"error : "<<error<<endl;
        iteration++;       
    } while (iteration < 5);
    return 0;
}

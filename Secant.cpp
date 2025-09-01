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

double slope(double x0,double x1) {
    return (f(x0)-f(x1))/(x0-x1);
}

int main() {   
    double tolerance = 0.000001;
    double x0 = 2.0;
    double x1 = x0-(f(x0)/f_prime(x0));
    double x2;
    int iteration = 0;
    double error;
    
    do {
        double fx = f(x1);
        double fpx = slope(x0,x1);
        x2 = x1 - fx / fpx;        
        error = abs((x2 - x1)/x2);;
        cout<<fixed<<setprecision(6)<<"f(x) : "<<fx<<endl;
        cout<<fixed<<setprecision(6)<<"tan : "<<fpx<<endl;
        cout<<fixed<<setprecision(6)<<"x"<<iteration<<" : "<<x0<<endl;
        cout<<fixed<<setprecision(6)<<"x"<<iteration+1<<" : "<<x1<<endl;
        cout<<fixed<<setprecision(6)<<"x"<<iteration+2<<" : "<<x2<<endl;
        cout<<"iteration : "<<iteration+1<<endl;
        cout<<setprecision(6)<<"error : "<<error<<endl;
		x0 = x1;
		x1 = x2;
        iteration++;
        
    } while (error > tolerance && iteration < 100);   
    return 0;
}

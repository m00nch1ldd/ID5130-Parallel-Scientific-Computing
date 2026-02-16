#include <iostream>
#include <math.h> //sin, pow
#include<time.h> //clock_t
using namespace std;

double fun (double x) {
    double f=sin(x)/(2*pow(x,3));
    return f;
}

void trapezoid (double a, double b, double *T, int n) { //in c++ arrays inherently passed as reference
    double h = (b-a)/n;
    double x_i;
    double sum=0;
    for (int i=1;i<n;i++){
        x_i=a+i*h;
        sum+=fun(x_i);
    }

    *T=h*((fun(a)+fun(b))/2 + sum);
    return;
}

int main() {
    double a = 1;
    double b = M_PI;
    int n = 32;
    double T;
    clock_t t;
    t=clock();
    trapezoid(a,b,&T,n); 
    t=clock()-t;
    double time=((float)t)/CLOCKS_PER_SEC;
    cout<<"T="<<T<<" t="<<time<<"\n"; 
    double actual = 0.198557;
    cout<<"The error involved is: "<<actual - T<< " = "<< abs(actual-T)/actual * 100 << "%"<<endl;
    return 0;
}
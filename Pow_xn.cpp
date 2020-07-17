#include<iostream>
using namespace std;
double myPow(double x, int n) {
        if (n==0) return 1;
        double temp = myPow(x,n/2);
        if (n%2)
            return n>0?temp*temp*x:temp*temp/x;
        else 
            return temp*temp;      
}
int main(){
    double x = 10.00;
    int n = 20;
    cout<<myPow(x,n)<<endl;

    return 0;
}

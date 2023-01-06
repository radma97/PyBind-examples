#include <chrono>
#include <iostream>

double sum(double *v, int n) {
    double s=0.0;
    for (int i=0;i<n;i++) {
        s+=v[i]*v[i];
    }
    return s;}

int main() {
    int n=1000000;
    double *d = new double[n];
    for (int i=0;i<n;i++) {
        d[i]=100.0*i/(n-1);
    }

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    double s=0;
    auto t1 = high_resolution_clock::now();
    for (int k=0;k<1000;k++) {
        s += sum(d,n);
    }
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << s << ": sum\n";
    std::cout << ms_double.count()/1000 << "ms\n";
}
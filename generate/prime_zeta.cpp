#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <algorithm>
using namespace std;

//since we want critical strip (Re(z)<1), need analythic continuation
complex<double> eta(complex<double> s, int N = 300) {
    complex<double> sum = 0;
    for (int n = 1; n <= N; ++n) {
        auto term = pow(complex<double>(n), -s);
        sum += (n & 1) ? term : -term;
    }
    return sum;
}

complex<double> zeta(complex<double> s, int N = 300) {
    return eta(s, N) / (1.0 - pow(2.0, 1.0 - s));
}

vector<float> generate_zeta_audio(float amplitude, float speed, float rate=44100, float dur=5){
    //speed = how far up the imaginary line per second we go.
    //amplitude basically volume

    vector<float> data;

    for(int i = 0; i < (rate*dur); i++){
        float t = speed * (i / rate);
        complex<double> z = zeta(complex<double>(0.5, t));
        // float a = static_cast<float>(abs(z));
        // if (z.real() < 0){
        //     a = a * -1.0;
        // }
        float a = sin(arg(z));
        data.push_back(a);
    }
    process_range(data, amplitude);
    return data;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <algorithm>
using namespace std;


float weierstrass( float x, float a = 0.5f, int b = 7){
    float sum = 0;
    for(int i=1; i<20; ++i){
        sum += pow(a,i) * cos(pow(b,i) * pi * x);
    }
    return sum;
}

vector<float> generate_weierstrass(float amplitude, float freq, float rate, float dur){
    vector<float> data;
    for(int i = 0; i < (rate*dur); i++){
        float a = amplitude * weierstrass(freq * (i/rate));
        data.push_back(a);
    }
    return data;
}
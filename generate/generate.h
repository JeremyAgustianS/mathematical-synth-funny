#pragma once
#include <helper.cpp>
#include <prime_zeta.cpp>
#include <weierstrass.cpp>

void process_range(vector<float> &audio_data, float amp);

vector<float> generate_sin(float amplitude, float freq, float rate, float dur);
//boring sin wave

vector<float> generate_zeta_audio(float amplitude, float speed, float rate, float dur);
// audio is directly sampled from zeta function, sampled from arg(zeta(z))

vector<float> generate_funny_zeta(float amplitude, float freq, float rate, float dur);
// a nice sine wave, given frequency modulation based on arg(zeta(z))

vector<float> generate_weierstrass(float amplitude, float freq, float rate, float dur);
// weierstrass function
#pragma once
#include <helper.cpp>
#include <prime_zeta.cpp>

void process_range(vector<float> &audio_data, float amp);

vector<float> generate_zeta_audio(float amplitude, float speed, float rate, float dur);
vector<float> generate_funny_zeta(float amplitude, float freq, float rate, float dur);

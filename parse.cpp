#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdint>
using namespace std;

// takes vector array -> wav 44k 
void export_wav(const string& filename, const vector<float> audio_data, int sample_rate = 44100){
    ofstream file(".\\output\\"+filename, std::ios::binary);
    if(!file){
        cerr << "Error: file not found" << endl;
        return;
    }

    int num_channels = 1; //mono
    int bytes_per_sample = 2; //16 bit audio
    int total_samples = audio_data.size(); //size

    //------------boring file header stuff:-----------------//

    // Calculate sizes for the WAV header
    int data_chunk_size = total_samples * num_channels * bytes_per_sample;
    int file_size_minus_8 = 36 + data_chunk_size;
    int byte_rate = sample_rate * num_channels * bytes_per_sample;
    int16_t block_align = num_channels * bytes_per_sample;
    int16_t bits_per_sample = 16;
    int16_t audio_format = 1;     // 1 = Uncompressed PCM linear format

    // Write the 44-byte standard RIFF/WAVE header
    file.write("RIFF", 4);
    file.write(reinterpret_cast<const char*>(&file_size_minus_8), 4);
    file.write("WAVE", 4);
    file.write("fmt ", 4);
    
    int subchunk1_size = 16;       // Size of the format chunk
    file.write(reinterpret_cast<const char*>(&subchunk1_size), 4);
    file.write(reinterpret_cast<const char*>(&audio_format), 2);
    file.write(reinterpret_cast<const char*>(&num_channels), 2);
    file.write(reinterpret_cast<const char*>(&sample_rate), 4);
    file.write(reinterpret_cast<const char*>(&byte_rate), 4);
    file.write(reinterpret_cast<const char*>(&block_align), 2);
    file.write(reinterpret_cast<const char*>(&bits_per_sample), 2);
    
    file.write("data", 4);
    file.write(reinterpret_cast<const char*>(&data_chunk_size), 4);

    for (float sample : audio_data){
        if (sample > 1.0f){sample = 1.0f;}
        if (sample < -1.0f){sample = -1.0f;}
    
        // scale to 16bit integersL
        int16_t p = static_cast<int16_t>(sample * 32767.0f);
        file.write(reinterpret_cast<const char*>(&p), 2);
    
    }

    file.close();
    cout<< "Saved successfully: " << filename << endl;

    return;
}

// 
vector<float> import_wav(){}


vector<float> generate_sin(float amplitude, float freq, float rate, float dur){
    vector<float> data;
    constexpr double pi = acos(-1.0); 
    for(int i = 0; i < (rate*dur); i++){
        float a = amplitude * sin((2 * pi * freq) * (i/rate));
        data.push_back(a);
    }
    return data;
}

int main(){

    // vector<float> test = generate_sin(0.5, 100, 44000, 4);
    // export_wav("test.wav", test);

}
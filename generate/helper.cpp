#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <algorithm>
using namespace std;
constexpr double pi = acos(-1.0); 

void process_range(vector<float> &audio_data, float amp = 1){

    if(audio_data.empty()){
        cout<< "process_range: audio data empty"<<endl;    
        return;
    }

    float max_val = 0;

    for (float num : audio_data) {
        if (-1 * num > max_val) {
            max_val = -1 * num;
        }
        if (num > max_val) {
            max_val = num;
        }
    }

    //division by 0:
    if(max_val == 0) { cout<<"0 audio data";  return;}

    for(float& num: audio_data){
        num = num * amp / max_val;
    }

    cout<< "range processing success"<<endl;
     

    return ;
}
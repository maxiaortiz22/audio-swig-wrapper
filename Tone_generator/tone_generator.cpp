#define _USE_MATH_DEFINES
#include <cmath>
#include "tone_generator.h"

// Struct of the tone generator, allocation and deallocation of its parameters.
struct tone_gen {
    int sampleRate;
    int frequency;
    float amplitude;
};

static struct tone_gen *pToneGen;
extern float *data;

void tone_generator_values(int sr, int freq, float amp) {
    if (pToneGen == NULL) {
        pToneGen = new tone_gen();
    }

    pToneGen->sampleRate = sr;
    pToneGen->frequency = freq;
    pToneGen->amplitude = amp;

}

void tone_generator_free() {
    if (pToneGen == NULL) {
        return;
    }
    free(pToneGen);
    pToneGen = NULL;
}

//Define the implementations of the ToneGenerator class:
ToneGenerator::ToneGenerator(int freq, float amp, int sr) : frequency(freq), amplitude(amp), sampleRate(sr) {
    offset = 2 * M_PI * (float) frequency / (float) sampleRate;
}

float ToneGenerator::getSample() {
    float sample = amplitude * sin(angle);
    angle += offset;
    return sample;
}

//Generating the tone:
void generateContinuousTone(float* data, int buffer_size){
    int freq = pToneGen->frequency;
    int sampleRate = pToneGen->sampleRate;
    float amp = pToneGen->amplitude;

    ToneGenerator toneGenerator(freq, amp, sampleRate);

    //main working loop:
    for (int i = 0; i < buffer_size; i += 1) {
        float sample = toneGenerator.getSample();
        data[i] = sample;
    }
}
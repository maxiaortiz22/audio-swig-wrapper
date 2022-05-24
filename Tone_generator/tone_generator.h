//Tone generator implementations:
void tone_generator_values(int sr, int freq, float amp);
void generateContinuousTone(float* data,int buffer_size);
void tone_generator_free();

//ToneGenerator class:

#ifndef TONEGENERATOR_H
#define TONEGENERATOR_H


class ToneGenerator {
    int frequency, sampleRate;
    float angle = 0.0, offset = 0.0, amplitude;

public:

    ToneGenerator(int freq, float amp, int sr);
    float getSample();

};

#endif

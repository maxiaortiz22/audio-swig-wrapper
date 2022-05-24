import tone_generator
import sounddevice as sd
import numpy as np

SR = 48000 #Sample rate
AMP = 1 #Amplitude
FREQ = 1000 #Frequency

buffer = 2*SR

tone_generator.tone_generator_values(SR, FREQ, AMP)

data = tone_generator.generateContinuousTone(buffer)

sd.play(data, SR)
sd.wait()

tone_generator.tone_generator_free()
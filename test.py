import tone_generator
import sounddevice as sd
import numpy as np
import soundfile as sf

SR = 48000 #Sample rate
AMP = 1 #Amplitude
FREQ_1 = 1000 #Frequency
FREQ_2 = 1003 #Frequency
SECONDS = 2

total_samples = SECONDS*SR
buffer = 256

tone_1 = tone_generator.ToneGenerator(FREQ_1, AMP, SR) #Instancio la clase
tone_2 = tone_generator.ToneGenerator(FREQ_2, AMP, SR) #Instancio la clase

audio_1, audio_2 = [], []
for i in range(int(total_samples/buffer)):
    data_1 = tone_1.generateContinuousTone(buffer)
    data_2 = tone_2.generateContinuousTone(buffer)

    audio_1.extend(data_1)
    audio_2.extend(data_2)

audio_1 = np.array(audio_1)
audio_2 = np.array(audio_2)

audio = (audio_1+audio_2)/np.max(np.abs(audio_1+audio_2))

sd.play(audio, SR)
sd.wait()

sf.write('test.wav', audio, SR)

tone_1.tone_generator_free()
tone_2.tone_generator_free()
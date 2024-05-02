#include "olcNoiseMaker.h"
#include "sound_engine.h"
#include <iostream>
#include <vector>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <cstring>

//dawanie wartosci oscillatorom








Keys Key0;
Keys Key1;
Keys Key2;
Keys Key3;
Keys Key4;
Keys Key5;
Keys Key6;
Keys Key7;
Keys Key8;
Keys Key9;
Keys Key10;
Keys Key11;
Keys Key12;
Keys Key13;
Keys Key14;

{
 Key0,
 Key1,
 Key2,
 Key3,
 Key4,
 Key5,
 Key6,
 Key7,
 Key8,
 Key9,
 Key10,
 Key11,
 Key12,
 Key13,
 Key14,

};


void getSound(int index)
{





	for (int i = 0; i < 14; i++) {

		if (index == i) {
			Klawiatura[i].keyPressed = true;
		}
		else {
			Klawiatura[i].keyPressed = false;
		}

	}
}


note num0;
note num1;
note num2;
note num3;
note num4;
note num5;
note num6;
note num7;
note num8;
note num9;
note num10;
note num11;
note num12;
note num13;
note num14;

note Notes[20] {
 num0,
 num1,
 num2,
 num3,
 num4,
 num5,
 num6,
 num7,
 num8,
 num9,
 num10,
 num11,
 num12,
 num13,
 num14,
};






double MakeNoise(double dTime) {


	double masterVolume = 0.2;
	double dOutput = 0.0;

	for (int q = 0; q < 15; q++) {

		if (GetAsyncKeyState((unsigned char)("ZSXCFVGBNJMK\xbcL\xbe\xbf"[q])) && 0x8000) {

			if (!Notes[q].active) {
				Notes[q].active = true;
				Notes[q].last_on = Notes[q].on;
				Notes[q].on = dTime;
				cout << q << endl;

			};

			dFrequencyOutput1 = dOctaveBaseFrequency * pow(d12thRootOf2, q + oscillator1.osc1.pitch);
			dFrequencyOutput2 = dOctaveBaseFrequency * pow(d12thRootOf2, q + oscillator1.osc2.pitch);
			dFrequencyOutput3 = dOctaveBaseFrequency * pow(d12thRootOf2, q + oscillator1.osc3.pitch);
			if (env.amplitude(dTime, Notes[q].on, Notes[q].off) != 0) {
				dOutput += env.amplitude(dTime, Notes[q].on, Notes[q].off) *
					(
						+oscillator1.osc1.loudness * synt.osc(dTime, dFrequencyOutput1, oscillator1.osc1.waveShape)
						+ oscillator1.osc2.loudness * synt.osc(dTime, dFrequencyOutput2, oscillator1.osc2.waveShape)
						+ oscillator1.osc3.loudness * synt.osc(dTime, dFrequencyOutput3, oscillator1.osc3.waveShape)
						);
			}
		}
		else {
			if (Notes[q].active) {
				Notes[q].active = false;
				Notes[q].off = dTime;

				QueInfo temp;
				temp.q = q;
				temp.on = Notes[q].on;
				temp.off = Notes[q].off;

				kolejka.insert(kolejka.begin(), temp);

			}
		};
	}

	for (int i = kolejka.size() - 1; i >= 0; i--) {

		if (dTime - kolejka[i].off >= env.dReleaseTime) {

			kolejka.erase(kolejka.begin() + i);

		}
		else {
			dFrequencyOutput1 = dOctaveBaseFrequency * pow(d12thRootOf2, kolejka[i].q + oscillator1.osc1.pitch);
			dFrequencyOutput2 = dOctaveBaseFrequency * pow(d12thRootOf2, kolejka[i].q + oscillator1.osc2.pitch);
			dFrequencyOutput3 = dOctaveBaseFrequency * pow(d12thRootOf2, kolejka[i].q + oscillator1.osc3.pitch);



			if (env.amplitude(dTime, kolejka[i].on, kolejka[i].off) != 0) {

				dOutput += env.amplitude(dTime, kolejka[i].on, kolejka[i].off) *

					(
						+oscillator1.osc1.loudness * synt.osc(dTime, dFrequencyOutput1, oscillator1.osc1.waveShape)
						+ oscillator1.osc2.loudness * synt.osc(dTime, dFrequencyOutput2, oscillator1.osc2.waveShape)
						+ oscillator1.osc3.loudness * synt.osc(dTime, dFrequencyOutput3, oscillator1.osc3.waveShape)
						);
			}
		}
	}
	return dOutput * masterVolume;
};

int main()
{






	int index = 0;

	while (1)
	{
		
		//ten warunek jest tutaj zeby polaczyc z nutami z linii czasu, w sensie on nie bedzie tutaj tylko u ciebie jakkolwiek dodjaesz te nuty
		//na razie jest ustawione na klikanie klawiatury
		int q = 0;

			if (1) {
				index = q;
				getSound(index);
			
			}
			else {
				index = -1;
				getSound(index);
			}
		}

		



}

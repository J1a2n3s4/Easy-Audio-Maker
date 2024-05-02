#include "olcNoiseMaker.h"

using namespace std;

class QueInfo {

public:
	int q;
	double off;
	double on;

};



class Keys {

public:
	bool keyPressed = false;

};
struct note
{
	int nType;
	double on;
	double last_on;
	double last_off;
	double off;
	bool active;
	bool flag;

	note()
		{
			nType = 0;
			on = 0.0;
			off = 0.0;
			active = false;
		 last_on=0.0;
			flag=false;
		}


};


struct oscillator
{
	double loudness;
	int waveShape;
	double attackValue;
	double releaseValue;
	int pitch;
	oscillator() {
		loudness = 0;
		waveShape = 0;
		pitch=0;
	}
};
struct preset_sound
{
	oscillator osc1;
	oscillator osc2;
	oscillator osc3;
	
};

struct envelope_adsr {
	double dAttackTime;
	double dReleaseTime;
	double dStartAmplitude;

	envelope_adsr()
		{
			dAttackTime = 0.2;
			dReleaseTime = 0.5;
			dStartAmplitude = 1.0;
		}


	

	double amplitude(const double dTime, const double dTimeOn, const double dTimeOff)
	 {

			double dAmplitude = 0.0;
			double dReleaseAmplitude = 0.0;

			if (dTimeOn > dTimeOff) 
			{

		
				double dLifeTime = dTime - dTimeOn;

				if (dLifeTime <= dAttackTime)
					dAmplitude = (dLifeTime / dAttackTime) * dStartAmplitude;

				if (dLifeTime > dAttackTime)
					dAmplitude =dStartAmplitude;

			}
			else 
			{
				double dLifeTime = dTimeOff - dTimeOn;

				if (dLifeTime <= dAttackTime)
					dReleaseAmplitude = (dLifeTime / dAttackTime) * dStartAmplitude;

				if (dLifeTime > dAttackTime )
					dReleaseAmplitude = dStartAmplitude;

				dAmplitude = ((dTime - dTimeOff) / dReleaseTime) * (0.0 - dReleaseAmplitude) + dReleaseAmplitude;
			}

			
			if (dAmplitude <= 0.000)
				dAmplitude = 0.0;

			return dAmplitude;
		}
	};



class synth
{

public:
	const double PI = 3.141592653589793238462643383279502884197;
	double osc(const double dTime, const double dHertz, const int nType = 0);
	double scale(const int nNote);
	double translate_fq(const double dHertz);
	double PassDTime(double dTime);
	double PassNType(int nType);

	


};
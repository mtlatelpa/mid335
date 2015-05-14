//Miguel Tlatelpa
//CMPS 335
//mid335.cpp
//
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

//frequency definitions
#define A4 440.0
#define F0 A4
#define F0_note A
#define F0_octave 4

typedef enum {
	C = 1,
	Cs,
	D,
	Ds,
	E,
	F,
	Fs,
	G,
	Gs,
	A,
	As,
	B,
	Z,
	END = Z,
	HALF_STEPS_PER_OCTAVE = Z
} note_t;

float notes[] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0};
float result[] = {16.35, 17.32, 18.35, 19.45, 20.6, 21.83, 23.12, 24.5, 25.96, 27.5, 29.14, 30.87, 32.7, 34.65, 36.71, 38.89, 41.2};
float freq(note_t note, int octave_delta);
const float tolerance = .004;

int main(int argc, char *argv[])
{
	note_t note;
	int octave_delta;
	if (argc != 4) {
		cout << "Usage: " << argv[0] << " <NOTE>  <OCTAVE_DELTA>" << endl;
		return 0;
	}
	
	note = (note_t)(toupper(argv[1][0]) - 64);
	switch(toupper(argv[1][0])) {
		case 'A': note = A; break;
		case 'B': note = B; break;
		case 'C': note = C; break;
		case 'D': note = D; break;
		case 'E': note = E; break;
		case 'F': note = F; break;
	}
	//You may call your unit test here...
	
	
	if (note > END) {
		cout << "Invalid note!" << endl;
		return 1;
	}
	octave_delta = atoi(argv[2]);
	cout << HALF_STEPS_PER_OCTAVE << endl;
	cout << freq(note, octave_delta) << endl;
	cout << endl;
	
	cout << "tolerance: " << tolerance << endl;
	cout << "freq function unit-test" << endl << endl;
	
	cout << "note octave value   diff" << endl;
	cout << "---- ------ ------- ----------" << endl;
	
	float ret = freq(note, octave_delta);
	float diff = ret - result[note];
	diff = fabs(diff);
	cout << " " << note << "    " << octave_delta << "    " << freq(note, octave_delta) << "  " << diff;
	if (diff < tolerance)
		cout << "     good" << endl;
	else
		cout << "  <------- bad" << endl;
	
/*	if (note == 'Z' && octave_delta == 0) {	
		for (int i = 0; i > 13; i++) {
			float ret = freq(note, octave_delta);
			float diff = ret - result[0];
			diff = fabs(diff);
			cout << " " << note << "    " << octave_delta << "    " << freq(note, octave_delta) << "  " << diff;
			if (diff < tolerance)
				cout << "     good" << endl;
			else
				cout << "  <------- bad" << endl;
		}
	}
*/

	cout << endl;
	return 0;
}

//-----------------------------------------------------------
//Generate a frequency in hz that is half_steps away from C_4
//Do not modify this function.
//-----------------------------------------------------------
float freq(note_t note, int octave_delta) 
{
	float freq;
	float factor;
	float a;
	int n;
	int octave = octave_delta - F0_octave;

	a = pow(2.0, 1.0/(float)HALF_STEPS_PER_OCTAVE);
	n = note - F0_note;
	freq = F0 * pow(a, (float)n);
	factor = pow(2.0, (float)octave);
	freq = freq * factor;
	return freq;
}

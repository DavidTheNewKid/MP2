// main.cpp : Defines the entry point for the console application.

/*
________________________________________________________________________________
								
								Headers
________________________________________________________________________________
*/

/*
________________________________________________________________________________
							System Defined Headers
*/

// Headers needed for compilation
#include "stdafx.h"
#include <iterator>
#include <map>
#include <math.h>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include "systemc.h"

/*
________________________________________________________________________________
							User Defined Headers
*/

// Headers needed for all of the gates made in MP2
#include "not.h" // NOT gate, also the highest priority gate
#include "gates_2.h" // AND and OR 2 input gates
#include "gates_3.h" // AND and OR 3 input gates
#include "gates_5.h" // AND and OR  5input gates
#include "nands.h" // NAND gates
#include "xors.h" // XOR gates, also the lowest priority gate
#include "encoder42.h"
#include "decoder24.h"
#include "SN74145.h"
#include "demux14.h"
#include "mux81.h"
#include "mux41.h"

// Headers needed to control binary in test benches		
#include "binarycontrol.h"
#include "dutcontrol.h"

/*
________________________________________________________________________________
*/

/*
________________________________________________________________________________
						
						Begin the Main Test Bench Program
________________________________________________________________________________
*/

int sc_main(int argc, char* argv[])
{

	/*
	________________________________________________________________________________
			Variables for Testbenching (only variables that need to be changed)	
	*/

	
	// Need to be changed for test benches
	const int O_BITS = 10; // # of output bits
	const int BITS = 4; // # of bits
	const char GATE_NAME[] = "SN74145_b"; // current gate name
	SN74145_b DUT(GATE_NAME);
	const int E_EXISTS = 0; // 0 = Enable bit does not exist, 1 = Enable bit does exist


	/*
	________________________________________________________________________________
	*/


	/*
	________________________________________________________________________________

						Begin Unchanging Test Bench Variables
	________________________________________________________________________________
	*/


	/*
	________________________________________________________________________________
	*/

	//					 Variables for building input strings

	const std::string input_begin = "i("; // begins string with "i("
	const char input_end = ')'; // after integer is added into input_beging, this variable ends the string (i.e "i(1" + input_end = "i(1)")

	std::string input_string; // Final input string (i.e. "i(6)" for input 6)

	std::string output_string = "F_ARR"; // Final output string

	/*
	________________________________________________________________________________
	*/

	//					Variables for storing signal values
	
	sc_signal<bool> i[BITS]; // array of temporary input signal variables
	sc_signal<bool> F; // temporary output signal variable'
	sc_signal<bool> e_i; // temporary enable variable (if it exists)
	sc_signal<sc_lv<O_BITS>> F_ARR;
	
	bool temp_inputs[BITS]; // Array of all the bit values for the temporary input signal variables

	/*
	________________________________________________________________________________
	*/

	//								Counters

	int current_bit = 0; // counts through entire bit stream
	int current_E = 0;
	int counter = 0; // generic counter
	
	/*
	________________________________________________________________________________
	*/

	//					Variable for computating overflow

	int max_bits = static_cast<int>(ceil(pow(2, BITS) - 1.0)); // Finds max int number for number of bits (2^(n)-1)



	/*
	________________________________________________________________________________
	*/
	//					Begin filtering test variables to their gates
	
	
	// Sets input variables for Device Under Testing to variables in test the test input signal array
	for (counter = 0; counter < BITS; counter++)
	{
		DUT.i[counter](i[counter]);
	}

	// Links outputs to current device under testing
	dutcontrol(DUT, F_ARR, F, e_i);

	// Begins tracing
	sc_trace_file *fp1;

	// Creates VCD file that is the same name as the gate
	fp1 = sc_create_vcd_trace_file(GATE_NAME);

	// Links test input array to fp1
	for (counter = 0; counter < BITS; counter++)
	{
		input_string = input_begin;
		input_string += ('0' + counter);
		input_string += input_end;
		sc_trace(fp1, i[counter], input_string);
	}

	if (E_EXISTS)
	{
		sc_trace(fp1, e_i, "E");
	}

	// Links test outputs/output to fp1
	if (O_BITS <= 1)
	{
		sc_trace(fp1, F, "F");
	}
	else
	{
		sc_trace(fp1, F_ARR, output_string);
	}


	// Loops through all possible binary numbers for the number of inputs
	
	if (E_EXISTS)
	{
		for (current_E = 0; current_E <= 1; current_E++)
		{
			e_i = current_E;
			for (counter = 0; counter <= max_bits; counter++)
			{
				// Converts counter number to corresponding bit array (i.e. (BITS =2 and counter = 3) then temp_inputs = [1,1]
				int_to_binary_arr(temp_inputs, BITS, counter);
				for (current_bit = 0; current_bit < BITS; current_bit++)
				{
					i[current_bit] = temp_inputs[current_bit];
				}
				// Sends current data to gate to begin tracing
				sc_start(100, SC_NS);
			}
		}
	} 
	else
	{
		for (counter = 0; counter <= max_bits; counter++)
		{
			// Converts counter number to corresponding bit array (i.e. (BITS =2 and counter = 3) then temp_inputs = [1,1]
			int_to_binary_arr(temp_inputs, BITS, counter);
			for (current_bit = 0; current_bit < BITS; current_bit++)
			{
				i[current_bit] = temp_inputs[current_bit];
			}
			// Sends current data to gate to begin tracing
			sc_start(100, SC_NS);
		}
	}

	// Blanks input
	for (current_bit = 0; current_bit < BITS; current_bit++)
	{
		i[current_bit] = 0;
	}
	// Takes the blanked input and traces to make gate display correctly in a wave modeling program
	sc_start(100, SC_NS);

	// Closes files
	sc_close_vcd_trace_file(fp1);

	// Waits for user to end the program (for testing runs only, to get errors)
	cin >> current_bit;

	return 0;
}

/*
________________________________________________________________________________
						
							End of Main Test Bench File
________________________________________________________________________________
*/
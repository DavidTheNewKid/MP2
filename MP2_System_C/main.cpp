// template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iterator>
#include <math.h>
#include <cmath>
#include <string>
#include <iostream> // for debugging purposes
#include "not.h"
#include "gates_2.h"
#include "gates_3.h"
#include "gates_5.h"
#include "nands.h"
#include "xors.h"
#include "binarycontrol.h"


int sc_main(int argc, char* argv[])
{

	// Need to be changed for test benches
	const int BITS = 5; // # of bits
	const char GATE_NAME[] = "nand5_c"; // current gate name
	nand3_c DUT(GATE_NAME); // gate variable using current gate name (GATE_NAME)

	// constants for building input strings "i(#)"
	const std::string input_begin = "i(";
	const char input_end = ')';

	// Built input string i.e. i(1) for input 1
	std::string input_string;

	// System C temp signals
	sc_signal<bool> i[BITS]; // inputs
	sc_signal<bool> F; // output
	
	// Temporary inputs for number of bits to loop through in the test bench
	bool temp_inputs[BITS];

	// Counters
	int current_bit = 0; // counts through entire bit stream
	int counter = 0; // generic counter
	 
	int max_bits = static_cast<int>(ceil(pow(2, BITS) - 1.0)); // Finds max int number for number of bits (2^(n)-1)


	// Sets input variables for Device Under Testing to variables in test the test input signal array
	for (counter = 0; counter < BITS; counter++)
	{
		DUT.i[counter](i[counter]);
	}

	// Sets output variable to test output signal variable
	DUT.F(F);

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

	// Links test output variable to fp1
	sc_trace(fp1, F, "F");

	// Loops through all possible binary numbers for the number of inputs
	for (counter = 0; counter <= max_bits; counter++)
	{
		// Converts counter number to corresponding bit array (i.e. (BITS =2 and counter = 3) then temp_inputs = [1,1]
		int_to_binary_arr(temp_inputs, BITS, counter);
		for (current_bit = 0; current_bit < BITS; current_bit++)
		{
			i[current_bit] = temp_inputs[current_bit];
		}
		// sends current data to gate to begin tracing
		sc_start(100, SC_NS);
	}

	// blanks input
	for (current_bit = 0; current_bit < BITS; current_bit++)
	{
		i[current_bit] = 0;
	}
	// takes the blanked input and traces to make gate display correctly in a wave modeling program
	sc_start(100, SC_NS);

	// Closes files
	sc_close_vcd_trace_file(fp1);

	// Waits for user to end the program (for testing runs only, to get errors)
	// cin >> current_bit;

	return 0;
}

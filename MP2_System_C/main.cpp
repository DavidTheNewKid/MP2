// template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iterator>
#include <math.h>
#include <cmath>
#include <string>
#include <iostream> // for debugging purposes
#include "gates_2.h"
#include "gates_3.h"
#include "binarycontrol.h"


int sc_main(int argc, char* argv[])
{

	const int BITS = 3;
	const char GATE_NAME[] = "and2";

	sc_signal<bool> i[BITS];
	sc_signal<bool> F;
	
	bool temp_inputs[BITS];

	int current_bit = 0;

	int max_bits = static_cast<int>(ceil(pow(2, BITS) - 1.0));

	and2 DUT(GATE_NAME);

	DUT.i[0](i[0]);
	DUT.i[1](i[1]);
	DUT.F(F);

	sc_trace_file *fp1;

	fp1 = sc_create_vcd_trace_file(GATE_NAME);

	sc_trace(fp1, i[0], "i(0)");
	sc_trace(fp1, i[1], "i(1)");
	sc_trace(fp1, F, "F");

	for (int counter = 0; counter <= max_bits; counter++)
	{
		int_to_binary_arr(temp_inputs, BITS, counter);
		for (current_bit = 0; current_bit < BITS; current_bit++)
		{
			i[current_bit] = temp_inputs[current_bit];
		}
		sc_start(100, SC_NS);
	}

	for (current_bit = 0; current_bit < BITS; current_bit++)
	{
		i[current_bit] = 0;
	}

	sc_start(100, SC_NS);

	sc_close_vcd_trace_file(fp1);

	cin >> current_bit;

	return 0;
}

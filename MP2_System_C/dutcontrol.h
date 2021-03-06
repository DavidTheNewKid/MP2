#pragma once

void dutcontrol(not1 & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

// 2 Input Gate Devices Under Testing

void dutcontrol(and2 & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(or2 & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(or2_c & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(or2_sc & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

// 3 Input Gate Devices Under Testing

void dutcontrol(and3 & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(or3 & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(or3_c & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(or3_sc & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

// 5 Input Gate Devices Under Testing

void dutcontrol(and5 & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(or5 & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(or5_c & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(or5_sc & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

// nand Devices Under Testing
void dutcontrol(nand2 & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(nand2_c & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(nand3 & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(nand3_c & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(nand3_sc & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(nand5 & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(nand5_c & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(nand5_sc & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

// XOR Devices Under Testing
void dutcontrol(xor2 & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(xor2_c & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(xor3 & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(xor3_c & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(xor3_sc & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(xor5 & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(xor5_c & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

void dutcontrol(xor5_sc & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F(F);
	return;
}

// Encoder Devices Under Testing

void dutcontrol(encoder42 & DUT, sc_signal<sc_lv<2>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F_ARR(F_ARR);
	return;
}

void dutcontrol(encoder42_b & DUT, sc_signal<sc_lv<2>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F_ARR(F_ARR);
	return;
}

// Decoder Devices Under Testing

void dutcontrol(decoder24 & DUT, sc_signal<sc_lv<4>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.E(E);
	DUT.F_ARR(F_ARR);
	return;
}

void dutcontrol(decoder24_b & DUT, sc_signal<sc_lv<4>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.E(E);
	DUT.F_ARR(F_ARR);
	return;
}

// Demux Devices Under Testing

void dutcontrol(demux14_b & DUT, sc_signal<sc_lv<4>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.E(E);
	DUT.F_ARR(F_ARR);
	return;
}

// Mux Devices Under Testing

void dutcontrol(mux41_b & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.E(E);
	DUT.F_ARR(F_ARR);
	return;
}

void dutcontrol(mux81_b & DUT, sc_signal<sc_lv<1>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.E(E);
	DUT.F_ARR(F_ARR);
	return;
}

// SN74145

void dutcontrol(SN74145_b & DUT, sc_signal<sc_lv<10>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F_ARR(F_ARR);
	return;
}

void dutcontrol(SN74145_spc & DUT, sc_signal<sc_lv<10>> & F_ARR, sc_signal<bool> & F, sc_signal<bool> & E)
{
	DUT.F_ARR(F_ARR);
	return;
}

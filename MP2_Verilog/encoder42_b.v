module encoder42_b(
input i1, // input 1
input i2, // input 2
input i3, // input 3
input i4, // input 4
output[1:0] o // output 2
);

assign o = 	i4 ? 2'b11:
			i3 ? 2'b10:
			12 ? 2'b01:
			2'b00;
endmodule

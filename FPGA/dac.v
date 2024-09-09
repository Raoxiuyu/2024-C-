module dac (
    clk,
    dac_clk,
    da_out,
	 data_in,
);

input  wire clk;
output wire dac_clk;
output reg [13:0] da_out;
input wire [13:0] data_in;

assign dac_clk=clk;

always @(posedge clk) begin
	da_out[12:0]<=data_in[12:0];
	da_out[13]<=~data_in[13];
end

endmodule
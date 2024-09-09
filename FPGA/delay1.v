module delay1(
	 clk,
    data_in,
	 data_out
);

output reg [13:0] data_out;
input wire [13:0] data_in;
input wire clk;

always @(posedge clk) begin
	data_out<=data_in;
end

endmodule
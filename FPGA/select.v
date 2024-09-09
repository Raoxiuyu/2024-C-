module select (
	 sel,
    data_in1,
	 data_in2,
	 data_out
);

output reg [13:0] data_out;
input wire [13:0] data_in1;
input wire [14:0] data_in2;
input wire sel;

always @(*) begin
	if(!sel) begin
		data_out[13:0]=data_in1[13:0];
	end
	else begin
		data_out[13:0]={data_in2[14],data_in2[12:0]};
	end
end

endmodule
module dds (
    clk,
    rstn,
    Fword,
    Pword,
	 sin_out
);

input  wire clk,rstn;
output reg [13:0] sin_out;
input wire [31:0] Fword;
input wire [7:0] Pword;

//2M=32'D 107374182
//40M=32'H 80000000
//32'D 1717986918;
//32'D 1374389535;


wire [13:0] wave_data;
reg [31:0] Fcnt;
wire [7:0] rom_addr;


always @(posedge clk or negedge rstn) begin
    if (!rstn) begin
        Fcnt<=32'b 0;
    end
    else
        Fcnt<=Fcnt+Fword;
end

assign rom_addr=Fcnt[31:24]+Pword[7:0];
assign dac_clk=clk;

romsin mysin(
    .address(rom_addr),
    .clock(clk),
    .q(wave_data)
);

always @(posedge clk) begin
    sin_out[13:0]<=wave_data[13:0];
end

endmodule //dds
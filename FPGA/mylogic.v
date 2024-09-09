module mylogic(
	input en,
	input [2:0] sel,
	input [7:0] data,
	output reg [7:0] coe_a,
	output reg [2:0] delay,
	output reg [31:0] freqWord_1,
	output reg [7:0] phaseWord_1,
	output reg [7:0] dac1_coe,
	output reg [7:0] dac2_coe
);

	reg [7:0] coe_a_tmp;
	reg [2:0] delay_tmp;
	reg [31:0] freqWord_1_tmp;
	reg [7:0] phaseWord_1_tmp;
	reg [7:0] dac1_coe_tmp;
	reg [7:0] dac2_coe_tmp;

	always @(*)
		if(en==1'b0) begin
			case(sel)
				3'b001: begin	// Ma 30%~90% 10% step
					case (data[3:0])
						4'b0000: begin
							coe_a_tmp = 8'd39;
						end
						4'b0001: begin
							coe_a_tmp = 8'd51;
						end
						4'b0010: begin
							coe_a_tmp = 8'd64;
						end
						4'b0011: begin
							coe_a_tmp = 8'd77;
						end
						4'b0100: begin
							coe_a_tmp = 8'd90;
						end
						4'b0101: begin
							coe_a_tmp = 8'd103;
						end
						4'b0110: begin
							coe_a_tmp = 8'd115;
						end
						default: begin
							coe_a_tmp = 8'd115;    // default
						end
					endcase
				end
				3'b010: begin	// Sm Delay 50~200ns 30ns step
					case (data[3:0])
						4'b0000: begin	// 50ns
							delay_tmp = 3'b000;
						end
						4'b0001: begin	// 80ns
							delay_tmp = 3'b001;
						end
						4'b0010: begin	// 110ns
							delay_tmp = 3'b010;
						end
						4'b0011: begin	// 140ns
							delay_tmp = 3'b011;
						end
						4'b0100: begin	// 170ns
							delay_tmp = 3'b100;
						end
						4'b0101: begin	// 200ns
							delay_tmp = 3'b101;
						end
						default: begin
							delay_tmp = 3'b000;    // default to 50ns
						end
					endcase
				end
				3'b011: begin	// fc 30~40M 1MHz step
					case (data[3:0])
						4'b0000: begin
							freqWord_1_tmp = 32'd1030792151;
						end
						4'b0001: begin
							freqWord_1_tmp = 32'd1065151889;
						end
						4'b0010: begin
							freqWord_1_tmp = 32'd1099511628;
						end
						4'b0011: begin
							freqWord_1_tmp = 32'd1133871366;
						end
						4'b0100: begin
							freqWord_1_tmp = 32'd1168231105;
						end
						4'b0101: begin
							freqWord_1_tmp = 32'd1202590843;
						end
						4'b0110: begin
							freqWord_1_tmp = 32'd1236950581;
						end
						4'b0111: begin
							freqWord_1_tmp = 32'd1271310320;
						end
						4'b1000: begin
							freqWord_1_tmp = 32'd1305670058;
						end
						4'b1001: begin
							freqWord_1_tmp = 32'd1340029796;
						end
						4'b1010: begin
							freqWord_1_tmp = 32'd1374389535
;
						end
						default: begin
							freqWord_1_tmp = 32'd1030792151;    // default
						end
					endcase
				end
				3'b100: begin	// Sm Phase 0~180deg 30deg step
					case (data[3:0])
						4'b0000: begin
							phaseWord_1_tmp = 8'd0;
						end
						4'b0001: begin
							phaseWord_1_tmp = 8'd21;
						end
						4'b0010: begin
							phaseWord_1_tmp = 8'd43;
						end
						4'b0011: begin
							phaseWord_1_tmp = 8'd64;
						end
						4'b0100: begin
							phaseWord_1_tmp = 8'd85;
						end
						4'b0101: begin
							phaseWord_1_tmp = 8'd107;
						end
						4'b0110: begin
							phaseWord_1_tmp = 8'd128;
						end
						default: begin
							phaseWord_1_tmp = 8'd0;   // default
						end
					endcase
				end
				3'b101: begin	
					dac1_coe_tmp=data;
				end
				3'b110: begin	
					dac2_coe_tmp=data;
				end
			endcase
			phaseWord_1=phaseWord_1;
			delay=delay;
			coe_a=coe_a;
			freqWord_1=freqWord_1;
			dac1_coe_tmp=dac1_coe_tmp;
			dac2_coe_tmp=dac2_coe_tmp;
		end
		else begin
			phaseWord_1=phaseWord_1_tmp;
			delay=delay_tmp;
         coe_a=coe_a_tmp;
			freqWord_1=freqWord_1_tmp;
			dac1_coe=dac1_coe_tmp;
			dac2_coe=dac2_coe_tmp;
		end
endmodule
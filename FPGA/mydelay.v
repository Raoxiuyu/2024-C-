module mydelay (
    clk,
	 rstn,
	 delay_sel,
    data_out,
	 data_in,
);

input  wire clk;
input  wire rstn;
input  wire[2:0] delay_sel;
output reg [13:0] data_out;
input wire [13:0] data_in;

reg[13:0] register_array[24];
integer i;

 // 在时钟上升沿和复位信号无效时，更新寄存器数组
 always @(posedge clk or negedge rstn) begin
	  if (!rstn) begin
			// 复位寄存器数组
			for (i = 0; i < 24; i = i + 1) begin
				 register_array[i] <= 12'b0;
			end
	  end else begin
			// 正常操作，将数据输入到数组的第一个寄存器
			// 并将数组中的数据向右移动
			for (i = 23; i > 0; i = i - 1) begin
				 register_array[i] <= register_array[i - 1];
			end
			register_array[0] <= data_in;
	  end
 end
 
 // 将最后一个寄存器的值输出
 always@(*) begin
	case (delay_sel)
		3'b000: begin	// 50ns
			data_out = register_array[4];
		end
		3'b001: begin	// 80ns
			data_out = register_array[8];
		end
		3'b010: begin	// 110ns
			data_out = register_array[12];
		end
		3'b011: begin	// 140ns
			data_out = register_array[16];
		end
		3'b100: begin	// 170ns
			data_out = register_array[19];
		end
		3'b101: begin	// 200ns
			data_out = register_array[23];
		end
		default: begin
			data_out = register_array[4];
		end
	endcase
 end

endmodule
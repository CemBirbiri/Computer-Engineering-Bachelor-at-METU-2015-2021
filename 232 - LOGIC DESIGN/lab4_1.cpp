`timescale 1ns / 1ps
module MaskROM (input [3:0] RomAddress, output reg[7:0] RomDataOut);
/*  Please write your code below  */

	always@(RomAddress) begin //clk olmadigi icin bunu yaptik
		if( RomAddress==4'b0000)  begin  RomDataOut=8'b00000000; end //0
		else if( RomAddress==4'b0001)  begin  RomDataOut=8'b00001111; end //1
		else if( RomAddress==4'b0010)  begin  RomDataOut=8'b00011110; end //2
		else if( RomAddress==4'b0011)  begin  RomDataOut=8'b00110000; end //3
		else if( RomAddress==4'b0100)  begin  RomDataOut=8'b01010000; end //4
		else if( RomAddress==4'b0101)  begin  RomDataOut=8'b01100110; end //5
		else if( RomAddress==4'b0110)  begin  RomDataOut=8'b01101010; end //6
		else if( RomAddress==4'b0111)  begin  RomDataOut=8'b01111110; end //7
		else if( RomAddress==4'b1000)  begin  RomDataOut=8'b10000001; end //8
		else if( RomAddress==4'b1001)  begin  RomDataOut=8'b10100000; end //9
		else if( RomAddress==4'b1010)  begin  RomDataOut=8'b10100110; end //10
		else if( RomAddress==4'b1011)  begin  RomDataOut=8'b10111101; end //11
		else if( RomAddress==4'b1100)  begin  RomDataOut=8'b11000000; end //12
		else if( RomAddress==4'b1101)  begin  RomDataOut=8'b11010000; end //13
		else if( RomAddress==4'b1110)  begin  RomDataOut=8'b11010011; end //14
		else begin   RomDataOut=8'b11100110; end //15


	end //'
	
/*  Please write your code above  */
endmodule


/*mode 0:read, 1:write*/																							
module RgbRAM ( input Mode,
				input [3:0] RamAddress, 
				input [23:0] RamDataIn,
				input [7:0] Mask,
				input [2:0] Op, 
				input CLK, 
				output reg [23:0] RamDataOut);


/*  Please write your code below  */
//*************************************************************************************************
reg [23:0] myArray [15:0];
reg [7:0] temp1;
reg [7:0] temp2;
reg [7:0] temp3;
integer int1;
integer int2;
integer int3;

//myArray[ramAddress][8]=1;
//***Initially, the values of all RAM registers will be 0 .
initial begin
	RamDataOut=0;
	myArray[0]=0; myArray[1]=0;myArray[2]=0; myArray[3]=0;myArray[4]=0; myArray[5]=0;
	myArray[6]=0; myArray[7]=0;myArray[8]=0; myArray[9]=0;myArray[10]=0; myArray[11]=0;
	myArray[12]=0; myArray[13]=0;myArray[14]=0; myArray[15]=0;

	temp1=0;
	temp2=0;
	temp3=0;
	int1=0;
	int2=0;
	int3=0;


end
	always@(posedge CLK)begin

		if(mode==1) begin
			if(op==3'b000)begin //AND'
				temp1 = RamDataIn[23:16] & Mask ;
				 temp2 = RamDataIn[15:8] & Mask ;
				 temp3 = RamDataIn[7:0] & Mask ;

				myArray[RamAddress][23:16]=temp1;
				myArray[RamAddress][15:8]=temp2;
				myArray[RamAddress][7:0]=temp3;


				end //
			else if(op==3'b001)begin //OR'
				 temp1 = RamDataIn[23:16] | Mask ;
				 temp2 = RamDataIn[15:8] | Mask ;
				 temp3 = RamDataIn[7:0] | Mask ;

				myArray[RamAddress][23:16];
				myArray[RamAddress][15:8];
				myArray[RamAddress][7:0];

				end
			else if(op==3'b010)begin //XOR'
				 temp1 = RamDataIn[23:16] ^ Mask ;
				 temp2 = RamDataIn[15:8] ^ Mask ;
				 temp3 = RamDataIn[7:0] ^ Mask ;

				myArray[RamAddress][23:16]=temp1;
				myArray[RamAddress][15:8]=temp2;
				myArray[RamAddress][7:0]=temp3;

				end
			else if(op==3'b011)begin //ADD'
				 int1 = RamDataIn[23:16] + Mask;
				 int2 = RamDataIn[15:8] + Mask ;
				 int3 = RamDataIn[7:0] + Mask ;

				if(int1 >= 255) myArray[RamAddress][23:16]=255;
				else myArray[RamAddress][23:16]=int1;

				if(int2 >= 255) myArray[RamAddress][15:8]=255;
				else myArray[RamAddress][15:8]=int2;

				if(int3 >= 255) myArray[RamAddress][7:0]=255;
				else myArray[RamAddress][7:0]=int3;

				


				end
			else if(op==3'b100)begin //SUBTRACT'
				int1 = RamDataIn[23:16] - Mask;
				 int2 = RamDataIn[15:8] - Mask ;
				 int3 = RamDataIn[7:0] - Mask ;

				if(int1 <= 0) myArray[RamAddress][23:16]=0;
				else myArray[RamAddress][23:16]=int1;

				if(int2 <= 0) myArray[RamAddress][15:8]=0;
				else myArray[RamAddress][15:8]=int2;

				if(int3 <= 0) myArray[RamAddress][7:0]=0;
				else myArray[RamAddress][7:0]=int3;


				end
			else if(op==3'b101)begin //INCREMENT'
				temp1=RamDataIn[23:16]+1 ;
				temp2= RamDataIn[15:8]+1  ;
				temp3= RamDataIn[7:0]+1;

				myArray[RamAddress][23:16]=temp1;
				myArray[RamAddress][15:8]=temp2;
				myArray[RamAddress][7:0]=temp3;

				end
			else if(op==3'b110)begin //DECREMENT'
				temp1=RamDataIn[23:16]-1 ;
				temp2= RamDataIn[15:8]-1  ;
				temp3= RamDataIn[7:0]-1;

				myArray[RamAddress][23:16]=temp1;
				myArray[RamAddress][15:8]=temp2;
				myArray[RamAddress][7:0]=temp3;

				end
			else begin //ROTATE LEFT
				int1=RamDataIn[23];
				int2=RamDataIn[15];
				int3=RamDataIn[7];

				RamDataIn[23:16]= RamDataIn[23:16]<<1;
				RamDataIn[15:8]= RamDataIn[15:8]<<1;
				RamDataIn[7:0]= RamDataIn[7:0]<<1;

				RamDataIn[16]=int1;
				RamDataIn[8]=int2;
				RamDataIn[0]=int3;

				myArray[RamAddress][23:16]=RamDataIn[23:16];
				myArray[RamAddress][15:8]=RamDataIn[15:8];
				myArray[RamAddress][7:0]=RamDataIn[7:0];







				end
			



			end //MODE==1 endi
	end //always@(posedge clk) endi

	always@(mode or RamAddress)begin
		if(mode==0) begin

			RamDataOut = myArray[RamAddress];
			
			end
	end //always@(mode or RamAddress)
	
	
//*************************************************************************************************'
/*  Please write your code above  */
endmodule


module RgbMaskModule(input Mode, input [3:0] Address, input [23:0] RGBin,input [2:0] Op, 
 input CLK, output wire [23:0] RGBout);
	
	/*  DO NOT edit this module  */
	
	wire [7:0]  romResult;

	MaskROM RO(Address, romResult);
	RgbRAM RA(Mode, Address, RGBin,romResult, Op, CLK, RGBout);
endmodule

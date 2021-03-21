`timescale 1ns / 1ps 
module lab3_2(
			input[3:0] number,
			input CLK, 
			input selection,
			input mode,
			input clear,
			output reg [7:0] digit1,
			output reg [7:0] digit0,
			output reg [7:0] count1,
			output reg [7:0] count0,
			output reg warning
    );
   //Modify the lines below to implement your design .
reg [7:0] p1;
reg [7:0] p0;
reg [7:0] s1;
reg [7:0] s0;
reg [7:0] d1;
reg [7:0] d0;
integer a;
   initial begin
   		count0=0;
	   	count1=0;
	   	digit1=0;
	   	digit0=0;
	   	warning=0;
			p1=0;
			p0=0;
			s1=0;
			s0=0;
			d0=0;
			d1=0;
			


   end
 
   always@(posedge CLK) begin
	 a=5;
	$display("");

	   if(clear)begin /* clear 1 ise her seyi sifirla*/
	   	count0=0;
	   	count1=0;
	   	digit1=0;
	   	digit0=0;
	   	warning=0;
			
			p1=0;
			p0=0;
			s1=0;
			s0=0;
			d1=0;
			d0=0;


	   	end
	   	else begin   /* clear 0 ise oyun baslasin*/

	   		if(selection==0)begin  /* SELECTION == 0      PRIME*/
					

	   		
				
	   			
						count0=p0;
						count1=p1;
						
						

	   				if(mode==1)begin        /*MODE== 1   NEXT PRIME*/
	   					if( number==4'b0010 ) begin // 2 geldiyse
	   						warning=0;
	   						count1=count1+1;
								if(count1==8'b00001001) begin count1=8'b00000000; end
								
	   						digit0=8'b00000010;
	   						digit1=8'b00000011;
								d0=digit0;
								d1=digit1;
								p1=count1;
								p0=count0;
								count0=p0;

	   					end
	   					else if( number==4'b0011 ) begin // 3 geldiyse
	   						
								count1=count1+1;
								
								if(count1==8'b00001001) begin count1=8'b00000000; end
								warning=0;
	   						digit0=8'b00000011;
	   						digit1=8'b00000101;
								d0=digit0;
								d1=digit1;
								p1=count1;
								p0=count0;
								count0=p0;
	   					end
	   					else if( number==4'b0101 ) begin // 5 geldiyse
	   						count1=count1+1;
								if(count1==8'b00001001) begin count1=8'b00000000; end
								warning=0;

	   						digit0=8'b00000101;
	   						digit1=8'b00000111;
								d0=digit0;
								d1=digit1;
								p1=count1;
								p0=count0;
								count0=p0;
	   					end	   					
	   					else if( number==4'b0111 ) begin // 7 geldiyse
	   						count1=count1+1;
								if(count1==8'b00001001) begin count1=8'b00000000; end
								warning=0;

	   						digit0=8'b00000111;
	   						digit1=8'b00001011;
								d0=digit0;
								d1=digit1;
								p1=count1;
								p0=count0;
								count0=p0;
	   					end	 
	   					else if( number==4'b1011 ) begin // 11 geldiyse
	   						count1=count1+1;
								if(count1==8'b00001001) begin count1=8'b00000000; end
								warning=0;

	   						digit0=8'b00001011;
	   						digit1=8'b00001101;
								d0=digit0;
								d1=digit1;
								p1=count1;
								p0=count0;
								count0=p0;
								
	   					end
							else if( number==4'b1101 ) begin // 13 geldiyse
	   						count1=count1+1;
								if(count1==8'b00001001) begin count1=8'b00000000; end
								warning=0;

	   						digit0=8'b00001101;
	   						digit1=8'b00000010;
								d0=digit0;
								d1=digit1;
								p1=count1;
								p0=count0;
								count0=p0;
	   					end
	   				/*	else begin                     // 13 geldiyse
	   						if(count1==8'b00001001) begin count1=0; end
	   						else begin count1=count1+1; end
	   						digit0=8'b00001101;
	   						digit1=8'b00000010;

	   					end*/
							else begin
							warning=1;
							digit0=d0;
							digit1=d1;
							count1=p1;
							count0=p0;
							
							end

	   				end     /* MODE==1 ENDi*/
	   				else begin             /*MODE==0   PREVIOUS PRIME */

	   					if( number==4'b0010 ) begin // 2 geldiyse
	   						count0=count0+1;
								if(count0==8'b00001001) begin count0=8'b00000000; end
								warning=0;

	   						digit0=8'b00000010;
	   						digit1=8'b00001101;
								d0=digit0;
								d1=digit1;
								p1=count1;
								p0=count0;
								count1=p1;

	   					end
	   					else if( number==4'b0011 ) begin // 3 geldiyse
	   						count0=count0+1;
								if(count0==8'b00001001) begin count0=8'b00000000; end
								warning=0;

	   						digit0=8'b00000011;
	   						digit1=8'b00000010;
								d0=digit0;
								d1=digit1;
								p1=count1;
								p0=count0;
								count1=p1;
	   					end
	   					else if( number==4'b0101 ) begin // 5 geldiyse
	   						count0=count0+1;
								if(count0==8'b00001001) begin count0=8'b00000000; end
								warning=0;

	   						digit0=8'b00000101;
	   						digit1=8'b00000011;
								d0=digit0;
								d1=digit1;
								p1=count1;
								p0=count0;
								count1=p1;
	   					end	   					
	   					else if( number==4'b0111 ) begin // 7 geldiyse
	   						count0=count0+1;
								if(count0==8'b00001001) begin count0=8'b00000000; end
								warning=0;

	   						digit0=8'b00000111;
	   						digit1=8'b00000101;
								d0=digit0;
								d1=digit1;
								p1=count1;
								p0=count0;
								count1=p1;
	   					end	 
	   					else if( number==4'b1011 ) begin // 11 geldiyse
	   						count0=count0+1;
								if(count0==8'b00001001) begin count0=8'b00000000; end
								warning=0;

	   						digit0=8'b00001011;
	   						digit1=8'b00000111;
								d0=digit0;
								d1=digit1;
								p1=count1;
								p0=count0;
								count1=p1;
	   					end	 
	   					else if(number==4'b1101)begin   // 13 geldiyse
	   						count0=count0+1;
								if(count0==8'b00001001) begin count0=8'b00000000; end
								warning=0;
	   						digit0=8'b00001101;
	   						digit1=8'b00001011;
								d0=digit0;
								d1=digit1;
								p1=count1;
								p0=count0;
								count1=p1;

	   					end
							else begin
								warning=1;
								
								digit0=d0;
								digit1=d1;
							count1=p1;
							count0=p0;
	   			
							
							end
	   				end  //Mode==0 endi







	   		end  //SELECTION ==0    endi

	   		else begin  /*NON_PRIME selection==1*/



	   			
						count1=s1;
						count0=s0;
						
	   				
	   				if(mode==1)begin //MOD==1 shift left
	   					if(number==4'b0001)begin   // 1 gelirse
	   						digit0=8'd1;
	   						digit1=8'd2;
								
								d0=digit0;
								d1=digit1;
								
								count1=count1+1;
								if(count1==8'b00001001) begin count1=8'b00000000; end
																d0=digit0;
								
								s1=count1;
								count0=s0;
								s0=count0;
								
								warning=0;

	   					end
	   					else if(number==4'b0100) begin //4 gelirse
	   						digit0=8'd4;
	   						digit1=8'd8;
								
								d0=digit0;
								d1=digit1;
								
								count1=count1+1;
								if(count1==8'b00001001) begin count1=8'b00000000; end
								s1=count1;
								count0=s0;
								s0=count0;
								
								warning=0;

	   					end	   					
	   					else if(number==4'b0110) begin // 6 gelirse
	   						digit0=8'd6;
	   						digit1=8'd12; 
								
								d0=digit0;
								d1=digit1;
								count1=count1+1;
								if(count1==8'b00001001) begin count1=8'b00000000; end
								s1=count1;
								count0=s0;
								s0=count0;
								
								warning=0;

	   					end	
	   					else if(number==4'b1000) begin // 8 gelirse
	   						digit0=8'd8;
	   						digit1=8'd0;
								
								d0=digit0;
								d1=digit1;
								count1=count1+1;
								if(count1==8'b00001001) begin count1=8'b00000000; end
								s1=count1;
								count0=s0;
								s0=count0;
								
								warning=0;
	   					end		   						   					
	   					else if(number==4'b1001) begin // 9 gelirse
	   						digit0=8'd9;
	   						digit1=8'd2;
								
								d0=digit0;
								d1=digit1;
								count1=count1+1;
								if(count1==8'b00001001) begin count1=8'b00000000; end
								s1=count1;
								count0=s0;
								s0=count0;
								
								warning=0;

	   					end	
	   					else if(number==4'b1010) begin // 10 gelirse
	   						digit0=8'd10;
	   						digit1=8'd4;
								
								d0=digit0;
								d1=digit1;
								count1=count1+1;
								if(count1==8'b00001001) begin count1=8'b00000000; end
								s1=count1;
								count0=s0;
								s0=count0;
								
								warning=0;

	   					end	
	   					else if(number==4'b1100) begin // 12 gelirse
	   						digit0=8'd12;
	   						digit1=8'd8;
								
								d0=digit0;
								d1=digit1;
								count1=count1+1;
								if(count1==8'b00001001) begin count1=8'b00000000; end
								s1=count1;
								count0=s0;
								s0=count0;
								
								warning=0;

	   					end	
	   					else if(number==4'b1110) begin // 14 gelirse
	   						digit0=8'd14;
	   						digit1=8'd12;
								
								d0=digit0;
								d1=digit1;
								count1=count1+1;
								if(count1==8'b00001001) begin count1=8'b00000000; end
									s1=count1;
								count0=s0;
								s0=count0;
								
								warning=0;
	   					end	
	   					else if(number==4'b1111)begin  //15 gelirse
	   					
	   						digit0=8'd15;
	   						digit1=8'd14;
								
								d0=digit0;
								d1=digit1;
								count1=count1+1;
								if(count1==8'b00001001) begin count1=8'b00000000; end
								s1=count1;
								count0=s0;
								s0=count0;
								
								warning=0;

	   					end
							else begin
								warning=1;
								
								digit0=d0;
								digit1=d1;
								count1=s1;
							count0=s0;
							end
	   				end //MOD==1 shift left  ENDİ
	   				else begin  //MOD==0 shift right
	   					if(number==4'b0001)begin   // 1 gelirse
	   						digit0=8'd1;
	   						digit1=8'd0;
								
								d0=digit0;
								d1=digit1;
								count0=count0+1;
								if(count0==8'b00001001) begin count0=8'b00000000; end
								s0=count0;
								count1=s1;
								s1=count1;
								
								warning=0;

	   					end
	   					else if(number==4'b0100) begin //4 gelirse
	   						digit0=8'd4;
	   						digit1=8'd2;
								
								d0=digit0;
								d1=digit1;
								count0=count0+1;
								if(count0==8'b00001001) begin count0=8'b00000000; end
								s0=count0;
								count1=s1;
								s1=count1;
								
								warning=0;

	   					end	   					
	   					else if(number==4'b0110) begin // 6 gelirse
	   						digit0=8'd6;
	   						digit1=8'd3;
								
								d0=digit0;
								d1=digit1;
								count0=count0+1;
								if(count0==8'b00001001) begin count0=8'b00000000; end
										s0=count0;
								count1=s1;
								s1=count1;
								
								warning=0;

	   					end	
	   					else if(number==4'b1000) begin // 8 gelirse
	   						digit0=8'd8;
	   						digit1=8'd4;
								
								d0=digit0;
								d1=digit1;
								count0=count0+1;
								if(count0==8'b00001001) begin count0=8'b00000000; end
								s0=count0;
								count1=s1;
								s1=count1;
								
								warning=0;

	   					end		   						   					
	   					else if(number==4'b1001) begin // 9 gelirse
	   						digit0=8'd9;
								
	   						digit1=8'd4;
								
								d0=digit0;
								d1=digit1;
								count0=count0+1;
								if(count0==8'b00001001) begin count0=8'b00000000; end
								s0=count0;
								count1=s1;
								s1=count1;
								
								warning=0;

	   					end	
	   					else if(number==4'b1010) begin // 10 gelirse
	   						digit0=8'd10;
	   						digit1=8'd5;
								
								d0=digit0;
								d1=digit1;
								count0=count0+1;
								if(count0==8'b00001001) begin count0=8'b00000000; end
								s0=count0;
								count1=s1;
								s1=count1;
								
								warning=0;

	   					end	
	   					else if(number==4'b1100) begin // 12 gelirse
	   						digit0=8'd12;
	   						digit1=8'd6;
								
								d0=digit0;
								d1=digit1;
								count0=count0+1;
								if(count0==8'b00001001) begin count0=8'b00000000; end
								s0=count0;
								count1=s1;
								s1=count1;
								
								warning=0;

	   					end	
	   					else if(number==4'b1110) begin // 14 gelirse
	   						digit0=8'd14;
	   						digit1=8'd7;
								
								d0=digit0;
								d1=digit1;
								count0=count0+1;
								if(count0==8'b00001001) begin count0=8'b00000000; end
								s0=count0;
								count1=s1;
								s1=count1;
								
								warning=0;

	   					end	
	   					else if(number==4'b1111)begin  //15 gelirse
	   					
	   						digit0=8'd15;
	   						digit1=8'd7;
								
								d0=digit0;
								d1=digit1;
								count0=count0+1;
								if(count0==8'b00001001) begin count0=8'b00000000; end
								s0=count0;
								count1=s1;
								s1=count1;
								
								warning=0;

	   					end
							else begin
								warning=1;
								
								digit0=d0;
								digit1=d1;
								count1=s1;
							count0=s0;
							end

	   				end //MODE==0 shift right
							
	   			


	   		end  /*NON_PRIME selection==1   endi  */

			
	   	end // clear 0 endi


 
   end  //always endi

endmodule



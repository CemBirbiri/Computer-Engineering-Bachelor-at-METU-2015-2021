`timescale 1ns / 1ps

module lab4_2(
  input [1:0] mode,
  input [2:0] n_gasoline_pumps,      // for setup mode, max 6
  input [2:0] n_diesel_pumps,        // for setup mode, max 6
  input [3:0] fuel_amount,           // for add car mode, max 8
  input fuel_type,                   // for add car mode, gas(0) or diesel(1)
  input CLK, 

  output reg [0:5] pump_status,                // pump is working or not, max 6 pumps
  output reg is_gasoline_queue_not_full,       // gasoline queue full warning
  output reg is_diesel_queue_not_full,         // diesel queue full warning

  output reg [3:0] n_cars_in_gasoline_queue,   // to represent max 9 on 1 7-seg display
  output reg [3:0] n_cars_in_diesel_queue,     // to represent max 9 on 1 7-seg display

  output reg [7:0] total_gasoline_needed,      // to represent max 99 on 2 7-seg displays
  output reg [7:0] total_diesel_needed,        // to represent max 99 on 2 7-seg displays

  // reset these after one clock
  output reg invalid_gasoline_car,             // to lightup dot at an2
  output reg invalid_diesel_car,               // to lightup dot at an0
  output reg invalid_setup_params              // to lightup all dots
);

// write your code here
integer gasoline_count;
integer diesel_count;
integer i;
reg [2:0] gas_queue [7:0] ;
reg [2:0] diesel_queue [7:0] ;
reg [2:0] pompa [5:0];

	always@(posedge CLK)begin
	invalid_gasoline_car=0;
	invalid_diesel_car=0;
	invalid_setup_params=0;

	
	if(mode==2'b11 | mode==2'b10)begin //SETUP mode
		gasoline_count=n_gasoline_pumps;
		diesel_count=n_diesel_pumps;
		if(gasoline_count+diesel_count > 6 || gasoline_count+diesel_count==0)begin
			//warning ver
			invalid_setup_params=1;
		end 
		else begin //gasoline_count+diesel_count uygun gelmis
			i=0;
			if(i==gasoline_count) ;
			else if(i<gasoline_count) pump_status[i]=1;
			else if(i==diesel_count) ;
			else if(i<diesel_count) pump_status[i]=1;
			else ;
			i=1;
			if(i==gasoline_count) ;
			else if(i<gasoline_count) pump_status[i]=1;
			else if(i==diesel_count) ;
			else if(i<diesel_count) pump_status[i]=1;
			else ;
			
			
			for(i=0; gasoline_count; i=i+1)begin//pump statusu olusturuyorz
				pump_status[i]=1;
			
			
			end
			
			for(i=gasoline_count; i< gasoline_count+diesel_count; i=i+1)begin//pump statusu olusturuyorz
				pump_status[i]=1;
			
			end

			is_gasoline_queue_not_full=0;
			is_diesel_queue_not_full=0;
			
			n_cars_in_gasoline_queue=0;
			n_cars_in_diesel_queue=0;

			total_gasoline_needed=0;
  			total_diesel_needed=0;
			//diesel_queue=0;  //*****
			//gas_queue=0;     //*****
		end
		
		
	//pompa ump_statusun bir gostergesi	

	end//mode==1X endi
	else if(mode==2'b00)begin //siradaki arabalar fuele gidiyor
		for(i=0;  i< gasoline_count; i=i+1)begin//gas sirasindaki arabalar pompaya gidiyor
			if(pump_status[i]==1)begin
				pompa[i]=gas_queue[i];
				pump_status[i]=0;
				
				total_gasoline_needed=total_gasoline_needed+gas_queue[i];
				gas_queue[i]=0;
			end
		
		end
		for(i=gasoline_count; i< gasoline_count+diesel_count; i=i+1)begin//diesel sirasindaki 
									//arabalar pompaya gidiyor
			if(pump_status[i]==1)begin
				pompa[i]=diesel_queue[i-gasoline_count];
				pump_status[i]=0;
				
				total_diesel_needed=total_diesel_needed+diesel_queue[i-gasoline_count];
				diesel_queue[i-gasoline_count]=0;
			end

		end 
		for(i=0; i< 6; i=i+1)begin 
			if(pompa[i]!= 0)begin //her clk cycle'da pompadaki arabalara 1 gallon veriliyor
								
				pompa[i]=pompa[i]-1;
				total_gasoline_needed=total_gasoline_needed-1;
				total_diesel_needed=total_diesel_needed-1;
	
			end
			else begin
				pump_status[i]=1;//cunku filled up olmus arabayi cikartiyoruz
				if(i< gasoline_count) n_cars_in_gasoline_queue=n_cars_in_gasoline_queue-1;
				else n_cars_in_diesel_queue=n_cars_in_diesel_queue-1;
				

			end
		end
		
		
//queue lari updatelemedin

	end//mode==00
	else begin //mode==01 //carlar siraya ekleniyor
		
		if(fuel_type==0)begin //gas isteyen araba gelmis
			if(fuel_amount >8) invalid_gasoline_car=0; //warning
			else begin
				if(gas_queue[0]==0)begin//queue bos
					
					for(i=0; i< gasoline_count; i=i+1)begin//queue bossa direk pompaya git
						if(pump_status[i]==1)begin
							pompa[i]=fuel_amount;
							pump_status[i]=0;
							
							total_gasoline_needed=total_gasoline_needed+fuel_amount;
							
						end
		
		end

				end
				else begin   //queue bos degil
					for(i=0; i< 8 ; i=i+1)begin
						if(gas_queue[i]==0)begin
							gas_queue[i]=fuel_amount;
							n_cars_in_gasoline_queue=n_cars_in_gasoline_queue+1;
							i=9; //break yerine
						end
					
					end	
				end
			end

		end
	end

	end//always endi

endmodule

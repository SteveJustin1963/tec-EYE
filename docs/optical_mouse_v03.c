/*

Optical Mouse rountines
ADNS-2610/2620 Agilent

CCS compiler

TechDesign Electronics (c) September 2007. 
Updated February-March 2009.

www.techdesign.be
info@techdesign.be

#bit mouse_sck	=pb.1		// ADNS-2620 
#bit mouse_sdio	=pb.0		//

*/



char mouse(short m_rw,char m_addr, char m_data);



////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char mouse(short m_rw,char m_addr, char m_data)
{
int8 s;
char mm_addr=0,mm_data=0;

SET_TRIS_B(0x04);
mouse_sck=1;
if(m_rw==1){mm_addr=(m_addr|0x80);}	// write to adns
else if(m_rw==0){mm_addr=m_addr;}	// read from adns

for (s=7;s!=255;s--){			// address

					mouse_sck=0;delay_cycles(20);
					mouse_sdio=bit_test(mm_addr,s);		//printf("%u",mouse_sdio);
					
					mouse_sck=1;
					delay_cycles(20);
					}

delay_us(200);
if(m_rw==0){
			SET_TRIS_B(0x05);
			//printf(" rw=0 ");
			}
//else if(m_rw==1){printf(" rw=1 ");}



for (s=7;s!=255;s--){			// data

					mouse_sck=0;delay_cycles(20);
					if(m_rw==0){
								if(mouse_sdio==1){bit_set(mm_data,s);}	//printf("1");}
								//else if(mouse_sdio==0){printf("0");}
								
								}
					else if(m_rw==1){mouse_sdio=bit_test(m_data,s);}
					mouse_sck=1;
					delay_cycles(20);
					}

//mouse_sck=0;nop;nop;
SET_TRIS_B(0x04);

//printf(" mm_data=%x ",mm_data);
return mm_data;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mouse_check(unsigned int8 selection)
{
//////////////////////
//OPTICAL MOUSE selection controls
unsigned int16 pix;
unsigned int8 dat;


mouse_cycle=0;

if(selection2!=selection){mouse(1,0x40,0x80);delay_us(100);}	// reset mouse on register sel. change


selection2=selection;


if((selection!=3)&&(selection<=11)){


		config_mouse = mouse(0,0x40,0x00);						// read config
		if(diag==2){printf(" config=%x ",config_mouse);}
		
		stat_mouse = mouse(0,0x41,0x00);						// read status
		if(diag==2){printf(" stat=%x ",stat_mouse);}
		
		y_mouse = mouse(0,0x42,0x00);							// read mouse delta y-axis
		if(diag==2){printf(" y=%d ",y_mouse);}
		x_mouse = mouse(0,0x43,0x00);							// read mouse delta x-axis
		if(diag==2){printf(" x=%d ",x_mouse);}
		
		SQUAL_mouse = mouse(0,0x44,0x00);						// read SQUAL_mouse
		if(diag==2){printf(" SQUAL_mouse=%x ",SQUAL_mouse);}	
		
		max_pixel = mouse(0,0x45,0x00);							// read mouse max_pixel
		if(diag==2){printf(" max_pixel=%d ",max_pixel);}
		min_pixel = mouse(0,0x46,0x00);							// read mouse min_pixel
		if(diag==2){printf(" min_pixel=%d ",min_pixel);}
		
		ldr_in_a = (signed int16)mouse(0,0x47,0x00);			// read pixel_sum
		if(diag==2){printf(" ldr_in_a=%Ld \n\r",ldr_in_a);}
		

}

else if(selection==3){

//unsigned int8 CCD_data[326];

mouse(1,0x40,0x01);	// forced awake mode ON
mouse(1,0x48,0x00);	// write anything to the pixel_data register

dat=0;

for (pix=1;pix!=325;pix++){		// 1...324
							
						if(pix==1){while ((dat&0xc0)!=0xc0){dat = mouse(0,0x48,0x00);};}		// read 
						else{dat = mouse(0,0x48,0x00);while((dat&0x40)!=0x40){dat = mouse(0,0x48,0x00);};}
						
						CCD_data[pix] = dat;

						//printf(" pix%Lu=%x ",pix,dat);
							}



max_pixel = mouse(0,0x45,0x00);							// read mouse max_pixel
//if(diag==2){printf(" max_pixel=%d ",max_pixel);}
min_pixel = mouse(0,0x46,0x00);							// read mouse min_pixel
//if(diag==2){printf(" min_pixel=%d ",min_pixel);}



mouse(1,0x40,0x00);	// forced awake mode OFF

}

else if(selection>=12){

		shutter_upper = mouse(0,0x49,0x00);							// read mouse shutter_upper
		if(diag==2){printf(" shutter_upper=%d ",shutter_upper);}
		shutter_lower = mouse(0,0x4a,0x00);							// read mouse shutter_lower
		if(diag==2){printf(" shutter_lower=%d ",shutter_lower);}

		frame_period = mouse(0,0x4b,0x00);							// read mouse frame_period
		if(diag==2){printf(" frame_period=%d ",frame_period);}



}



}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*****************************************************************************
* Filename:          D:\work\lprs2\2013_2014\Resene_vezbe\lab56\basic_system/drivers/vga_periph_mem_v1_00_a/src/vga_periph_mem.c
* Version:           1.00.a
* Description:       vga_periph_mem Driver Source File
* Date:              Wed Mar 05 10:25:21 2014 (by Create and Import Peripheral Wizard)
*****************************************************************************/


/***************************** Include Files *******************************/

#include "vga_periph_mem.h"
Xuint32 cursor_position;
/************************** Function Definitions ***************************/

void set_cursor(Xuint32 new_value){
	cursor_position = new_value;
}

void clear_text_screen(Xuint32 BaseAddress){
	int i;
	for (i = 0; i < 4800; i++){
		VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + i*4, 0x20);
	}
}

void print_string(Xuint32 BaseAddress, unsigned char string_s[], int lenght){
	int i;
	for (i = 0; i < lenght; i++){
		VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + cursor_position + i*4, (string_s[i]-0x40));
	}
}

void clear_graphics_screen(Xuint32 BaseAddress){
	int i;
	for (i = 0; i < 9600; i++){
	    VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0x0);
	}
}

void draw_square(Xuint32 BaseAddress){
	int i, j, k;
		for (j = 0; j < 480; j++){
			for (k = 0; k<(640/32); k++){
				i = j*(640/32) + k;
				if ((j > 200) && (j < 280) && (k > 8) && (k < 12)) {
					VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
				}
				else{
					VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0x0);
				}
			}
		}
}

void print_char(Xuint32 BaseAddress, char c){
	VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + cursor_position + 28, c);
}

void clear_screen(Xuint32 BaseAddress){
	clear_graphics_screen(BaseAddress);
	clear_text_screen(BaseAddress);
}

void set_foreground_color(Xuint32 BaseAddress, Xuint32 color){
	VGA_PERIPH_MEM_mWriteMemory(BaseAddress + 0x00000010, color);
}

void set_background_color(Xuint32 BaseAddress, Xuint32 color){
	VGA_PERIPH_MEM_mWriteMemory(BaseAddress + 0x00000014, color);
}

void set_font_size(Xuint32 BaseAddress, Xuint32 size){
	VGA_PERIPH_MEM_mWriteMemory(BaseAddress + 0x0000000C, size);
}

void draw_rectangle(Xuint32 BaseAddress){
	int i, j, k;
			for (j = 0; j < 480; j++){
				for (k = 0; k<(640/32); k++){
					i = j*(640/32) + k;
					if ((j > 200) && (j < 288) && (k > 4) && (k < 16)) {
						VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
					}
					else{
						VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0x0);
					}
				}
			}
}

void draw_square_moving(Xuint32 BaseAddress){
	int p, i, j, k;
	for(p = 0; p < 480; p++){
			for (j = 0; j < 480; j++){
						for (k = 0; k<(640/32); k++){
							i = j*(640/32) + k;
							if ((j > 200) && (j < 280) && (k > 8) && (k < 12)) {
								VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + p*i*4, 0xFFFFFFFF);
							}
							else{
								VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + p*i*4, 0x0);
							}
						}
					}
			}
}

/*void get_resolution(Xuint32 BaseAddress){

}*/

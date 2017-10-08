#include "keyboard.h"
#include "io.h"
#include "definitions.h"

char scancodes[] = 
{0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0F,0x10,
0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1E,0x1F,0x20,
0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2B,0x2C,0x2D,0x2E,0x2F,
0x30,0x31,0x32,0x33,0x34,0x35,0x37,0x39,0x47,0x48,0x49,0x4A,0x4B,0x4C,
0x4D,0x4E,0x4F,0x50,0x51,0x52,0x53,0x1C,0x01,0xE0,0xD3,0x2A,0x36,0x39,
0x0E};
char codestrans[] = 
{'1','2','3','4','5','6','7','8','9','0','-','=',9,'q','w','e','r','t'
,'y','u','i','o','p','[',']','a','s','d','f','g','h','j','k','l',';','\'',
'`','\\','z','x','c','v','b','n','m',',','.','/','*',' ','7','8','9','-',
'4','5','6','+','1','2','3','0','.',13,27,127,127,15,14,32,8};


char getScancode() {
	char c=0;
	do {
		if(inb(0x60)!=c) {
			c=inb(0x60);
			if(c>0) {
				return c;
			}
		}
	} while(1);
}

char getchar() {
	char the_scancode = getScancode();
	int n = sizeof(scancodes)/sizeof(scancodes[0]);
	for(int i=0; i < n+1; i++) {
		if(scancodes[i]==the_scancode) {
			outb(0x60,0);
			return codestrans[i];
		}
	}
	return ';';
}



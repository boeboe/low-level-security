#include <unistd.h>
#include <sys/mman.h>

/** Print out "you win!\r\n" */
unsigned char code[] = {
  0xeb, 0x19, 0x31, 0xc0, 0x31, 0xdb, 0x31, 0xd2, 0x31, 0xc9, 0xb0, 0x04,
  0xb3, 0x01, 0x59, 0xb2, 0x0a, 0xcd, 0x80, 0x31, 0xc0, 0xb0, 0x01, 0x31,
  0xdb, 0xcd, 0x80, 0xe8, 0xe2, 0xff, 0xff, 0xff, 0x79, 0x6f, 0x75, 0x20,
  0x77, 0x69, 0x6e, 0x21, 0x0d, 0x0a
};

/** Does a gracefull exit with code 0 */
//unsigned char code[] = {
  //0x31, 0xdb, 0xb0, 0x01, 0xcd, 0x80
//};

/** Small infinite loop */
//unsigned char code[] = {
  //0xcd, 0x80, 0xeb, 0xfe
//};

/**
 * Small sample program to test if your shellcode is working.
 * 
 */
int main(int argc, char **argv) {
	
	/** You need to data section to be made readable + executable */
	mprotect((void*)((intptr_t)code & ~0xFFF), 8192, PROT_READ|PROT_EXEC);	

	int (*exeshell)();
	exeshell = (int (*)()) code;
	(int)(*exeshell)();
	
	printf("Failed to execute shellcode");
	
}



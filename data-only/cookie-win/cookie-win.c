#pragma check_stack(off)

#include <stdio.h>

int main() {

	int cookie = 0;
	char buf[8];
	
	printf("buf: %08x cookie: %08x\n", &buf, &cookie);
	
	gets(buf);
	
	if (cookie == 0x41424344) {
		printf("you win!\n");
	}
}



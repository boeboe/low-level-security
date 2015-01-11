#include <stdio.h>
          
int main() {

	int cookie = 3333;
	char buf[8];
	printf("buf: %08x cookie: %08x\n", &buf, &cookie);
	
	gets(buf);
	
	if (cookie == 0x41424344) {
		printf("you win!\n");
	} else {
		printf("you lose!\n");
	}

}



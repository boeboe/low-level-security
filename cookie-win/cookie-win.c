#include <stdio.h>
          
int main() {

	int cookie = 0;
	char buf[8];
	
	printf("buf: %08x cookie: %08x\n", &buf, &cookie);
	
	printf("please provice input follow by <enter>\n");

	gets(buf);
	
	if (cookie == 0x41424344) {
		printf("you win!\n");
	} else {
		printf("you lose!\n");
	}
}



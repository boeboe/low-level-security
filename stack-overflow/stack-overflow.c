#include <stdio.h>

int main() {
	
	char buf[8];

	function(buf);
	
	printf("you lose!\n");
}

int function(char* buf) {
	
	printf("buf location: %08x\n", &buf);
	
	gets(buf);
	
	printf("buf content: %s\n", buf);

}

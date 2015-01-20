#pragma check_stack(off)

#include <string.h>
 
int main(int argc, char *argv[]) {
        
    boom(argv[1]);
    return 0;
        
}

void boom(char *str) {
	
    char buffer[128];
    printf("buffer: %08x \n", &buffer);
    strcpy(buffer, str);  // The horror…
    
}

#include <stdio.h>

int main(int argc, char** argv) {
	if (argc != 2) {
        printf( "usage: %s <string>\n", argv[0] );
    } else {
		int result = is_file_passwd("file://", argv[1]);
		
		if (result == 0) {
			printf("file content is passwd!\n");
		} else {
			printf("file content is not passwd!\n");
		}
	}
	
    return 0;
}

int is_file_passwd(char* one, char* two) {
	char tmp[16];
	
	printf("address of tmp: %08x\n", &tmp);
	
	strcpy(tmp, one);
	strcat(tmp, two);
		
	return strcmp(tmp, "file://passwd");
}

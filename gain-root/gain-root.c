#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[15];
    int pass = 0;

	printf("buf: %08x pass: %08x\n", &buf, &pass);

    printf("enter the password : \n");
    gets(buf);

    if(strcmp(buf, "secret")) {
        printf ("wrong Password \n");
    } else {
        printf ("correct Password \n");
        pass = 1;
    }

    if(pass) {
       /* Now Give root or admin rights to user*/
        printf ("root privileges given to the user \n");
    }

    return 0;
}

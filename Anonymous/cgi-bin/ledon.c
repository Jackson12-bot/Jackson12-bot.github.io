#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define DATAFILE "/usr/local/cgi/data.txt"
int main(void)
{
   
    char ch;
    char wendu[10];
    char shidu[10];
    char stime[20];
    int i=0;
    int j=0;
    int k=0;
    int flag=0;

    
        printf("Content-type:text/html\n\n");
        printf("<html>\n");
        printf("<head><title>viewdata</title></head>\n");
        printf("<body>\n");
        printf("温度:");
      
        system("echo 1 > /sys/class/leds/led1/brightness");
        printf("</body>\n");
        printf("</html>");
        fclose(f);
    
    return 0;
}


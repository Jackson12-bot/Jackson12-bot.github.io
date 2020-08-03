#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define DATAFILE "/usr/local/cgi/data.txt"
int main(void)
{
    FILE *f = fopen(DATAFILE,"r");
    char ch;
    char wendu[10];
    char shidu[10];
    char stime[20];
    int i=0;
    int j=0;
    int k=0;
    int flag=0;
    if(f == NULL) //判断打开文件是否成功
    {
        printf("Content-type:text/html;charset=gb2312\n\n");
        printf("<TITLE>错误</TITLE>");
        printf("<p><EM>意外错误，无法打开文件</EM>");
    }
    else//打开文件成功，开始输出网页
    {
        printf("Content-type:text/html\n\n");
        printf("<html>\n");
        printf("<head><title>viewdata</title></head>\n");
        printf("<body>\n");
        printf("温度:");
        while((ch=getc(f))!='\n') //判断是否到了一行的末尾
        {
            if(ch!=' '&&flag==0) //flag＝0表示正在读温度
            {
                wendu=ch;
                i++;
            }
            else if(flag==0)
            {
                wendu='\0';
                flag=1;
                printf("%s",wendu);
                printf("<br>湿度:");
                continue;
            }
            else if(ch!=' '&&flag==1) //flag=1表示正在读湿度
            {
                shidu[j]=ch;
                j++;
            }
            else if(flag==1)
            {
                shidu[j]='\0';
                flag=2;    //flag=2表示读取时间
                printf("%s<br>时间:",shidu);
                continue;
            }
            else
            {
                stime[k]=ch;
                k++;
            }
        }
        stime[k]='\0';
        printf("%s",stime);
        printf("</body>\n");
        printf("</html>");
        fclose(f);
    }
    return 0;
}


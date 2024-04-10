#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void reverse_string(char *s,int n)
{
    static int i=0;
    static char rs[500];
    if(*s)
    {
        reverse_string(s+1,n);
        rs[i++]=*s;
    }
    if(n==strlen(rs))
    {
        printf("%s",rs);
    }

}
int main()
{
    char s[500]={"a"};
    int n=0;
    printf("Introduce string: ");
    scanf("%499s",s);
    n=strlen(s);
    reverse_string(s,n);
    return 0;
}
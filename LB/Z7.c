#include<stdio.h>

void Display(char *str)
{
    if(*str != '\0')
    {
        printf("%c\t",*str);
        str++;
        Display(str);

    }
}

int main()
{
    char Arr[20];

    printf("ENter string:");
    scanf("%[^'\n']s",Arr);

    Display(Arr);

    return 0;
}
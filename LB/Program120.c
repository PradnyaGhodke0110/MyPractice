#include<stdio.h>

int strlenX(char str[])
{
    int iCnt=0,i=0;

    while(str[i] != '\0')
    {
        iCnt++;
        str++;
    }
    return iCnt;
}

int main()
{
    char Arr[30];
    int iRet=0;

    printf("Please enter string\n");
    scanf("%[^'\n']s",Arr);

    iRet=strlenX(Arr);
    printf("Number of characters are:%d\n",iRet);

    return 0;
}
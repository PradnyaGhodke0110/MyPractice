#include<stdio.h>
#include<stdbool.h>

typedef unsigned int UNIT;

bool CheckBit(UNIT No)
{
    UNIT iMask=512;
    UNIT Result=0;

    Result=No & iMask;

    if(Result == iMask)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{
    UNIT Value=0;
    bool bRet=false;

    printf("Enter Value");
    scanf("%d",&Value);

    bRet=CheckBit(Value);

    if(bRet==true)
    {
        printf("10th bit is on\n ");
    }
    else
    {
        printf("10th bit  is off\n");
    }

    return 0;
}
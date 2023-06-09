//DOUBLY CIRCULAR LINKED LIST 

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
     struct node *prev;

};

typedef struct node NODE ;
typedef struct  node * PNODE ;
typedef struct node ** PPNODE ;

void InsertFirst(PPNODE First,PPNODE Last,int no)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((*First==NULL) && (*Last==NULL))
    {
        *First=newn;
        *Last=newn; //navin nodcha adress apan head mde ani tail mde thewto

    }
    else
    {
        newn->next=*First;//newn next mde first cha addrees first prev mde newn cha address ani newn cha address first mde mhnjech first head la point krti ani head first node la mhnjech newn la  
        (*First)->prev=newn;
        *First=newn;
    }
    (*First)->prev=*Last;
    (*Last)->next=*First;



}
void InsertLast(PPNODE First,PPNODE Last,int no)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((*First==NULL) && (*Last==NULL))
    {
        *First=newn;
        *Last=newn; //navin nodcha adress apan head mde ani tail mde thewto

    }
    else
    {
        (*Last)->next=newn;
        newn->prev=*Last;
        *Last=newn;
        
    }
    (*First)->prev=*Last;
    (*Last)->next=*First;

}

void Display(PNODE First,PNODE Last)
{
    if(First==NULL && Last==NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    do
    {
        printf("|%d|->",First->data);
        First=First->next;
    } while (First!=Last->next);
    printf("\n");
    
}
int  Count(PNODE First,PNODE Last)
{
    int iCnt=0;
    if(First==NULL && Last==NULL)
    {
        //printf("Linked List is empty\n");
        return iCnt;
    }
    do
    {
        iCnt++;
       // printf("|%d|->",First->data);
        First=First->next;
    } while (First!=Last->next);

    return iCnt;
}
void DeleteFirst(PPNODE First,PPNODE Last)
{
    if(*First==NULL && *Last==NULL)
    {
        return;
    }
    else if(*First==*Last)
    {
        free(*First);
        *First=NULL;
        *Last=NULL;

    }
    else
    {
        (*First)=(*First)->next;
        free((*Last)->next);
    }
     (*First)->prev=*Last;
    (*Last)->next=*First;

}
void DeleteLast(PPNODE First,PPNODE Last)
{
    if(*First==NULL && *Last==NULL)
    {
        return;
    }
    else if(*First==*Last)
    {
        free(*First);
        *First=NULL;
        *Last=NULL;

    }
    else
    {
        *Last=(*Last)->prev;
        free((*First)->prev);
        
    }
     (*First)->prev=*Last;
    (*Last)->next=*First;

}
void InsertAtPos(PPNODE First,PPNODE Last,int no,int ipos)
{
    int iNodeCnt=Count(*First,*Last);
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt = 0;

    {
        if((ipos<1) ||(ipos>iNodeCnt+1))
        {
            printf("Invalid Position");
            return;
        }

    }

    if(ipos==1)
    {
        InsertFirst(First,Last,no);
    }
    else if(ipos==iNodeCnt+1)
    {
        InsertLast(First,Last,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }


}
void DeleteAtPos(PPNODE First, PPNODE Last, int ipos)
{
    int iNodeCnt = Count(*First, *Last);
    PNODE temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos ==1)
    {
        DeleteFirst(First,Last);
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast(First,Last);
    }
    else
    {
        temp = *First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}



int main()
{
    PNODE Head=NULL;
    PNODE Tail=NULL;
    int iRet=0;

    InsertFirst(&Head,&Tail,51);
    InsertFirst(&Head,&Tail,21);
    InsertFirst(&Head,&Tail,11);

    InsertLast(&Head,&Tail,101);
    InsertLast(&Head,&Tail,111);
    InsertLast(&Head,&Tail,121);

    Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("Numbr of nodes are:%d\n",iRet);

   
    InsertAtPos(&Head,&Tail,105,5);
    Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("Numbr of nodes are:%d\n",iRet);

    DeleteAtPos(&Head,&Tail,5);
     Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("Numbr of nodes are:%d\n",iRet);

    DeleteFirst(&Head,&Tail);
    DeleteLast(&Head,&Tail);
    Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("Numbr of nodes are:%d\n",iRet);

    return 0;
}
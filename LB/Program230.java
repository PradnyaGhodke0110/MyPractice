import java.util.*;
/*
 * * * *
 * * * *
 * * * *
 * * * *
  */
class Pattern
{
    public void Display(int row,int col)
    {
        int i=0,j=0;

        for(i=1;i<=row;i++)
        {
            for(j=1;j<=col;j++)
            {
                System.out.print("*\t");
            }
            System.out.println();

        }

    }
}
 class Program230
{
    public static void main(String args[])
    {
        Pattern pobj=new Pattern();
        Scanner sobj=new Scanner(System.in);

        System.out.println("enter no of rows:");
        int i=sobj.nextInt();

        System.out.println("enter no of cols:");
        int j=sobj.nextInt();
       
        pobj.Display(i,j);

    }

    
}

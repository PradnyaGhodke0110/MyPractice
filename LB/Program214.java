import java.util.*;
class MarvellousX
{
    public void Display(String str)
    {
        for(int i=0;i<str.length();i++)
        {
            System.out.println(str.charAt(i));
        }
    }
}
class Program214
{
    public static void main(String args[])
    {
        Scanner sobj=new Scanner(System.in);

        System.out.println("ENter your full name:");
        String str=sobj.nextLine();

        MarvellousX obj=new MarvellousX();

        obj.Display(str);

        
       }

}
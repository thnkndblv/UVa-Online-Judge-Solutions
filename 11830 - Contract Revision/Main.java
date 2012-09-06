import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner( System.in );
        
        while ( sc.hasNext() )
        {
            String D = sc.next();
            String N = sc.next();
            if ( D.equals("0") && N.equals("0") ) break;
            String ans = "";
            for (int i=0; i<N.length(); i++)
            {
                if ( N.charAt(i) != D.charAt(0) )
                {
                    ans = ans + N.substring(i,i+1);
                }
            }
            if ( ans.equals("") ) ans = "0";
            System.out.println( new BigInteger(ans) );
        }
    }
}
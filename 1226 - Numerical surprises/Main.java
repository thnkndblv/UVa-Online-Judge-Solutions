import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
    Main()
    {
        Scanner sc = new Scanner( System.in );
        
        int test = sc.nextInt();
        while ( test-- > 0 )
        {
            int m = sc.nextInt();
            BigInteger n = sc.nextBigInteger();
            System.out.println( n.mod( BigInteger.valueOf( m ) ) );
        }
    }
    public static void main( String[] args )
    {
        new Main();
    }
}

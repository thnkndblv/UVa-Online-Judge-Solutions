import java.io.*;
import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
    BigInteger[] P = new BigInteger[ 70 ];
    Main()
    {
        Scanner sc = new Scanner( System.in );
        P[ 0 ] = BigInteger.ONE;
        for (int i=1; i<70; i++) P[ i ] = P[ i-1 ].multiply( BigInteger.valueOf( 3 ) );
        
        long n;
        while ( ( n = sc.nextLong()) != 0 )
        {
            n--;
            System.out.print("{");
            boolean f = false;
            for (int i=0; n!=0; i++, n >>= 1)
            {
                if ( (n & 1) == 1 )
                {
                    if ( f ) System.out.print(",");
                    f = true;
                    System.out.print( " "+P[ i ] );
                }
            }
            System.out.println(" }");
        }
    }
    public static void main(String[] args)
    {
        new Main();
    }
}

import java.io.*;
import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
    BigInteger[] ans = new BigInteger[ 808 ];
    Main()
    {
        Scanner sc = new Scanner( System.in );
        ans[ 0 ] = BigInteger.ZERO;
        ans[ 1 ] = BigInteger.ZERO;
        ans[ 2 ] = BigInteger.ONE;
        for (int i=3; i<808; i++)
            ans[ i ] = BigInteger.valueOf( i-1 ).multiply( ans[i-1].add( ans[i-2] ) );
        
        while ( sc.hasNextInt() )
        {
            int n = sc.nextInt();
            if ( n == -1 ) break;
            System.out.println( ans[ n ] );
        }
    }
    
    public static void main(String[] args)
    {
        new Main();
    }
}

import java.util.Scanner;
import java.util.Arrays;

public class Main
{    
    Main()
    {
        Scanner sc = new Scanner( System.in );
        int caso = 1;
        while ( sc.hasNextInt() )
        {
            int N = sc.nextInt();
            int Q = sc.nextInt();
            
            if ( N==0 && Q==0 ) break;
            
            int[] acc = new int[ 10004 ];
            int[] pos = new int[ 10004 ];
            for (int i=0; i<N; i++)
            {
                int a = sc.nextInt();
                acc[ a ]++;
            }
            
            Arrays.fill( pos, -1 );
            if ( acc[0] > 0 ) pos[ 0 ] = 0;
            for (int i=1; i<=10000; i++)
            {
                if ( acc[i] > 0 ) pos[ i ] = acc[ i-1 ];
                acc[ i ] += acc[ i-1 ];
            }
            
            System.out.println("CASE# "+(caso++)+":");
            for (int i=0; i<Q; i++)
            {
                int m = sc.nextInt();
                
                if ( pos[ m ] == -1 ) System.out.println( m+" not found" );
                else System.out.println( m+" found at "+(pos[m]+1) );
            }
        }
    }
    public static void main(String[] args)
    {
        new Main();
    }
}

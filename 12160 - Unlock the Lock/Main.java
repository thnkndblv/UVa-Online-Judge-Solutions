import java.util.Scanner;
import java.util.Arrays;
import java.util.Queue;
import java.util.LinkedList;

public class Main
{
    final int oo = 1000000000;
    int[] button = new int[ 10 ];
    int[] dist = new int[ 10000 ];
    Main()
    {
        Scanner sc = new Scanner( System.in );
        int caso = 1;
        
        while ( sc.hasNextInt() )
        {
            int L = sc.nextInt();
            int U = sc.nextInt();
            int R = sc.nextInt();
            
            if ( L==0 && U==0 && R==0 ) break;
            
            for (int i=0; i<R; i++) button[i] = sc.nextInt();
            Arrays.fill( dist, oo );
            
            // BFS
            Queue< Integer > Q = new LinkedList<Integer>();
            Q.add( L );
            dist[ L ] = 0;
            while ( Q.size() > 0 )
            {
                int u = Q.poll();
                for (int i=0; i<R; i++)
                {
                    int nu = (u + button[i]) % 10000;
                    if ( dist[u]+1 < dist[nu] )
                    {
                        dist[ nu ] = dist[ u ] + 1;
                        Q.add( nu );
                    }
                }
            }
            
            if ( dist[U] == oo ) System.out.println("Case "+(caso++)+": Permanently Locked");
            else System.out.println("Case "+(caso++)+": "+dist[U]);
        }
    }
    public static void main(String[] args)
    {
        new Main();
    }
}

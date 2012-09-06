import java.util.Scanner;
import java.util.Arrays;
import java.util.Queue;
import java.util.LinkedList;

public class Main
{
    final int oo = 1000000000;
    char[][] board = new char[ 102 ][ 102 ];
    int[][] dist = new int[ 102 ][ 102 ];
    int[][] mov = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    Main()
    {
        Scanner sc = new Scanner( System.in );
        int test = sc.nextInt();
        while ( test-- > 0 )
        {
            int R = sc.nextInt();
            int C = sc.nextInt();
            for (int i=0; i<R; i++) board[i] = sc.next().toCharArray();
            
            int ri = 0, ci = 0;
            int rf = 0, cf = 0;
            for (int i=0; i<R; i++)
            {
                for (int j=0; j<C; j++)
                {
                    if ( board[i][j] == 'A' )
                    {
                        ri = i;
                        ci = j;
                    }
                    if ( board[i][j] == 'B' )
                    {
                        rf = i;
                        cf = j;
                    }
                    if ( board[i][j] != 'Z' ) continue;
                    for (int k=0; k<8; k++)
                    {
                        int nr = i + mov[k][0];
                        int nc = j + mov[k][1];
                        if ( nr>=0 && nr<R && nc>=0 && nc<C && board[nr][nc]=='.' ) board[nr][nc]='X';
                    }
                }
            }
            
            // BFS
            for (int i=0; i<R; i++) Arrays.fill( dist[i], oo );
            Queue< Integer > Q = new LinkedList<Integer>();
            dist[ri][ci] = 0;
            Q.add( (ri << 16) | ci );
            while ( Q.size() > 0 )
            {
                int r = Q.poll();
                int c = r & ((1<<16)-1);
                r >>= 16;
                
                for (int dr=-1; dr<2; dr++)
                    for (int dc=-1; dc<2; dc++)
                        if ( dr!=0  || dc!=0 )
                        {
                            int nr = r + dr;
                            int nc = c + dc;
                            if ( nr>=0 && nr<R && nc>=0 && nc<C )
                            {
                                if ( board[nr][nc]=='.' || board[nr][nc]=='B' )
                                {
                                    if ( dist[r][c] + 1 < dist[nr][nc] )
                                    {
                                        dist[nr][nc] = dist[r][c] + 1;
                                        Q.add( (nr << 16) | nc );
                                    }
                                }
                            }
                        }
            }
            if ( dist[rf][cf] == oo ) System.out.println("King Peter, you can't go now!");
            else System.out.println("Minimal possible length of a trip is " + dist[rf][cf]);
        }
    }
    
    public static void main(String[] args)
    {
        new Main();
    }
}

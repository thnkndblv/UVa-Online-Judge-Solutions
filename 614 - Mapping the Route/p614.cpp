#include <stdio.h>
#include <memory.h>

int n, m;
int rs, cs, rt, ct;
int maze[ 15 ][ 15 ];
int ans[ 15 ][ 15 ];

#define W 0
#define N 1
#define E 2
#define S 3

int mov[][2] = {{0,-1},{-1,0},{0,1},{1,0}};

bool dfs(int ra, int ca, int cnt)
{
    ans[ra][ca] = cnt;
    if ( ra==rt && ca==ct )
    {
        ans[ra][ca] = cnt;
        return true;
    }
    else
    {
        for (int k = 0; k < 4; k++)
        {
            if ( maze[ra][ca] & (1<<k) ) continue;
            int nr = ra + mov[k][0];
            int nc = ca + mov[k][1];
            if ( nr>=1 && nr<=n && nc>=1 && nc<=m && ans[nr][nc]==-1 )
                if (dfs( nr, nc, cnt+1 ))
                {
                    ans[ra][ca] = cnt;
                    return true;
                }
        }
        ans[ra][ca] = -2;
        return false;
    }
}

void printBorder(int ren)
{
    for (int j=1; j<=m; j++)
    {
        if ( j == 1 ) printf("+");
        if ( maze[ren][j] & (1<<N) ) printf("---");
        else printf("   ");
        printf("+");
    }
    puts("");
}

int main()
{
    int test = 1;
    while ( scanf("%d %d %d %d %d %d",&n,&m,&rs,&cs,&rt,&ct), n || m || rs || cs || rt || ct )
    {
        memset( maze, 0, sizeof maze );
        int a;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
            {
                if ( i == 1 ) maze[i][j] |= (1 << N), maze[i-1][j] |= (1 << S);
                if ( i == n ) maze[i][j] |= (1 << S), maze[i+1][j] |= (1 << N);
                if ( j == 1 ) maze[i][j] |= (1 << W), maze[i][j-1] |= (1 << E);
                if ( j == m ) maze[i][j] |= (1 << E), maze[i][j+1] |= (1 << W);
                
                scanf("%d",&a);
                if ( a & 1 ) maze[i][j] |= (1 << E), maze[i][j+1] |= (1 << W);
                if ( a & 2 ) maze[i][j] |= (1 << S), maze[i+1][j] |= (1 << N);
            }
        
        memset( ans, -1, sizeof ans );
        dfs( rs, cs, 1 );
        printf("Maze %d\n\n",test++);
        for (int i=1; i<=n; i++)
        {
            printBorder( i );
            for (int j=1; j<=m; j++)
            {
                if ( j==1 ) printf("|");
                
                if ( ans[i][j] == -2 ) printf("???");
                else if ( ans[i][j] == -1 ) printf("   ");
                else printf("%3d",ans[i][j]);
                
                if ( maze[i][j] & (1<<E) ) printf("|");
                else printf(" ");
            }
            puts("");
        }
        printBorder( n+1 );
        puts("");
        puts("");
    }
    
    return 0;
}

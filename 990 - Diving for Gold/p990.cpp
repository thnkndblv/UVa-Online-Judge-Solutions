#include <stdio.h>
#include <memory.h>

int d[33], v[33], x[33];
int dp[ 33 ][ 1003 ];
bool tomar[  33 ][ 1003 ];

void path(int n, int t, int cnt)
{
    if ( n == 0 ) printf("%d\n",cnt);
    else if ( tomar[n][t] )
    {
        path( n-1, t-x[n], cnt+1 );
        printf("%d %d\n",d[n],v[n]);
    }
    else
    {
        path( n-1, t, cnt );
    }
}

int main()
{
    int t, w;
    int n;
    int test;
    
    while ( scanf("%d %d",&t,&w) == 2 )
    {
        scanf("%d",&n);
        for (int i=1; i<=n; i++) scanf("%d %d",d+i,v+i),x[i] = 3*d[i]*w;
        
        memset( tomar, 0, sizeof tomar );
        for (int i=1; i<=n; i++)
        {
            for (int j=0; j<=t; j++)
            {
                dp[i][j] = dp[i-1][j];
                if ( x[i]<=j && v[i]+dp[i-1][j-x[i]] > dp[i][j] )
                {
                    dp[i][j] = v[i] + dp[i-1][j-x[i]];
                    tomar[i][j] = true;
                }
            }
        }
        if ( test++ ) puts("");
        printf("%d\n",dp[n][t]);
        path( n, t, 0 );
    }
    
    return 0;
}
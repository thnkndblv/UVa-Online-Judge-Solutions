#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

#define MAXD 20
int p[ MAXD ][ MAXD ];
int f[ MAXD ];
int ans[ MAXD ][ MAXD ];
int temp[ MAXD ][ MAXD ];

int main()
{
    int d, n, m;
    
    while ( scanf("%d %d %d",&d,&n,&m), d || n || m )
    {
        memset( p, 0, sizeof p );
        memset( ans, 0, sizeof ans );
        for (int i=0; i<d; i++) scanf("%d",&p[0][i]), p[0][i] %= m;
        for (int i=0; i<d; i++) scanf("%d",f+i), f[i] %= m;
        for (int i=1; i<d; i++) p[i][i-1] = 1;
        for (int i=0; i<d; i++) ans[i][i] = 1;
        
        reverse( f, f+d );
        n -= 1;
        while ( n > 0 )
        {
            if ( n & 1 )
            {
                memset( temp, 0, sizeof temp );
                for (int i=0; i<d; i++)
                    for (int j=0; j<d; j++)
                        for (int k=0; k<d; k++)
                        {
                            temp[i][j] += p[i][k] * ans[k][j];
                            temp[i][j] %= m;
                        }
                memcpy( ans, temp, sizeof temp );
            }
            
            memset( temp, 0, sizeof temp );
            for (int i=0; i<d; i++)
                for (int j=0; j<d; j++)
                    for (int k=0; k<d; k++)
                    {
                        temp[i][j] += p[i][k] * p[k][j];
                        temp[i][j] %= m;
                    }
            memcpy( p, temp, sizeof temp );
            
            n >>= 1;
        }
        
        int r = 0;
        for (int i=0; i<d; i++)
        {
            r += ans[d-1][i] * f[ i ];
            r %= m;
        }
        printf("%d\n",r);
    }
    
    return 0;
}
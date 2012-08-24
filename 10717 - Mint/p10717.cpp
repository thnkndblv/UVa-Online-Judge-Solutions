#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <math.h>

using namespace std;

int coin[ 55 ];

int gcd(int a, int b)
{
    return b==0 ? a : gcd( b, a%b );
}

int main()
{
    int n, t, h;
    
    while ( scanf("%d %d",&n,&t), n || t )
    {
        for (int i=0; i<n; i++) scanf("%d",coin+i);
        while ( t-- )
        {
            scanf("%d",&h);
            int x = INT_MAX, y = INT_MAX;
            for (int i=0; i<n; i++)
                for (int j=i+1; j<n; j++)
                    for (int k=j+1; k<n; k++)
                        for (int l=k+1; l<n; l++)
                        {
                            int lcm = 1;
                            lcm = lcm * coin[i] / gcd( lcm, coin[i] );
                            lcm = lcm * coin[j] / gcd( lcm, coin[j] );
                            lcm = lcm * coin[k] / gcd( lcm, coin[k] );
                            lcm = lcm * coin[l] / gcd( lcm, coin[l] );
                            x = min( x, h - lcm*(int)floor( 1.0 * h / lcm ) );
                            y = min( y, lcm*(int)ceil( 1.0 * h / lcm ) - h );
                        }
            printf("%d %d\n",h-x,h+y);
        }
    }
    
    return 0;
}

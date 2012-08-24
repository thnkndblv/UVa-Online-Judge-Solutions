#include <stdio.h>

int s, t;
int v[ 35 ];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd( b, a % b );
}

void backtrack(int n, int k)
{
    if ( k > t )
    {
        if ( n == 0 )
        {
            for (int i=1; i<=t; i++)
            {
                if ( i!=1 ) printf(" ");
                printf("%d",v[i]);
            }
            printf("\n");
        }
    }
    else
    {
        for (int i=v[k-1]; i<=n; i++)
        {
            bool ok = true;
            for (int j=1; j<k; j++)
                if ( gcd( i, v[j] ) != 1 )
                {
                    ok = false;
                    break;
                }
            if ( ok )
            {
                v[ k ] = i;
                backtrack( n - i, k+1 );
            }
        }
    }
}

int main()
{
    int test;
    
    scanf("%d",&test);
    for (int kase=1; kase<=test; kase++)
    {
        scanf("%d %d",&s,&t);
        v[ 0 ] = 1;
        printf("Case %d:\n",kase);
        backtrack( s, 1 );
    }
    
    return 0;
}

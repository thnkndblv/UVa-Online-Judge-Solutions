#include <stdio.h>

int f[ 15 ];
int r[ 15 ];

int main()
{
    f[ 0 ] = 1;
    for (int i=1; i<=12; i++) f[ i ] = f[i-1] * i;
    r[ 2 ] = 1;
    for (int i=3; i<=12; i++) r[ i ] = (i-1) * ( r[i-1] + r[i-2] );
    
    int test, n;
    
    scanf("%d",&test);
    while ( test-- )
    {
        scanf("%d",&n);
        printf("%d/%d\n",r[n],f[n]);
    }
    
    return 0;
}

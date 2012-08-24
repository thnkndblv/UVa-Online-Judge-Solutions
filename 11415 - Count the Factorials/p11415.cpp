#include <stdio.h>
#include <bitset>
#include <algorithm>

using namespace std;

#define MAXN 3000000
bitset< MAXN > criba;
int facts[ MAXN ];
void sieve()
{
    criba.set();
    criba[ 0 ] = 0;
    criba[ 1 ] = 0;
    for (int i=2; i<MAXN; i++)
        if ( criba[i] )
        {
            facts[ i ] = 1;
            for (int j=i<<1; j<MAXN; j+=i)
            {
                criba[ j ] = 0;
                for (int k=j; k%i==0; k/=i)
                    facts[ j ]++;
            }
        }
}

int main()
{
    sieve();
    for (int i=2; i<MAXN; i++) facts[ i ] += facts[ i-1 ];
    
    int t, n;
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d",&n);
        printf("%d\n",(int)(upper_bound( facts, facts+MAXN, n ) - facts));
    }
    
    return 0;
}

#include <stdio.h>
#include <bitset>

using namespace std;

#define MAXPRIME 5000006
bitset< MAXPRIME > criba;
int ans[ MAXPRIME ];
void sieve()
{
    criba.set();
    criba[ 0 ] = 0;
    criba[ 1 ] = 0;
    for (int i=2; i<MAXPRIME; i++)
        if ( criba[i] )
        {
            ans[ i ] += i;
            for (int j=i<<1; j<MAXPRIME; j+=i)
            {
                criba[j] = 0;
                ans[ j ] += i;
            }
        }
}

int main()
{
    int a, b;
    
    sieve();
    for (int i=2; i<MAXPRIME; i++)
    {
        if ( criba[ ans[i] ] ) ans[ i ] = 1 + ans[ i-1 ];
        else ans[ i ] = ans[ i-1 ];
    }
    
    while ( scanf("%d",&a), a )
    {
        scanf("%d",&b);
        printf("%d\n",ans[b]-ans[a-1]);
    }
    
    return 0;
}

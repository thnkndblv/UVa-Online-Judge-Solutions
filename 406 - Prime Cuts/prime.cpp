#include <stdio.h>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXPRIME 1010
bitset< MAXPRIME > criba;
vector< int > primo;
void sieve()
{
    criba.set();
    criba[ 0 ] = 0;
    criba[ 1 ] = 0;
    for (int i=2; i*i<MAXPRIME; i++)
        if ( criba[ i ] )
            for (int j=i<<1; j<MAXPRIME; j+=i)
                criba[ j ] = 0;
    primo.push_back( 1 );
    for (int i=2; i<MAXPRIME; i++)
        if ( criba[ i ] )
            primo.push_back( i );
}

int main()
{
    int n, c;
    
    sieve();
    while ( scanf("%d %d",&n,&c) == 2 )
    {
        int m = 0;
        while ( primo[ m ] <= n ) m++;
        int L, H;
        if ( m%2 == 0 )
        {
            L = max( 0, m/2 - c );
            H = min( m-1, m/2 + (c-1) );
        }
        else
        {
            L = max( 0, m/2 - (c - 1) );
            H = min( m-1, m/2 + (c - 1) );
        }
        printf("%d %d:",n,c);
        for (int i=L; i<=H; i++) printf(" %d",primo[i]);
        printf("\n\n");
    }
    
    return 0;
}

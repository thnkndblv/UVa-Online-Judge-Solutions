#include <stdio.h>
#include <bitset>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

#define MAXPRIME 10004
bitset< MAXPRIME > criba;
vector< int > primo;
void sieve()
{
    criba.set();
    criba[0] = 0;
    criba[1] = 0;
    for (int i=2; i<MAXPRIME; i++)
    {
        if ( criba[i] )
        {
            primo.push_back( i );
            for (int j=i<<1; j<MAXPRIME; j+=i)
                criba[j] = 0;
        }
    }
}

int main()
{
    int n;
    
    primo.push_back( 0 );
    sieve();
    for (int i=1; i<primo.size(); i++) primo[ i ] += primo[ i-1 ];
    
    while ( scanf("%d",&n), n )
    {
        int ans = 0;
        for (int i=0; i<primo.size(); i++)
            if ( binary_search( primo.begin(), primo.end(), primo[i]+n ) )
                ans++;
        printf("%d\n",ans);
    }
    
    return 0;
}

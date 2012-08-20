#include <stdio.h>
#include <bitset>
#include <vector>

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
    int m, n;
    
    sieve();
    
    scanf("%d",&m);
    while ( m-- )
    {
        scanf("%d",&n);
        int ans = primo[0];
        for (int i=0; i<primo.size() && primo[i]<=n; i++)
            if ( n % primo[i] > n % ans )
                ans = primo[i];
        printf("%d\n",ans);
    }
    
    return 0;
}

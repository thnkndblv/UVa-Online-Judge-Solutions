#include <stdio.h>

int main()
{
    int n, lim;
    int cs = 1;
    
    while ( scanf("%d %d",&n,&lim), n!=-1 && lim!=-1 )
    {
        int cnt = 1;
        long long k=n;
        while ( k!=1LL && k<=lim )
        {
            k = (k&1LL) ? 3LL*k+1LL: k/2LL;
            cnt++;
        }
        if ( k != 1LL ) cnt--;
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n",cs++,n,lim,cnt);
    }
    
    return 0;
}

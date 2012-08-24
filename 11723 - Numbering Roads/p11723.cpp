#include <stdio.h>

int main()
{
    int n, r;
    int test = 1;
    
    while ( scanf("%d %d",&r,&n), r || n )
    {
        int ans = (r-1) / n;
        if ( ans > 26 ) printf("Case %d: impossible\n",test++);
        else printf("Case %d: %d\n",test++,ans);
    }
    
    return 0;
}

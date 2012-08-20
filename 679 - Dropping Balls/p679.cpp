#include <stdio.h>

int main()
{
    int test;
    int d, i;
    
    scanf("%d",&test);
    while ( test-- )
    {
        scanf("%d %d",&d,&i);
        i--;
        int ans = 0;
        for (int j=1; j<d; j++)
        {
            ans <<= 1;
            ans |= (i & 1);
            i >>= 1;
        }
        ans += (1 << (d-1));
        printf("%d\n",ans);
    }
    
    return 0;
}

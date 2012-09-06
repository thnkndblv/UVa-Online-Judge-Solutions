#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>

using namespace std;

char str[ 1003 ];
int dp[ 1003 ][ 1003 ];

int solve(int a, int b)
{
    if ( a > b ) return 0;
    int &ret = dp[a][b];
    if ( ret != -1 ) return ret;
    if ( a == b ) return ret = 1;
    if ( str[a] == str[b] ) return ret = 2 + solve( a+1, b-1 );
    return ret = max( solve(a+1,b), solve(a,b-1) );
}

int main()
{
    int test;
    
    scanf("%d",&test);
    gets(str);
    while ( test-- )
    {
        gets( str );
        int len = strlen( str );
        memset( dp, -1, sizeof dp );
        printf("%d\n",solve( 0, len-1 ));
    }
    
    return 0;
}

#include <stdio.h>
#include <stack>
#include <ctype.h>

using namespace std;

char line[ 5 ];
int precedencia[ 1 << 8 ];

int main()
{
    int T;
    
    precedencia[ '(' ] = -1;
    precedencia[ '+' ] = precedencia[ '-' ] = 0;
    precedencia[ '*' ] = precedencia[ '/' ] = 1;
    
    scanf("%d\n",&T);
    scanf("\n");
    while ( T-- )
    {
        char c;
        stack< char > stk;
        while ( gets(line) )
        {
            if ( sscanf(line,"%c",&c) != 1 ) break;
            if ( isdigit( c ) ) printf("%c",c);
            else if ( c == '(' ) stk.push( c );
            else if ( c == ')' )
            {
                while ( stk.top() != '(' ) printf("%c",stk.top()), stk.pop();
                stk.pop();
            }
            else
            {
                while ( !stk.empty() && precedencia[ c ] <= precedencia[ stk.top() ] )
                {
                    printf("%c",stk.top());
                    stk.pop();
                }
                stk.push( c );
            }
        }
        while ( !stk.empty() ) printf("%c",stk.top()), stk.pop();
        puts("");
        if ( T ) puts("");
    }
    
    return 0;
}

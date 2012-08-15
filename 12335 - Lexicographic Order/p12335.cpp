#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long f[ 20 ];

int main()
{
    int T;
    string str;
    long long k;
    
    f[0] = 1LL;
    for (int i=1; i<20; i++) f[ i ] = f[ i-1 ] * i;
    
    cin >> T;
    for (int kase=1; kase<=T; kase++)
    {
        cin >> str >> k;
        int n = str.length();
        int perm[ n ];
        for (int i=0; i<n; i++) perm[ i ] = i;
        k--;
        for (int i=0; i<n; i++)
        {
            int p = k / f[ n - i - 1 ];
            swap( perm[i], perm[i+p] );
            sort( perm+i+1, perm+n );
            k %= f[ n - i - 1 ];
        }
        string ans( n, ' ' );
        for (int i=0; i<n; i++) ans[ perm[ i ] ] = str[ i ];
        cout << "Case " << kase << ": " << ans << endl;
    }
    
    return 0;
}

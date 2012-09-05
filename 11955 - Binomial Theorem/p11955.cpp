#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

long long C[55][55];

int main()
{
    int test;
    string line;
    
    for (int i=0; i<=50; i++)
        for (int j=0; j<=i; j++)
        {
            if ( j==0 || j==i ) C[i][j] = 1LL;
            else C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    
    cin >> test;
    cin.ignore();
    for (int cs=1; cs<=test; cs++)
    {
        getline( cin, line );
        replace( line.begin(), line.end(), '(', ' ' );
        replace( line.begin(), line.end(), ')', ' ' );
        replace( line.begin(), line.end(), '+', ' ' );
        replace( line.begin(), line.end(), '^', ' ' );
        istringstream in( line );
        string a, b;
        int k;
        in >> a >> b >> k;
        cout << "Case " << cs << ": ";
        for (int i=0; i<=k; i++)
        {
            int j = k - i;
            if ( i ) cout << "+";
            if ( C[k][i] != 1LL ) cout << C[k][i] << "*";
            if ( j )
            {
                cout << a;
                if ( j > 1 ) cout << "^" << j;
            }
            if ( i && j ) cout << "*";
            if ( i )
            {
                cout << b;
                if ( i > 1 ) cout << "^" << i;
            }
        }
        cout << endl;
    }
    
    return 0;
}

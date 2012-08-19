#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <memory.h>

using namespace std;

string line;
int cnt[ 1003 ];

int main()
{
    int N, P;
    int neighbour;
    
    cin >> N;
    while ( N-- )
    {
        cin >> P;
        cin.ignore();
        memset( cnt+1, 0, P << 2 );
        for (int i=1; i<=P; i++)
        {
            getline( cin, line );
            istringstream in( line );
            while ( in >> neighbour ) cnt[ i ]++;
        }
        int best = *min_element( cnt+1, cnt+1+P );
        int f = 0;
        for (int i=1; i<=P; i++)
            if ( cnt[i] == best )
            {
                if ( f++ ) cout << " ";
                cout << i;
            }
        cout << endl;
    }
    
    return 0;
}

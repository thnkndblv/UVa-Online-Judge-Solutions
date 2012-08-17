#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define forit(i, a) for ( __typeof( (a).begin() ) i = (a).begin(); i != (a).end(); i++ )
#define mp make_pair

string line;
map< string, set<string> > project;
map< string, int > cnt;
vector< pair< int, string > > ans;

bool cmp( pair<int,string> A, pair<int,string> B )
{
    return A.first > B.first || (A.first == B.first && A.second < B.second);
}

int main()
{
    while ( getline( cin, line ), line != "0" )
    {
        string lastP = "";
        project.clear();
        while ( line != "1" )
        {
            if ( isupper( line[ 0 ] ) )
            {
                project[ line ] = set<string>();
                lastP = line;
            }
            else
            {
                project[ lastP ].insert( line );
            }
            getline(cin,line);
        }
        cnt.clear();
        forit(it1, project)
        {
            forit (it2, it1->second)
            {
                cnt[ *it2 ]++;
            }
        }
        ans.clear();
        forit(it1, project)
        {
            int a = 0;
            forit(it2, it1->second)
            {
                if ( cnt[ *it2 ] > 1 ) continue;
                a++;
            }
            ans.push_back( mp( a, it1->first ) );
        }
        sort( ans.begin(), ans.end(), cmp );
        forit(it, ans) cout << it->second << " " << it->first << endl;
    }
    
    return 0;
}

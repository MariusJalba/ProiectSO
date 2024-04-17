#include <iostream>
using namespace std;
int main()
{
enum Zi {L,Ma,Mi,J,V,S,D};
int z;
for (z=(int)L; z<=(int)V; z++) cout<<z; cout<<endl;
for (z=(int)D; z>=(int)Ma; z--) cout<<z; cout<<endl;
return 0;
}

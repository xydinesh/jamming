/*
  ID: xydines1
  PROG: ride
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstring>

using namespace std;

int main() 
{
    char comet[10];
    char group[10];
    int icoment;
    int igroup;
    map <const char, int> values;
    int i;

    freopen("ride.in", "r", stdin);  freopen("ride.out", "w", stdout);

    for (i = 0; i < 26; i++)  values[(const char )('A' + i)] = i + 1;

    scanf("%s\n", comet);
    scanf("%s\n", group);

    icoment = values[comet[0]];
    for (i = 1; i < (int)strlen(comet); i++)  icoment *= values[comet[i]];

    igroup = values[group[0]];
    for (i = 1; i < (int)strlen(group); i++)  igroup *= values[group[i]];

    ((icoment % 47) == (igroup % 47))? printf("GO\n"):printf("STAY\n");
    return 0;
}

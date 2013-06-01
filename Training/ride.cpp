/*
ID: celesti3
PROG: ride
LANG: C++
*/


#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);

	char comet[6],grp[6];
	scanf("%s%s",comet,grp);

	int cmod=1,gmod=1;
	int clen=strlen(comet),glen=strlen(grp);

	FOR(fir,0,clen)
		cmod*=(comet[fir]+1-'A');
	FOR(sec,0,glen)
		gmod*=(grp[sec]+1-'A');

	cmod%=47,gmod%=47;
	if(cmod==gmod)
		printf("GO\n");
	else
		printf("STAY\n");

	fclose(stdin);
	fclose(stdout);

	return 0;
}

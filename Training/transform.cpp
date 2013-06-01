/*
ID: celesti3
PROG: transform
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define MEM(A,B) memset(A,B,sizeof(A))
#define VS vector<string>
#define SZ(A) int(A.size())

using namespace std;

int N;
char tmp[11][11];
char old[11][11],chng[11][11],dupl[11][11];

inline bool isEql(char fir[][11],char sec[][11])
{
	FOR(all,0,N)
		if(strcmp(fir[all],sec[all]))
			return 0;
	return 1;
}

inline bool copy(char to[][11],char from[][11])
{
	FOR(flr,0,N)	FOR(flc,0,N)	to[flr][flc]=from[flr][flc];
	return 1;
}

inline bool rot90(char grid[][11])
{
	char rt[11][11];
	FOR(rw,0,N)		FOR(cl,0,N)
		rt[cl][N-1-rw]=grid[rw][cl];

	copy(grid,rt);
	return isEql(grid,chng);
}

inline bool rot180(char from[][11],char grid[][11])
{
	copy(grid,from);
	rot90(grid);		rot90(grid);
	return isEql(grid,chng);
}

inline bool rot270(char from[][11],char grid[][11])
{
	copy(grid,from);
	rot90(grid);		rot90(grid);		rot90(grid);
	return isEql(grid,chng);
}

int main()
{
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);

	scanf("%d",&N);
	FOR(rw,0,N)
		scanf("%s",old[rw]);

	FOR(rw,0,N)
		scanf("%s",chng[rw]);

	bool dn=0;
	copy(dupl,old);

	if(rot90(dupl))		printf("1\n"),dn=1;
	else if(!dn && rot180(old,dupl))		printf("2\n"),dn=1;
	else if(!dn && rot270(old,dupl))		printf("3\n"),dn=1;
	else {
		copy(dupl,old);
		FOR(rw,0,N)		FOR(cl,0,(N>>1))
			swap(dupl[rw][cl],dupl[rw][N-1-cl]);

		if(!dn && isEql(dupl,chng))		printf("4\n"),dn=1;
		else {
			bool nty=0,onety=0,twos=0;

			copy(tmp,dupl);
			if(rot90(dupl))	nty=1;
			if(!nty && rot180(tmp,dupl))	onety=1;
			if(!nty && !onety && rot270(tmp,dupl))		twos=1;

			if(nty || onety || twos)
				printf("5\n");
			else if(isEql(old,chng))
				printf("6\n");
			else
				printf("7\n");
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}

#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <numeric>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);

	char wts[21][12];
	int N;

	scanf("%d",&N);
	FOR(a,0,N){
		scanf("%s",wts[a]);
		reverse(wts[a],wts[a]+strlen(wts[a]));

		EFOR(fl,strlen(wts[a]),9)		wts[a][fl]='0';
	}

	bool inc[21];

	int ans=0;
	FOR(a,1,1<<N){
		int bits=__builtin_popcount(a);
		if(ans>=bits)	continue;

		FOR(mask,0,N)
			inc[mask]=(a>>mask)&1;

		bool car=0;
		EFOR(ps,0,9){
			int tmp=0;

			FOR(cow,0,N)
				if(inc[cow]){
					tmp+=(wts[cow][ps]-'0');
					if(tmp>=10){
						car=1,ps=10;
						break;
					}
				}
		}
		if(!car)
			ans=bits;
	}
	printf("%d\n",ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

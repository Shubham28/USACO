/*
ID: celesti3
PROG: spin
LANG: C++
*/


#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

int main()
{
	freopen("spin.in","r",stdin);
	freopen("spin.out","w",stdout);

	int spd[5],W[5],wdg[5][5][2];

	FOR(a,0,5){
		scanf("%d %d",&spd[a],&W[a]);
		FOR(i,0,W[a]){
			scanf("%d %d",&wdg[a][i][0],&wdg[a][i][1]);
			wdg[a][i][1]+=wdg[a][i][0];
			wdg[a][i][1]%=360;
		}
	}

	char used[400];
	int mat=(1<<5)-1;
	bool fnd=0;

	EFOR(tm,0,360){
		MEM(used,0);

		FOR(l,0,5)
			FOR(a,0,W[l]){
				int fr=(wdg[l][a][0]+tm*spd[l])%360,to=(wdg[l][a][1]+tm*spd[l])%360;

				for(int f=fr;f!=to;f=(f+1)%360)
					used[f]|=(1<<l);

				used[to]|=(1<<l);
			}

		FOR(a,0,360)
			if(used[a]==mat){
				printf("%d\n",tm);
				fnd=1;
				break;
			}

		if(fnd)
			break;
	}
	if(!fnd)
		printf("none\n");

	fclose(stdin);
	fclose(stdout);

	return 0;
}

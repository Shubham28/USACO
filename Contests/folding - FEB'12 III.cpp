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
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())

using namespace std;

int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);

	int N,L;
	float knt[101];

	scanf("%d %d",&N,&L);
	FOR(a,0,N)
		scanf("%f",&knt[a]);

	sort(knt,knt+N);

	int ans=0;
	for(float chk=.5;chk<=L-.5;chk+=.5){
		bool prs=binary_search(knt,knt+N,chk);
		int mat=lower_bound(knt,knt+N,chk)-knt;

		bool yes=1;
		if(prs){
			for(int bck=mat-1,frw=mat+1;bck>=0 && frw<N;bck--,frw++)
				if((knt[mat]-knt[bck])!=(knt[frw]-knt[mat])){
					yes=0;
					break;
				}
		} else {
			for(int bck=mat-1,frw=mat;bck>=0 && frw<N;bck--,frw++)
				if((chk-knt[bck])!=(knt[frw]-chk)){
					yes=0;
					break;
				}
		}
		ans+=yes;
	}
	printf("%d\n",ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

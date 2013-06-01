#include <vector>
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
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

bool cmp(vector<LL>fr,vector<LL>sc)
{
	if(fr[0]+fr[1]<sc[0]+sc[1])			return 1;
	return 0;
}

int main()
{
	freopen("gifts.in","r",stdin);
	freopen("gifts.out","w",stdout);

	int N;
	LL B;
	scanf("%d %lld",&N,&B);

	vector< vector<LL> >cst(N,vector<LL>(2));
	FOR(a,0,N)
		scanf("%lld %lld",&cst[a][0],&cst[a][1]);

	sort(ALL(cst),cmp);

	int ans=0;
	FOR(ch,0,N){
		LL tot=B;
		int cnt=0;

		FOR(a,0,N){
			LL tmp=cst[a][1]+((a==ch)?cst[a][0]/2:cst[a][0]);

			if(tot-tmp>=0)
				tot-=tmp,cnt++;
		}
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

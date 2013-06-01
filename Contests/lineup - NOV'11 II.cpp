#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <set>
#include <numeric>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
#define SZ(A) int(A.size())
#define PII pair<int,int>

using namespace std;

int main()
{
	int N;
	map<int,int>ID;
	PII cord[50005];

	scanf("%d",&N);
	int x,cw,T=0;
	FOR(a,0,N){
		scanf("%d %d",&x,&cw);

		if(ID.find(cw)==ID.end()){
			ID[cw]=T;
			T++;
		}
		cord[a]=PII(x,ID[cw]);
	}
	sort(cord,cord+N);

	int L=0;
	set< PII >opt;
	int last[50005];
	MEM(last,-1);

	int ans=INT_MAX;
	FOR(a,0,N){
		int cw=cord[a].second;
		int x=cord[a].first;

		if(last[cw]!=-1){
			opt.erase( PII(last[cw],cw) );
			L--;
		}

		L++;
		opt.insert( PII(x,cw) );
		last[cw]=x;

		if(L==T)
			ans=min(ans,x-((*opt.begin()).first));
	}
	printf("%d\n",ans);

	return 0;
}

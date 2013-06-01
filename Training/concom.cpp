/*
ID: celesti3
PROG: concom
LANG: C++
*/


#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <set>
#include <numeric>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int V;
bool exs[101],vist[101];
int wts[101][101];

void DFS(int vr,bool com[])
{
	vist[vr]=1;

	bool dn[101];
	MEM(dn,0);

	FOR(ow,0,100){
		if(!exs[ow])	continue;

		if(wts[vr][ow]>50 && !dn[ow]){
			dn[ow]=1;
			if(!vist[ow])
				DFS(ow,dn);

			FOR(cn,0,100)
				wts[vr][cn]+=((vr!=cn)?wts[ow][cn]:0);

			ow=-1;
		}
	}
	FOR(cp,0,100)
		if(dn[cp])
			com[cp]=1;

	return;
}

int main()
{
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);

	int E;
	scanf("%d",&E);
	FOR(in,0,E){
		int fr,to,val;
		scanf("%d %d %d",&fr,&to,&val);

		if(fr==to)  continue;

		wts[fr-1][to-1]=val;
		exs[fr-1]=exs[to-1]=1;
	}

	FOR(vr,0,100)
		if(exs[vr] && !vist[vr]){
			bool tmp[101];
			DFS(vr,tmp);
		}

	FOR(fr,0,100)	FOR(to,0,100){
		if(wts[fr][to]>50)
			printf("%d %d\n",fr+1,to+1);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}

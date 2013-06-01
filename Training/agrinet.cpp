/*
ID: celesti3
PROG: agrinet
LANG: C++
*/


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

int V,E;
int P[105],rnk[105];

struct edge{
	int wt,fr,to;
};

edge data[1000005];

int findPrnt(int node)
{
	if(P[node]!=node)
		P[node]=findPrnt(P[node]);

	return P[node];
}

bool isSame(int fr,int to)
{	return (findPrnt(fr)==findPrnt(to));	}

void unionCmp(int fr,int to)
{
	int pr1=findPrnt(fr),pr2=findPrnt(to);

	if(rnk[pr1]>=rnk[pr2])		P[pr2]=pr1;
	else		P[pr1]=pr2;

	if(rnk[pr1]==rnk[pr2])		++rnk[pr1];

	return;
}

inline bool cmpr(edge fir, edge sec)
{		return (fir.wt<sec.wt);		}

int Kruskal()
{
	sort(data,data+E,cmpr);

	int cost=0;
	FOR(grdy,0,E){
		int st=data[grdy].fr,en=data[grdy].to;
		if(!isSame(st,en)){
			cost+=data[grdy].wt;
			unionCmp(st,en);
		}
	}

	return cost;
}


int main()
{
	freopen("agrinet.in","r",stdin);
	freopen("agrinet.out","w",stdout);

	scanf("%d",&V);
	memset(rnk,0,sizeof(int)*(V+1));
	E=0;

	FOR(nd,0,V){
		P[nd]=nd;

		int val;
		FOR(vrt,0,V){
			scanf("%d",&val);
			if(val==0)
				continue;

			data[E].fr=nd,data[E].to=vrt;
			data[E].wt=val;
			++E;
		}
	}
	printf("%d\n",Kruskal());

	fclose(stdin);
	fclose(stdout);

	return 0;
}

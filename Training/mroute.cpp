#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <queue>
#include <list>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define PII pair<int,int>

using namespace std;

int V,E,X;

list<int>negh[501],L[501],C[501];
list<int>::iterator in,il,ic;

int Dijkstra(int src,int fin)
{
	int dis[V+1],limt[V+1];
	bool dn[V];

	MEM(dis,-1);	MEM(dn,0);
	FOR(i,0,V)		limt[i]=1000001;

	priority_queue< PII, vector< PII >, greater< PII > >que;
	dis[src]=0;
	que.push(PII(0,src));

	while(!que.empty()){
		int val=(que.top()).first,prs=(que.top()).second;
		que.pop();

		if(dn[prs])		continue;

		in=negh[prs].begin(),il=L[prs].begin(),ic=C[prs].begin();

		for(;in!=negh[prs].end();in++,il++,ic++){
			int tmp=*in,chk;

			if(dis[prs]==0)
				chk=(*il)+X/(*ic);
			else
				chk=dis[prs]-X/limt[prs]+(*il)+X/min(limt[prs],(*ic));

			if(dis[tmp]==-1 || dis[tmp]>chk){
				dis[tmp]=chk;
				limt[tmp]=min(limt[prs],(*ic));
				que.push(PII(chk,tmp));
			}
		}
		dn[prs]=1;
		if(dn[fin])
			return dis[fin];
	}
}

int main()
{
	freopen("mroute.in","r",stdin);
	freopen("mroute.out","w",stdout);

	scanf("%d%d%d",&V,&E,&X);

	int fr,to,lt,cp;
	FOR(i,0,E){
		scanf("%d%d%d%d",&fr,&to,&lt,&cp);

		PB(negh[fr-1],to-1);
		PB(L[fr-1],lt);
		PB(C[fr-1],cp);

		PB(negh[to-1],fr-1);
		PB(L[to-1],lt);
		PB(C[to-1],cp);
	}

	cout<<int(Dijkstra(0,V-1))<<"\n";

	fclose(stdin);
	fclose(stdout);

	return 0;
}

/*
ID: celesti3
PROG: butter
LANG: C++
*/


#include <list>
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
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define PII pair<int,int>

using namespace std;

int C,V,E;

list<int>adj[801];
list<int>wts[801];
list<int>::iterator iA,iW;

int cows[801],dist[801];
bool dn[801];

void Dijkstra(int src)
{
	MEM(dist,-1);	MEM(dn,0);

	priority_queue< PII, vector< PII >, greater< PII > >que;
	dist[src]=0;
	que.push(PII(0,src));

	while(!que.empty()){
		int val=(que.top()).first,prs=(que.top()).second;
		que.pop();

		if(dn[prs])		continue;

		for(iA=adj[prs].begin(),iW=wts[prs].begin();iA!=adj[prs].end();iA++,iW++){
			int chk=val+(*iW);
			int tmp=*iA;

			if(dist[tmp]<0 || dist[tmp]>chk){
				dist[tmp]=chk;
				que.push(PII(chk,tmp));
			}
		}
		dn[prs]=1;
	}
	return;
}

int main()
{
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);

	MEM(cows,0);
	scanf("%d %d %d",&C,&V,&E);

	int tmp;
	FOR(a,0,C){
		scanf("%d",&tmp);
		++cows[tmp-1];
	}

	int fr,to,wt;
	FOR(a,0,E){
		scanf("%d %d %d",&fr,&to,&wt);
		fr--,to--;
		PB(adj[fr],to);		PB(wts[fr],wt);
		PB(adj[to],fr);		PB(wts[to],wt);
	}

	int shrt=400000;
	FOR(a,0,V){
		Dijkstra(a);

		int sum=0;
		FOR(rm,0,V)
			sum+=dist[rm]*cows[rm];

		shrt=min(shrt,sum);
	}
	printf("%d\n",shrt);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

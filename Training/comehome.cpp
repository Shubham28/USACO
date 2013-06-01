/*
ID: celesti3
PROG: comehome
LANG: C++
*/


#include <list>
#include <map>
#include <queue>
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
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define PII pair<int,int>

using namespace std;

int V;
map<char,int>ID;
int revID[10001];
list<int>negh[10001],wts[10001];
list<int>::iterator in,iw;

int Dijkstra(int src,char &near)
{
	int dis[V];
	bool dn[V];
	MEM(dis,-1);	MEM(dn,0);

	priority_queue< PII, vector< PII >, greater< PII > >que;
	dis[src]=0;
	que.push(PII(0,src));

	while(!que.empty()){
		int val=(que.top()).first,prs=(que.top()).second;
		que.pop();

		if(dn[prs])		continue;

		for(in=negh[prs].begin(),iw=wts[prs].begin();in!=negh[prs].end();in++,iw++){
			int chk=val+(*iw);
			int tmp=*in;
			if(dis[tmp]<0 || dis[tmp]>chk){
				dis[tmp]=chk;
				que.push(PII(chk,tmp));
			}
		}
		dn[prs]=1;

		char let=revID[prs];
		if('A'<=let && let<='Y'){
			near=let;
			return dis[prs];
		}
	}
}

int main()
{
//	freopen("Input.txt","r",stdin);
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);

	int E;

	V=0;
	scanf("%d",&E);
	FOR(in,0,E){
		char fr,to;
		int val;
		cin>>fr>>to;
		scanf("%d",&val);

		if(ID.find(fr)==ID.end())
			revID[V]=fr,ID[fr]=V++;
		if(ID.find(to)==ID.end())
			revID[V]=to,ID[to]=V++;

		PB(negh[ID[fr]],ID[to]);
		PB(wts[ID[fr]],val);

		PB(negh[ID[to]],ID[fr]);
		PB(wts[ID[to]],val);
	}

	char near;
	int val=Dijkstra(ID['Z'],near);
	printf("%c %d\n",near,val);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

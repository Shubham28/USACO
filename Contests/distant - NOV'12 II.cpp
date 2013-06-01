#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <list>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define MEM(A,B) memset(A,B,sizeof(A))
#define PII pair<int,int>

using namespace std;

int V;
list<int>negh[901],wts[901];
list<int>::iterator in,iw;

int mx;

int dis[901];
bool dn[901];

void Dijkstra(int src)
{
	MEM(dis,-1);	MEM(dn,0);

	priority_queue< PII, vector< PII >, greater< PII > >que;
	dis[src]=0;
	que.push(PII(0,src));

	while(!que.empty()){
		int val=(que.top()).first,prs=(que.top()).second;
		que.pop();

		if(dn[prs])		continue;

		for(in=negh[prs].begin(),iw=wts[prs].begin();in!=negh[prs].end(),iw!=wts[prs].end();in++,iw++){
			int chk=val+(*iw);
			int tmp=*in;
			if(dis[tmp]<0 || dis[tmp]>chk){
				dis[tmp]=chk;
				que.push(PII(chk,tmp));
			}
		}
		dn[prs]=1;
		mx=max(mx,dis[prs]);
	}
}


int main()
{
	freopen("distant.in","r",stdin);
	freopen("distant.out","w",stdout);

	int N,A,B;
	cin>>N>>A>>B;
	V=N*N;

	char grid[31][31];
	FOR(i,0,N)		FOR(j,0,N)
		cin>>grid[i][j];

	int dr[]={-1,0,0,1};
	int dc[]={0,-1,1,0};

	FOR(r,0,N)		FOR(c,0,N)
		FOR(d,0,4){
			int tr=r+dr[d],tc=c+dc[d];
			if(0<=tr && tr<N && 0<=tc && tc<N){
				PB(negh[N*r+c],N*tr+tc);
				PB(wts[N*r+c],(grid[r][c]==grid[tr][tc])?A:B);
			}
		}

	FOR(i,0,V)
		Dijkstra(i);

	cout<<mx<<"\n";

	fclose(stdin);
	fclose(stdout);

	return 0;
}

/*
ID: celesti3
PROG: humble
LANG: C++
*/


#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <set>
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
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);

	int N,K;
	int prm[101];

	set<int>formed,seq;
	set<int>::iterator it;

	priority_queue< PII, vector< PII >, greater< PII > >next;

	scanf("%d %d",&K,&N);
	FOR(a,0,K)
		scanf("%d",&prm[a]);

	FOR(ini,0,K){
		next.push( PII(prm[ini],prm[ini]) );
		formed.insert(prm[ini]);
	}
	seq.insert(1);

	while(N--){
		int val=next.top().first;
		int p=next.top().second;
		next.pop();

		seq.insert(val);

		int qt=val/p;
		it=seq.find(qt);
		it++;
		for(;it!=seq.end();it++){
			int add=(*it)*p;
			if(formed.find(add)==formed.end()){
				formed.insert(add);
				next.push( PII(add,p) );
				break;
			}
		}
	}

	it=seq.end();
	it--;
	printf("%d\n",*it);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

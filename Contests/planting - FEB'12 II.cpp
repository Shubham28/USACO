#include <list>
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
#define SZ(A) int(A.size())
#define LL long long
#define PII pair<int,int>

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int N;
PII R[1001][2];

void swp(int fr,int sc)
{
	swap(R[fr][0],R[sc][0]);
	swap(R[fr][1],R[sc][1]);
	return;
}

/*	Optimize the scan-line by finding x-cordinates which are identical & skipping them.
	Implemented in code using 'nxt' variable.	*/

int main()
{
	Input(N);

	int mn=10000,mx=-10000;
	FOR(i,0,N){
		Input(R[i][0].first),Input(R[i][0].second);
		Input(R[i][1].first),Input(R[i][1].second);

		mn=min(mn,R[i][0].first);
		mx=max(mx,R[i][1].first);
	}

	FOR(fr,0,N-1)	FOR(sc,fr+1,N){
		if(R[fr][0].first>R[sc][0].first)
			swp(fr,sc);
		else if(R[fr][0].first==R[sc][0].first && R[fr][1].first>R[sc][1].first)
			swp(fr,sc);
	}

	int st=0;
	LL tot=0;
	EFOR(x,mn,mx){
		list< PII >reg;
		list< PII >::iterator it;

		int nxt=999999999,ini=-1;
		bool skip=0;
		FOR(a,st,N){
			if(R[a][1].first<=x)
				ini=(!skip)?a:ini;
			else
				skip=1;

			if(R[a][0].first>x){
				nxt=min(nxt,R[a][0].first);
				break;
			} else if(R[a][0].first<=x && x<R[a][1].first){
				nxt=min(nxt,R[a][1].first);
				int st=R[a][1].second,fin=R[a][0].second;

				list< list< PII >::iterator >ers;
				list< list< PII >::iterator >::iterator rem;

				for(it=reg.begin();it!=reg.end();it++){
					int fr=(*it).first,to=(*it).second;

					if(fin<fr || to<st)
						continue;

					st=min(st,fr);
					fin=max(fin,to);
					PB(ers,it);
				}
				for(rem=ers.begin();rem!=ers.end();rem++)
					reg.erase((*rem));

				PB(reg,PII(st,fin));
			}
		}

		for(it=reg.begin();it!=reg.end();it++)
			tot+=(LL)(nxt-x)*(LL)((*it).second-(*it).first);

		x=nxt-1,st=max(st,ini);
	}
	printf("%lld\n",tot);

	return 0;
}

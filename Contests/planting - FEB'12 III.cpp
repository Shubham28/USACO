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
#define PII pair<int,int>

using namespace std;

int main()
{
	freopen("planting.in","r",stdin);
	freopen("planting.out","w",stdout);

	int N;
	PII rect[10][2];

	scanf("%d",&N);

	int mn=10000,mx=-10000;
	FOR(i,0,N){
		scanf("%d %d",&rect[i][0].first,&rect[i][0].second);
		scanf("%d %d",&rect[i][1].first,&rect[i][1].second);

		mn=min(mn,rect[i][0].first);
		mx=max(mx,rect[i][1].first);
	}

	int tot=0;
	EFOR(x,mn,mx){
		list< PII >reg;
		list< PII >::iterator it;


		FOR(a,0,N)
			if(rect[a][0].first<=x && x<rect[a][1].first){
				int st=rect[a][1].second,fin=rect[a][0].second;

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

		for(it=reg.begin();it!=reg.end();it++)
			tot+=((*it).second-(*it).first);
	}
	printf("%d\n",tot);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

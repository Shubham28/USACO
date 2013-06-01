/*
ID: celesti3
PROG: zerosum
LANG: C++
*/


#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define VS vector<string>
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define SZ(A) int(A.size())

using namespace std;

int main()
{
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);

	int N;
	scanf("%d",&N);

	int lim=int(pow(3.0,N-1.)+1e-9);
	short sym[N];
	int val[N+1];

	VS ans;
	FOR(msk,0,lim){

		for(int cnv=msk,dg=0;dg<N-1;dg++,cnv/=3)
			sym[dg]=cnv%3;

		int len=0;
		val[len]=1;

		EFOR(nxt,2,N){
			if(sym[nxt-2]==0)
				val[len]=val[len]*10+nxt;
			else
				val[++len]=nxt;
		}

		int eval=val[0],cur=1;
		FOR(p,0,N-1){
			if(sym[p]==1)
				eval-=val[cur++];
			else if(sym[p]==2)
				eval+=val[cur++];
		}

		if(eval==0){
			string tmp;
			FOR(ps,0,N-1){
				PB(tmp,char('1'+ps));

				if(sym[ps]==0){
					PB(tmp,' ');
				} else if(sym[ps]==1){
					PB(tmp,'-');
				} else if(sym[ps]==2)
					PB(tmp,'+');
			}
			PB(tmp,char('0'+N));
			PB(ans,tmp);
		}
	}
	SORT(ans);
	FOR(ec,0,SZ(ans))
		cout<<ans[ec]<<"\n";


	fclose(stdin);
	fclose(stdout);

	return 0;
}

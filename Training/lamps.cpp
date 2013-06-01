/*
ID: celesti3
PROG: lamps
LANG: C++
*/

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
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int lmp[2][100];
int ln[2];

bool test(int cmb,int chn,bool fin)
{
	FOR(ch,0,ln[chn]){
		bool st=1;
		FOR(msk,0,4)
			if((cmb>>msk)&1){
				if(msk==0)		st=!st;
				else if(msk==1 && (lmp[chn][ch]&1))		st=!st;
				else if(msk==2 && !(lmp[chn][ch]&1))		st=!st;
				else if(msk==3 && (lmp[chn][ch]-1)%3==0)		st=!st;
			}

			if(st!=fin)
				return 0;
		}
	return 1;
}

int main()
{
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);

	int N,C;
	scanf("%d %d",&N,&C);

	int tmp;
	scanf("%d",&tmp);
	while(tmp!=-1){
		lmp[0][ln[0]++]=tmp;
		scanf("%d",&tmp);
	}

	scanf("%d",&tmp);
	while(tmp!=-1){
		lmp[1][ln[1]++]=tmp;
		scanf("%d",&tmp);
	}

	bool ans[20][N+1];
	int L=0;

	FOR(cmb,0,1<<4){
		int ones=__builtin_popcount(cmb);

		if(ones<=C && (ones&1)==(C&1))
			if(test(cmb,0,1) && test(cmb,1,0)){

				MEM(ans[L],0);
				FOR(msk,0,4)
					if((cmb>>msk)&1)
						EFOR(a,1,N){
							if(msk==0)		ans[L][a-1]=!ans[L][a-1];
							else if(msk==1 && (a&1))		ans[L][a-1]=!ans[L][a-1];
							else if(msk==2 && !(a&1))		ans[L][a-1]=!ans[L][a-1];
							else if(msk==3 && (a-1)%3==0)		ans[L][a-1]=!ans[L][a-1];
						}

				FOR(pr,0,N)
					ans[L][pr]=!ans[L][pr];
				L++;
			}
	}
	if(L==0)
		printf("IMPOSSIBLE\n");
	else {
		bool cp[N+1];
		FOR(i,0,L-1)	FOR(j,i+1,L){
			if(memcmp(ans[i],ans[j],sizeof(ans[j]))>0){
				memcpy(cp,ans[i],sizeof(ans[i]));
				memcpy(ans[i],ans[j],sizeof(ans[j]));
				memcpy(ans[j],cp,sizeof(cp));
			}
		}

		FOR(r,0,L){
			FOR(pr,0,N)		printf("%d",ans[r][pr]);
			printf("\n");
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}

/*
ID: celesti3
PROG: stamps
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
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

int main()
{
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);

	int N,K;
	scanf("%d %d",&K,&N);

	int stmp[51];
	FOR(a,0,N)
		scanf("%d",&stmp[a]);

	sort(stmp,stmp+N);

	int minm[10001];
	minm[0]=0;

	int ans=0;
	while(true){
		int chk=ans+1;

		int &lst=minm[chk%10001];
		lst=500;

		FOR(a,0,N){
			if(stmp[a]<=chk)
				lst=min(lst,minm[(chk-stmp[a]+10001)%10001]);
			else
				break;
		}
		if(lst+1>K)
			break;
		else
			++lst,++ans;
	}
	printf("%d\n",ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

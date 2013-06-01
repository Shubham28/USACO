#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define LL long long

using namespace std;

int main()
{
	freopen("cowfind.in","r",stdin);
	freopen("cowfind.out","w",stdout);

	char seq[50005];
	scanf("%s",seq);
	int L=strlen(seq);

	int cumRight[50005];
	cumRight[L]=0;
	RFOR(i,L-1,0){
		cumRight[i]=cumRight[i+1];

		cumRight[i]+=(seq[i]==')' && seq[i+1]==')');
	}

	LL ans=0;
	FOR(i,1,L)
		ans+=((seq[i]=='(' && seq[i-1]=='(')?cumRight[i]:0);

	printf("%lld\n",ans);
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

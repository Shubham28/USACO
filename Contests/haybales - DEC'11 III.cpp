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

using namespace std;

int main()
{
	freopen("haybales.in","r",stdin);
	freopen("haybales.out","w",stdout);

	int N;
	int hts[10001];

	scanf("%d",&N);
	FOR(a,0,N)
		scanf("%d",&hts[a]);

	int sum=accumulate(hts,hts+N,0);
	int orig=sum/N;

	int ans=0;
	FOR(a,0,N)
		if(hts[a]>=orig)
			ans+=(hts[a]-orig);

	printf("%d\n",ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

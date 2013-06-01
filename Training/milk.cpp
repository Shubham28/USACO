/*
ID: celesti3
PROG: milk
LANG: C++
*/


#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <set>
#include <numeric>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);

	int N,F;
	scanf("%d%d",&N,&F);

	vector< VI >mlk(F,VI(2));
	FOR(inp,0,F)
		scanf("%d%d",&mlk[inp][0],&mlk[inp][1]);

	SORT(mlk);

	int tot=0,cost=0;
	for(int chk=0;chk<F && tot<N;chk++){
		if(mlk[chk][1]+tot<=N)
			tot+=mlk[chk][1],cost+=mlk[chk][0]*mlk[chk][1];
		else
			cost+=(N-tot)*mlk[chk][0],tot=N;
	}
	printf("%d\n",cost);


	fclose(stdin);
	fclose(stdout);

	return 0;
}

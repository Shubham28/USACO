/*
ID: celesti3
PROG: milk2
LANG: C++
*/


#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
//	freopen("Input.txt","r",stdin);
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);

	int N;
	scanf("%d",&N);

	vector< VI >mlk(N,VI(2));
	FOR(inp,0,N)
		scanf("%d%d",&mlk[inp][0],&mlk[inp][1]);

	SORT(mlk);
	int one,none=0;
	one=mlk[0][1]-mlk[0][0];

	int str=mlk[0][0],end=mlk[0][1];
	FOR(rem,1,N){
		if(mlk[rem][0]>end){
			one=max(one,end-str);
			none=max(none,mlk[rem][0]-end);
			str=mlk[rem][0],end=mlk[rem][1];
		} else
			end=max(end,mlk[rem][1]);
	}
	printf("%d %d\n",one,none);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

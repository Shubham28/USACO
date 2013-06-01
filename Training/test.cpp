/*
ID: celesti3
PROG: test
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
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <numeric>
#include <sstream>

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
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);

	int fir,sec;
	scanf("%d%d",&fir,&sec);
	printf("%d\n",fir+sec);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

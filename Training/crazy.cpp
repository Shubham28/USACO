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
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int P[1005],rnk[1005];

void createSet(int nm)
{		P[nm]=nm,rnk[nm]=0;		}

int findSet(int nm)
{
	if(nm!=P[nm])
		P[nm]=findSet(P[nm]);

	return P[nm];
}

void mergeSet(int x,int y)
{
	int px=findSet(x);
	int py=findSet(y);

	if(px==py)		return;

	if(rnk[px]>=rnk[py])		P[py]=px;
	else		P[px]=py;

	if(rnk[px]==rnk[py])	rnk[px]++;
	return;
}

int main()
{
//	freopen("crazy.in","r",stdin);
//	freopen("crazy.out","w",stdout);

	int N,C;
	scanf("%d%d",&N,&C);

	map< map<int,int> >polyg;
	map< int,VI >pts;
	int indx=0;

	FOR(i,0,N){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

		if(polyg.find(
	}
	
//	fclose(stdin);
//	fclose(stdout);

	system("pause");

	return 0;
}

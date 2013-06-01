/*
ID: celesti3
PROG: crypt1
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
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int N;
char num[10];

bool selc(int chk)
{
	char buf[5];
	sprintf(buf,"%d",chk);

	FOR(ps,0,3)
		if(find(num,num+N,buf[ps])==(num+N))
			return 0;
	return 1;
}

int main()
{
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);

	scanf("%d",&N);
	FOR(inp,0,N)
		scanf("%1s",&num[inp]);
	sort(num,num+N);

	char fir[5],sec[5];

	int ans=0;
	FOR(dg1,0,N)	FOR(dg2,0,N)	FOR(dg3,0,N)
		FOR(dg4,0,N){
			fir[0]=num[dg1],fir[1]=num[dg2],fir[2]=num[dg3],fir[3]=0;
			sec[0]=num[dg4];

			int prd2=atoi(fir)*(sec[0]-'0');
			if(prd2>=1000)			break;
			else if(!selc(prd2))		continue;

			FOR(dg5,0,N){
				sec[1]=num[dg5],sec[2]=0;

				int prd1=atoi(fir)*(sec[1]-'0');
				if(prd1>=1000)		break;
				else if(!selc(prd1))		continue;

				int fin=prd1+10*prd2;
				if(1000<=fin && fin<=9999 && selc(fin))
					++ans;
			}
		}

	printf("%d\n",ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

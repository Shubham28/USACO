#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <numeric>
#include <utility>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PII pair<int,int>

using namespace std;

int dy[]={-1,0,0,1};
int dx[]={0,-1,1,0};

bool vist[5][5];
int cnt;

int trk[25],nxt=0;

int movCows(PII bes,PII mil)
{
	if(cnt==24){
		PII fin;
		FOR(rw,0,5)		FOR(cl,0,5)
			if(!vist[rw][cl]){
				fin=PII(rw,cl);
				break;
			}

		bool fr=0,sc=0;
		FOR(m,0,4){
			int ty=fin.first+dy[m],tx=fin.second+dx[m];

			if(0<=ty && ty<5 && 0<=tx && tx<5){
				if(PII(ty,tx)==bes)
					fr=1;
				if(PII(ty,tx)==mil)
					sc=1;
			}
		}
		return (fr && sc);
	}

	int tot=0;
	FOR(fr,0,4){
		int y1=bes.first+dy[fr],x1=bes.second+dx[fr];
		if( !(0<=y1 && y1<5 && 0<=x1 && x1<5 && !vist[y1][x1]) )
			continue;

		vist[y1][x1]=1,cnt+=1;
		FOR(sc,0,4){
			int y2=mil.first+dy[sc],x2=mil.second+dx[sc];
			if( !(0<=y2 && y2<5 && 0<=x2 && x2<5 && !vist[y2][x2]) )
				continue;

			vist[y2][x2]=1,cnt+=1;
			tot+=movCows(PII(y1,x1),PII(y2,x2));

			vist[y2][x2]=0,cnt-=1;
		}
		vist[y1][x1]=0,cnt-=1;
	}
	return tot;
}

int main()
{
	freopen("grazing.in","r",stdin);
	freopen("grazing.out","w",stdout);

	MEM(vist,0);
	vist[0][0]=vist[4][4]=1;
	cnt=2;

	int K;
	scanf("%d",&K);

	int rw,cl;
	while(K--){
		scanf("%d %d",&rw,&cl);
		rw--,cl--;
		vist[rw][cl]=1,cnt+=1;
	}

	printf("%d\n",movCows(PII(0,0),PII(4,4)));
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

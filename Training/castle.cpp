/*
ID: celesti3
PROG: castle
LANG: C++
*/

#include <queue>
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

int dr[]={-2,0,0,2};
int dc[]={0,-2,2,0};

int main()
{
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);

	int N,M;
	scanf("%d %d",&M,&N);

	int ar[N+1][M+1];
	int R=2*N+1,C=2*M+1;
	int con[R+5][C+5],room[R+5][C+5];
	MEM(room,-1);

	FOR(rw,0,N)		FOR(cl,0,M)
		scanf("%d",&ar[rw][cl]);

	FOR(rw,0,N)		FOR(cl,0,M){
		int x=rw<<1,y=cl<<1;
		con[x][y]=con[x][y+2]=con[x+2][y]=con[x+2][y+2]=0;
		con[x+1][y+1]=-1;

		con[x][y+1]=((ar[rw][cl]>>1)&1)?0:-1;
		con[x+1][y]=(ar[rw][cl]&1)?0:-1;
		con[x+1][y+2]=((ar[rw][cl]>>2)&1)?0:-1;
		con[x+2][y+1]=((ar[rw][cl]>>3)&1)?0:-1;
	}

	int pv[2505][2];
	int ln=0,cmpn=1,larg=0;

	for(int rw=1;rw<R;rw+=2)	for(int cl=1;cl<C;cl+=2)
		if(con[rw][cl]==-1){
			ln=0;
			pv[ln][0]=rw,pv[ln++][1]=cl;

			queue<int>br;
			br.push(rw); br.push(cl);
			con[rw][cl]=cmpn;

			while(!br.empty()){
				int x=br.front();	br.pop();
				int y=br.front();	br.pop();

				FOR(m,0,4){
					int tx=x+dr[m],ty=y+dc[m];

					if(con[x+dr[m]/2][y+dc[m]/2]==-1)
						if(0<=tx && tx<R && 0<=ty && ty<C && con[tx][ty]==-1){
							con[tx][ty]=cmpn;
							pv[ln][0]=tx,pv[ln++][1]=ty;

							br.push(tx);	br.push(ty);
						}
				}
			}
			FOR(fl,0,ln)
				room[pv[fl][0]][pv[fl][1]]=ln;

			larg=max(larg,ln);
			cmpn++;
		}

	int bst=0,opr,opc;
	char dirn;

	for(int cl=1;cl<C;cl+=2)	for(int rw=R-2;rw>=0;rw-=2)
		for(int mv=0;mv<=2;mv+=2){
			int wx=rw+dr[mv]/2,wy=cl+dc[mv]/2;
			int cx=rw+dr[mv],cy=cl+dc[mv];

			if(0<=cx && cx<R && 0<=cy && cy<C)
				if(con[cx][cy]!=con[rw][cl])
					if(bst<room[rw][cl]+room[cx][cy]){
						bst=room[rw][cl]+room[cx][cy];

						if(mv==0){
							dirn='N';
							opr=wx/2+1,opc=(wy+1)/2;
						} else {
							dirn='E';
							opr=(wx+1)/2,opc=wy/2;
						}
					}
		}

	printf("%d\n%d\n%d\n",cmpn-1,larg,bst);
	printf("%d %d %c\n",opr,opc,dirn);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

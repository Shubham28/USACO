/*
ID: celesti3
PROG: cowtour
LANG: C++
*/


#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <numeric>
#include <set>
#include <fstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define LD long double

using namespace std;

inline LD distn(int co1[],int co2[])
{
	LD x2=pow(co1[0]-co2[0],2);
	LD y2=pow(co1[1]-co2[1],2);

	return sqrt(x2+y2);
}

int main()
{
	freopen("cowtour.in","r",stdin);
	freopen("cowtour.out","w",stdout);

	int V;
	int cord[151][2],matr[151][151];
	LD dist[151][151];

	scanf("%d",&V);
	FOR(c,0,V)
		scanf("%d %d",&cord[c][0],&cord[c][1]);

	char tmp[151];
	FOR(r,0,V){
		scanf("%s",tmp);
		FOR(e,0,V)
			matr[r][e]=tmp[e]-'0';
	}
	FOR(r,0,V)
		FOR(c,0,V){
			if(matr[r][c])
				dist[r][c]=distn(cord[r],cord[c]);
			else
				dist[r][c]=1e12;
		}

	FOR(intr,0,V)
		FOR(frm,0,V){
			if(dist[frm][intr]>1e11)
				continue;

			FOR(to,0,V){
				if(frm==to || dist[intr][to]>1e11)
					continue;

				LD chk=dist[frm][intr]+dist[intr][to];
				dist[frm][to]=min(dist[frm][to],chk);
				matr[frm][to]|=(matr[frm][intr]&matr[intr][to]);
			}
		}

	int comp[V+1];
	MEM(comp,-1);

	LD diam[V+1];									//	Diameter of components
	MEM(diam,0);

	int cnct=1;
	for(int fr=0;fr<V;fr++){
		if(comp[fr]==-1)
			comp[fr]=cnct++;

		FOR(to,fr+1,V)
			if(matr[fr][to]){
				comp[to]=comp[fr];
				diam[comp[to]]=max(diam[comp[to]],dist[fr][to]);
			}
	}

	LD frth[V+1];
	MEM(frth,0);

	FOR(fr,0,V)
		FOR(to,0,V)
			if(fr!=to && comp[fr]==comp[to])
				frth[fr]=max(frth[fr],dist[fr][to]);

	LD ans=1e11;
	FOR(fr,0,V)
		FOR(to,0,V){
			if(comp[fr]!=comp[to]){
				LD oldDm=max(diam[comp[fr]],diam[comp[to]]);
				LD newDm=frth[fr]+frth[to]+distn(cord[fr],cord[to]);

				ans=min(ans,max(oldDm,newDm));
			}
		}

	printf("%.6Lf\n",ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

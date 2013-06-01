/*
ID: celesti3
PROG: rect1
LANG: C++
*/


#include <vector>
#include <map>
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
#define PB(A,B) A.push_back(B);
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
#define SZ(A) int(A.size())
#define PII pair<int,int>

using namespace std;

struct region{
	int strt,end;
	region *left,*rgt;
	bool emp;
};

map<int,int>area;

void cnstr(struct region *now,int &col,int frm,int to)
{
	if(now->emp){
		now->strt=frm,now->end=to;
		now->emp=0;

		struct region *tmp1,*tmp2;
		tmp1=new region;
		tmp2=new region;
		tmp1->emp=tmp2->emp=1;
		tmp1->left=tmp2->rgt=NULL;
		now->left=tmp1,now->rgt=tmp2;

		area[col]+=(to-frm+1);

	} else {
		int tlf=now->strt,trt=now->end;

		if(tlf<=frm && to<=trt)		return;

		if(frm<tlf && trt<to){
			cnstr(now->left,col,frm,tlf-1);
			cnstr(now->rgt,col,trt+1,to);
		} else if(frm<tlf)
			cnstr(now->left,col,frm,min(to,tlf-1));
		else if(trt<to)
			cnstr(now->rgt,col,max(frm,trt+1),to);
	}
	return;
}

int main()
{
	freopen("rect1.in","r",stdin);
	freopen("rect1.out","w",stdout);

	int X,Y,N;
	scanf("%d %d %d",&X,&Y,&N);

	int ID[2505];
	PII rect[2505][2];

	ID[0]=1;
	rect[0][0]=PII(0,0);
	rect[0][1]=PII(X-1,Y-1);

	EFOR(a,1,N){
		scanf("%d %d",&rect[a][0].first,&rect[a][0].second);
		scanf("%d %d",&rect[a][1].first,&rect[a][1].second);
		--rect[a][1].first,--rect[a][1].second;

		scanf("%d",&ID[a]);
	}

	FOR(yAx,0,Y){
		region *root=new region;
		root->emp=1;
		root->left=root->rgt=NULL;

		RFOR(a,N,0)
			if(rect[a][0].second<=yAx && yAx<=rect[a][1].second)
				cnstr(root,ID[a],rect[a][0].first,rect[a][1].first);
	}

	map<int,int>::iterator it;
	for(it=area.begin();it!=area.end();it++)
		printf("%d %d\n",(*it).first,(*it).second);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

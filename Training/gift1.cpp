/*
ID: celesti3
PROG: gift1
LANG: C++
*/


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
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int N;
char names[11][16];

int findPos(char word[16])
{
	FOR(pos,0,N)
		if(strcmp(names[pos],word)==0)
			return pos;

}

int main()
{
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);

	int acnt[11],initial[11];
	memset(acnt,0,sizeof(acnt));
	Input(N);

	FOR(inp,0,N){
		scanf("%s",names[inp]);
		acnt[inp]=0;
	}

	FOR(inp,0,N){
		char tmp[16];
		scanf("%s",tmp);

		int tot,giver;
		Input(tot),Input(giver);
		int plc=findPos(tmp);
		acnt[plc]+=tot;
		initial[plc]=tot;

		if(giver!=0){
			int each=tot/giver;

			FOR(all,0,giver){
				char match[16];
				scanf("%s",match);

				acnt[findPos(match)]+=each;
			}
			acnt[plc]-=(each*giver);
		}
	}

	FOR(prn,0,N)
		printf("%s %d\n",names[prn],acnt[prn]-initial[prn]);

	fclose(stdin);
	fclose(stdout);

	return 0;
}

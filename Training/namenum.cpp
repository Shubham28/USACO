/*
ID: celesti3
PROG: namenum
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

string dict[5000];
string pad="ABCDEFGHIJKLMNOPRSTUVWXY";
int L,N=0;
char num[15],name[15];
bool none=1;

void combn(int pos)
{
	if(pos==L){
		name[L]=0;
		string chk(name);
		if(binary_search(dict,dict+N,chk))
			printf("%s\n",name),none=0;
		return;
	}

	FOR(all,0,3){
		int val=num[pos]-'2';
		name[pos]=pad[val*3+all];
		combn(pos+1);
	}
	return;
}

int main()
{
	freopen("dict.txt","r",stdin);
	while(cin>>dict[N++]);
	fclose(stdin);

	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);

	scanf("%s",num);
	L=strlen(num);
	combn(0);
	if(none)
		printf("NONE\n");

	fclose(stdin);
	fclose(stdout);

	return 0;
}

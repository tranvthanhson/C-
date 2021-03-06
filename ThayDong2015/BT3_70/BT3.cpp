#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<stdlib.h>

using namespace std;
typedef long long ll;
ifstream fi("BT3.INP");
ofstream fo("BT3.OUT");
ll n,kq,f[102][102],d[102];
string ch;

long long tinh(ll i,ll c)
{
	ll sl;
	if(i>n) return (c==0);
	if(f[i][c]>-1) return (f[i][c]);
	sl=tinh(i+1,c+1);
	if(c>0&&d[i]==0)
		sl+=tinh(i+1,c-1);
	f[i][c]=sl;	
	return sl;	
}

string xuly(ll x)
{
	string str="",tmp="";
	int dem=0;
	while(x>0)
	{
		str+=(char)(x%10+48);
		x/=10;
		dem++;
	}
	for(int i=dem-1;i>dem-6;i--)
		tmp+=str[i];
	tmp+="...";	
	for(int i=4;i>=0;i--)
		tmp+=str[i];
	return tmp;	
}
int main()
{
	while(fi>>n)
	{	
		memset(d,0,sizeof(d));
		fi>>ch;
		int null=0;
		for(int i=0;i<ch.size();i++)
		{
			if(ch[i]>='0'&&ch[i]<='9')
			{
				null=null*10+(ch[i]-48);
			}
			else if(null>0)
			{
				d[null]=1;
				null=0;
			}
		}
		
		memset(f,-1,sizeof(f));
		kq=tinh(1,0);
		if(kq<10000000000)
			fo<<kq<<endl;
		 else fo<<xuly(kq)<<endl;	
	}
}


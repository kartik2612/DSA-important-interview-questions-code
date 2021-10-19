#include<bits/stdc++.h>
using namespace std;
#define max 256

void badchar_func(string txt,string pat,vector<int> &badchar)
{
	int size=pat.size();
	char k='*';
	for(int i=0;i<pat.size()-1;i++)
	{
		badchar[(int)pat[i]]=size-i-1;
	}
	badchar[(int)'*']=size;
	badchar[(int)pat[size-1]]=size;
}

void search(string &txt,string &pat)
{
	int n=txt.size();
	int m=pat.size();
	vector<int> badchar;
	badchar_func(txt,pat,badchar);
	int shift=0;
	
	vector<int> :: iterator it;
	while(shift<=(n-m))
	{
		int j=m-1;
		while(j>=0 && pat[j]==txt[shift+j])
		{
			j--;
		}
		if(j<0)
		{
			cout<<"pattern found at "<<shift<<endl;
			it=find(badchar.begin(),badchar.end(),(int)txt[shift+j]);
			if(it!=badchar.end())
			{
				shift+=badchar[(int)txt[shift+j]];
			}
			else
			{
				shift+=badchar[(int)'*'];
			}
		}
		else
		{
			shift+=badchar[(int)txt[shift+j]];
		}
	}
}

int main()
{
	string txt;
	cin>>txt;
	string pat;
	cin>>pat;
	search(txt,pat);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

/*int main()
{
	string p;
	cout<<"Enter pages: "<<endl;
	getline(cin,p);
	vector<string> pages;
	cout<<"Enter number of frames: "<<endl;
	int frames;
	cin>>frames;
	for(i=0;i<p.size();i++)
	{
		if(p[i]==' ')
		{
			pages.push_back(temp);
			temp="";
		}
		else
		{
			temp+=p[i];
		}
	}
	if(temp!="")
	{
		pages.push_back(temp);
	}
*/

void fifo(vector<int>& pages,int frames)
{
	unordered_set<int> s;
	queue<int> q;
	int i,j;
	int hits=0;
	
	for(i=0;i<pages.size();i++)
	{
		if(s.size()<frames)
		{
			if(s.find(pages[i])==s.end())
			{
				s.insert(pages[i]);
				q.push(pages[i]);
			}
			else
			{
				hits++;
			}
		}
		else
		{
			if(s.find(pages[i])==s.end())
			{
				int ele=q.front();
				q.pop();
				s.erase(ele);
				s.insert(pages[i]);
				q.push(pages[i]);	
			}
			else
			{
				hits++;
			}
		}
		/*for(auto itr:s)
		{
			cout<<itr<<" ";
		}
		cout<<endl;*/
	}
	float hit_ratio=((float)hits)/(pages.size());
	float miss_ratio=1-hit_ratio;
	cout<<"Hit-ratio is "<<hit_ratio<<endl;
	cout<<"Miss ratio is "<<miss_ratio<<endl;
}

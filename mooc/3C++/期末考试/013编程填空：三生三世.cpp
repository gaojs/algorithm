#include<iostream>
#include<cstring>
#include<list>
#include<algorithm>
using namespace std;

class TV_Drama
{
public:
	char name[100];
	int actor;
	int story;
	int acting_skill;
// 在此处补充你的代码

	TV_Drama(char*_name, int _actor, int _story, int _acting_skill)
	{
		strcpy(name,_name);
		actor=_actor;
		story=_story;
		acting_skill=_acting_skill;		
	}
	
	bool operator<(const TV_Drama& b)
	{//sort(a,a+n);
		return actor>b.actor;
	}
 
};

bool comparator_1(const TV_Drama& a, const TV_Drama& b)
{//sort(a,a+n,cmp);
	return a.story>b.story; 
}
 
struct comparator_2
{//sort(a,a+n,cmp());
	bool operator()(const TV_Drama& a, const TV_Drama& b)
	{
		return a.acting_skill>b.acting_skill; 
	}
};

struct cmp 
{// function object type:
	void operator() (TV_Drama& a) 
	{
		cout<<a.name<<";";
	}
} Printer;

void Printer2 (TV_Drama& a) 
{// function:
	cout<<a.name<<";";
} 
// 在此处补充你的代码

 
int main(){
	list<TV_Drama> lst;
	int n;
	
	cin>>n;
	char  _name[100];
	int _actor, _story, _acting_skill;
	for (int i=0; i<n; i++)
	{
        cin.ignore();
        cin.getline(_name,100);
        cin>>_actor>>_story>>_acting_skill;
		lst.push_back(TV_Drama(_name, _actor, _story, _acting_skill));
	}

	lst.sort();
	for_each(lst.begin(), lst.end(), Printer);	
	cout<<endl;

	lst.sort(comparator_1);
	for_each(lst.begin(), lst.end(), Printer);	
	cout<<endl;

	lst.sort(comparator_2());
	for_each(lst.begin(), lst.end(), Printer);	
	cout<<endl;

	return 0;
}

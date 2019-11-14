#include<iostream>
#include<map>
using namespace std;

multimap<int,int> mp;
int main() {
//	freopen("F:\\in.txt","r",stdin);
	map<int,int>::iterator it,itl,t;
	int n,i,id,pw,mid;
	cin>>n;
	mp.clear();
	mp.insert(make_pair(1e9,1));
	for(i=0; i<n; i++) {
		scanf("%d %d",&id,&pw);
		it=mp.upper_bound(pw);
		mid=it->second;
		if(it!=mp.begin()) { 
			itl=it;
			itl--;
			if(it->first-pw<pw-itl->first)							
				mid=it->second; 	
			if(it->first-pw>pw-itl->first)						
				mid=itl->second; 	
			if(it->first-pw<=pw-itl->first)
				for(t=it; t->first==it->first&&t!=mp.end(); t++) {
					if(mid>t->second)mid=t->second;	
				}
			if(it->first-pw>=pw-itl->first)
				for(t=itl; t->first==itl->first&&t!=mp.end(); t--){
					if(mid>t->second)mid=t->second;	
				}
		}else{
			for(t=it; t->first==it->first&&t!=mp.end(); t++) {
				if(mid>t->second)mid=t->second;	
			}
		}
		cout<<id<<" "<<mid<<endl;
		mp.insert(make_pair(pw,id));
	}
	return 0;
}

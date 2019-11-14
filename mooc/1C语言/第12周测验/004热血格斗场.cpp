#include<iostream>
#include<map>
using namespace std;

map<int,int> mp;
int main() {
//	freopen("F:\\aain.txt","r",stdin);
	map<int,int>::iterator it,itl;
	int n,i,id,pw;
	cin>>n;		
//	cout<<"n=" <<n<<endl;
	mp.clear();
	mp.insert(make_pair(1e9,1));
//	for(it=mp.begin();it!=mp.end();it++){
//		cout<<"begin=it:"<<it->first<<","<<it->second<<endl; 
//	}
	for(i=0; i<n; i++) {
		scanf("%d %d",&id,&pw);
//		cout<<"id="<<id<<",pw="<<pw<<endl;
		it=mp.upper_bound(pw);
		if(it==mp.begin()){ //找到第一个 
			cout<<id<<" "<<it->second<<endl;
		} else {
			itl=it;
			itl--;//找到左侧的一个 
			if(it->first-pw<pw-itl->first){
				cout<<id<<" "<<it->second<<endl;
			} else{
				cout<<id<<" "<<itl->second<<endl;
			}
		} 
		mp.insert(make_pair(pw,id));		
	}
	return 0;
}
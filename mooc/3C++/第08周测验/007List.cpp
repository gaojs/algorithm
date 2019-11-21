#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

int main() {
	//freopen("F:\\aain.txt","r",stdin);
	map<int,list<int>> m;
	int n,i,id,id2,e;
	string s;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> s;
		if (s == "new") {
			cin >> id;
			m[id]= *(new list<int>);
		} else if(s == "add") {
			cin >> id >> e;
			m[id].push_back(e);
			m[id].sort();
		} else if (s == "merge") {
			cin >> id >> id2;
			m[id].merge(m[id2]);
			m[id].sort();
		} else if (s == "unique") {
			cin >> id;
			m[id].unique();
		} else if (s == "out") {
			cin >> id;
			for (list<int>::iterator i = m[id].begin();
			        i != m[id].end(); i++) {
				cout << *i << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

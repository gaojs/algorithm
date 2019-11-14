#include <iostream>
using namespace std;

class MyCin {
		// 在此处补充你的代码
		bool done;
	public:
		MyCin():done(false) {
		}
		operator bool() {
			return !done;
		}
		MyCin &operator>>(int &t) {
			if(!done) {
				cin>>t;
				if(t==-1) {
					done=true;
				}
			}
			return *this;
		}
};

int main() {
	MyCin m;
	int n1,n2;

	freopen("F:\\aain.txt","r",stdin);
	while( m >> n1 >> n2)
		cout  << n1 << " " << n2 << endl;
	return 0;
}

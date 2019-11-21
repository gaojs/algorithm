#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString {
		char * p;
	public:
		MyString(const char * s) {
			if( s) {
				p = new char[strlen(s) + 1];
				strcpy(p,s);
			} else {
				p = NULL;
			}
		}
		~MyString() {
			if(p) delete [] p;
		}
// 在此处补充你的代码
		MyString& operator=(MyString &ms) {
			p = new char[strlen(ms.p) + 1];
			strcpy(p,ms.p);
			return *this;
		}
		
		void Copy(const char * s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		
		friend ostream & operator<<(ostream &out, MyString &ms) {
			out<<ms.p;
			return out;
		}
		
		MyString &operator=(const char *s){
			p = new char[strlen(s) + 1];
			strcpy(p,s);
			return *this;			
		} 
// 在此处补充你的代码
};


int main() {
//	freopen("F:\\aain.txt","r",stdin);
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
//		cout<<w1<<","<<w2<<endl; 
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

//		s2 = w2;
//		s3 = s2;
//		s1 = s3;
//		cout << s1 << "," << s2 << "," << s3 << endl;
	}
}

#include <cstdlib>
#include <iostream>
using namespace std;

int strlen(const char * s) {
	int i = 0;
	for(; s[i]; ++i);
	return i;
}

void strcpy(char * d,const char * s) {
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
}

int strcmp(const char * s1,const char * s2) {
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}

void strcat(char * d,const char * s) {
	int len = strlen(d);
	strcpy(d+len,s);
}

class MyString {
		// 在此处补充你的代码
	public:
		char *ps;
		int len;

		MyString() {
			ps=new char[1];
			ps[0]=0;
			len=0;
		}
		~MyString() {
			if(ps) delete []ps;
			ps=NULL;
			len=0;
		}

		MyString(const char *str) {
			len=strlen(str);
			ps = new char[len+1];
			strcpy(ps,str);
		}
		MyString(const MyString &ms) {
			len=ms.len;
			ps = new char[len+1];
			strcpy(ps,ms.ps);
		}

		friend ostream &operator<<(ostream &out, const MyString &ms) {
			out<<ms.ps;
			return out;
		}

		MyString &operator=(const MyString &ms) {
			if(ps==ms.ps) return *this;
			if(ps) delete []ps;
			len=ms.len;
			ps=new char[len+1];
			strcpy(ps,ms.ps);
			return *this;
		}

		MyString operator+(const MyString &ms) const {
			char *pstr=new char[len+ms.len+1];
			strcpy(pstr,ps);
			strcat(pstr,ms.ps);
			return MyString(pstr);
		}
		friend MyString operator+(const char* ps, const MyString &ms) {			
			char *pstr=new char[strlen(ps)+ms.len+1];
			strcpy(pstr,ps);
			strcat(pstr,ms.ps);
			return MyString(pstr);			
		}

		MyString &operator+=(const MyString &ms) {
			len +=ms.len;
			char *pstr=new char[len+1];
			strcpy(pstr,ps);
			strcat(pstr,ms.ps);
			if(ps) delete []ps;
			ps=pstr;
			return *this;
		}

		char &operator[](const int i) {
			return ps[i];
		}


		MyString operator()(int s, int l) const {
			if(l+s>len) {
				l=len-s;
			}
			if(s>=len) {
				return MyString("");
			}
			char *pstr = new char[l+1];
			int i = 0;
			for(;i<l;i++){
				pstr[i]=ps[s+i];
			}
			pstr[i]=0;
			return MyString(pstr);
		}
		
		bool operator<(const MyString &ms){
			return strcmp(ps,ms.ps)<0?true:false;
		} 
		bool operator==(const MyString &ms){
			return strcmp(ps,ms.ps)==0?true:false;
			
		} 
		bool operator>(const MyString &ms){
			return strcmp(ps,ms.ps)>0?true:false;			
		} 
};


int CompareString( const void * e1, const void * e2) {
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
		return -1;
	else if( *s1 == *s2)
		return 0;
	else if( *s1 > *s2 )
		return 1;
}

int main() {
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0; i < 4; i ++ )
		cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}

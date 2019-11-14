#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int MAX = 210;
class CHugeInt {
// �ڴ˴�������Ĵ���
	public:
		char s[MAX];

		//���洢���ݵ�����������������������ʽ����ӵ�λ���λ���е�ԭ��
		void reverse(char *p) {
			int len=strlen(p);
			for(int i=0,j=len-1; i<j; ++i,--j) {
				swap(p[i],p[j]);
			}
		}

		CHugeInt() {
			memset(s,0,sizeof(s));
		}
		CHugeInt(int n) {
			memset(s,0,sizeof(s));
			sprintf(s,"%d",n);
			reverse(s);
		}
		CHugeInt(const char* str) {
			memset(s,0,sizeof(s));
			strcpy(s, str);
			reverse(s);
		}
		CHugeInt(const CHugeInt &b) {
			memset(s,0,sizeof(s));
			strcpy(s, b.s);
		}
		CHugeInt operator+(const CHugeInt &b) const{
			CHugeInt tmp;
			int carry =0;//��λ
			for(int i=0; i<MAX; i++) {
				char c1=s[i];
				char c2=b.s[i];
				if(c1==0&&c2==0&&carry==0) {
					break;
				}
				if(c1>='0') {
					c1-='0';
				}
				if(c2>='0') {
					c2-='0';
				}
				int k=c1+c2+carry;
				if(k>=10) { //��Ӵ���10���λ
					carry=1; //��λλ��1
					tmp.s[i]=k-10+'0';
				} else {
					carry=0;
					tmp.s[i]=k+'0';
				}
			}
			return tmp;
		}
		CHugeInt &operator++() { //++a
			*this=*this+1;
			return *this;
		}
		CHugeInt operator++(int) { //a++
			CHugeInt tmp(*this);
			*this=*this+1;
			return tmp;
		}
		CHugeInt &operator+=(int n) { //a+=n
			*this=*this+n;
			return *this;
		}
		friend CHugeInt operator+(const int n, const CHugeInt &a) {
			return a+n;
		}
		friend ostream &operator<<(ostream &out, const CHugeInt &a) {
			int len=strlen(a.s);
			for(int i=len-1; i>=0; --i) {
				cout<<a.s[i];
			}
			return out;
		}
};

int  main() {
	freopen("F:\\aain.txt","r",stdin);
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout << ++b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}

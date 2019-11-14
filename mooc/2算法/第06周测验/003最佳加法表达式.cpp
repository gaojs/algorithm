#include<bits/stdc++.h>
#include<cstring>
#include<stdlib.h>
using namespace std;
const int MaxLen = 55;
const string maxv = "999999999999999999999999999999999999999999999999999999999";
string ret[MaxLen][MaxLen];
string num[MaxLen][MaxLen];
int cmp(string &num1,string &num2) {
	int l1 = num1.length();
	int l2 = num2.length();
	if (l1 != l2) {
		return l1-l2;
	} else {
		for (int i=l1-1; i>=0; i--) {
			if (num1[i]!=num2[i]) {
				return num1[i]-num2[i];
			}
		}
		return 0;
	}
}
void add (string &num1,string &num2,string &num3) {
	//加法从低位到高位相加，那么需要将字符串倒过来
	int l1 = num1.length();
	int l2 = num2.length();
	int maxl = MaxLen,c = 0;        //c是进位标志
	for (int i=0; i<maxl; i++) {
		int t;
		if (i < l1 && i < l2) {
			t = num1[i]+num2[i]-2*'0'+c;
		} else if (i < l1 && i >= l2) {
			t = num1[i] - '0' + c;
		} else if (i >= l1 && i < l2) {
			t = num2[i] - '0' + c;
		} else {
			break;
		}
		num3.append(1,t%10+'0');
		c = t/10;
	}
	while (c) {
		num3.append(1,c%10+'0');
		c /= 10;
	}
}
int main() {
	int m;                  //加号数目
	string str;             //输入的字符串
	while(cin >> m >> str) {
		//为了之后的加法计算先将这个字符串倒过来
		reverse(str.begin(),str.end());
		int n = str.length();
		for (int i=0; i<n; i++) {
			num[i+1][i+1] = str.substr(i,1);
		}
		for (int i=1; i<=n; i++) { //求解对应的num[i][j]
			for (int j=i+1; j<=n; j++) {
				num[i][j] = str.substr(i-1,j-i+1);
			}
		}
		//当加号数目为0
		for (int i=1; i<=n; i++) {
			ret[0][i] = num[1][i];
		}
		for (int i=1; i<=m; i++) { //对于加号数目的枚举
			for (int j=1; j<=n; j++) { //对于长度的枚举
				string minv = maxv;
				string tmp;
				for (int k=i; k<=j-1; k++) {
					tmp.clear();
					add(ret[i-1][k],num[k+1][j],tmp);
					if (cmp(minv,tmp)>0) {
						minv = tmp;
					}
				}
				ret[i][j] = minv;
			}
		}
		//将原先颠倒的字符串倒回来
		reverse(ret[m][n].begin(),ret[m][n].end());
		cout << ret[m][n] << endl;
	}
	return 0;
}

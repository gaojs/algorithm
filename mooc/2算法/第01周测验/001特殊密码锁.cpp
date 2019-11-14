#include<iostream>
#include<cstring>
#include<cmath>
#include<bitset>
using namespace std;

int flags(int LEN, int t) { //操作锁l的第t位
	int f=1<<t; //当前位
	if(t>0) { //左侧
		f|=1<<(t-1);
	}
	if(t<LEN-1) { //右侧
		f|=1<<(t+1);
	}
	return f;
}

bool ok(int lock, int result, int LEN, int &oper) { //判断是否可以
//	cout<<"ok() LEN="<<LEN<<",oper="<<bitset<32>(oper)<<endl;
	if(oper&1) { //先操作0位
		lock^=flags(LEN,0);
	}
	for(int t=0; t<LEN-1; t++) { //从低位到高位，依次判断并操作
		if(((lock>>t)&1)!=((result>>t)&1)) { //不等，要操作t+1位
			oper|=1<<(t+1);
//			cout<<"ok() oper="<<bitset<32>(oper)<<endl;
			lock^=flags(LEN,t+1);
//			cout<<"ok() lock="<<bitset<32>(lock)<<",r="<<bitset<32>(result)<<endl;
		}
	}
	if(lock==result) {
		return true;
	}
	return false;
}

int calcBitNum(int oper) { //计算bit位为1的个数
//	cout<<"calc() oper="<<bitset<32>(oper)<<endl;
	int n=0;
	for(; oper>0; oper>>=1) {
		if((oper&1)>0) {
			n++;
		}
	}
	return n;
}

int main() {
//	freopen("F:\\aain.txt","r",stdin);
	char lockStr[32],resultStr[32];
	int lockLen,lock,result,i,min,n,oper;
	cin>>lockStr>>resultStr; //输入字符串
//	cout<<"lockStr="<<lockStr<<",resultStr="<<resultStr<<endl;
	lockLen=strlen(lockStr); //求字符串长度
//	cout<<"lockLen="<<lockLen<<endl;
	for(lock=result=i=0; i<lockLen; i++) {
		lock=(lock<<1)+(lockStr[i]=='0'?0:1); //转成数值
		result=(result<<1)+(resultStr[i]=='0'?0:1); //转成数值
	}
//	cout<<"lock="<<bitset<32>(lock)<<",result="<<bitset<32>(result)<<endl;
	for(min=32,oper=0; oper<2; oper+=1) { //考虑低位有两种情况
		int oper_temp=oper;
		if(ok(lock,result,lockLen,oper_temp)) {//判断是否可以
			n=calcBitNum(oper_temp);//计算按键次数
//			cout<<"n="<<n<<endl;
			if(min>n) { //存在更小的方案
				min=n;
			}
		}
	}
	if(min==32) {
		cout<<"impossible";
	} else {
		cout<<min;
	}
	return 0;
}

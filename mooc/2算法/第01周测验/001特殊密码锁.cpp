#include<iostream>
#include<cstring>
#include<cmath>
#include<bitset>
using namespace std;

int flags(int LEN, int t) { //������l�ĵ�tλ
	int f=1<<t; //��ǰλ
	if(t>0) { //���
		f|=1<<(t-1);
	}
	if(t<LEN-1) { //�Ҳ�
		f|=1<<(t+1);
	}
	return f;
}

bool ok(int lock, int result, int LEN, int &oper) { //�ж��Ƿ����
//	cout<<"ok() LEN="<<LEN<<",oper="<<bitset<32>(oper)<<endl;
	if(oper&1) { //�Ȳ���0λ
		lock^=flags(LEN,0);
	}
	for(int t=0; t<LEN-1; t++) { //�ӵ�λ����λ�������жϲ�����
		if(((lock>>t)&1)!=((result>>t)&1)) { //���ȣ�Ҫ����t+1λ
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

int calcBitNum(int oper) { //����bitλΪ1�ĸ���
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
	cin>>lockStr>>resultStr; //�����ַ���
//	cout<<"lockStr="<<lockStr<<",resultStr="<<resultStr<<endl;
	lockLen=strlen(lockStr); //���ַ�������
//	cout<<"lockLen="<<lockLen<<endl;
	for(lock=result=i=0; i<lockLen; i++) {
		lock=(lock<<1)+(lockStr[i]=='0'?0:1); //ת����ֵ
		result=(result<<1)+(resultStr[i]=='0'?0:1); //ת����ֵ
	}
//	cout<<"lock="<<bitset<32>(lock)<<",result="<<bitset<32>(result)<<endl;
	for(min=32,oper=0; oper<2; oper+=1) { //���ǵ�λ���������
		int oper_temp=oper;
		if(ok(lock,result,lockLen,oper_temp)) {//�ж��Ƿ����
			n=calcBitNum(oper_temp);//���㰴������
//			cout<<"n="<<n<<endl;
			if(min>n) { //���ڸ�С�ķ���
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

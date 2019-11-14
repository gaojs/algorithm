#include <iostream>
#include <string.h>
using namespace std;
char s1[201],s2[201],s3[402];
int visited[201][201];//������飬�±�ֱ��ʾ��һ���ַ����͵ڶ����ַ����ĳ���
int flag=0;//��ʾ�Ƿ������
int len3;//�������ַ����ĳ���
void dfs(int a,int b,int c);
int main() {
	int n,num=1;
	cin>>n;
	while(n) {
		cin>>s1>>s2>>s3;
		len3=strlen(s3);
		memset(visited,0,sizeof(visited));
		dfs(0,0,0);
		if(flag==1) {
			flag=0;
			cout<<"Data set "<<num<<": yes"<<endl;
		} else {
			cout<<"Data set "<<num<<": no"<<endl;
		}
		num++;
		n--;
	}
	return 0;
}
void dfs(int a,int b,int c) {
	if(flag==1) { //������ϳɹ����������ص��ظ�����
		return;
	}
	if(c==len3) {
		flag=1;
		return;
	}
	if(visited[a][b]==0) { //������ϲ��ɹ����������ص��ظ�����
		visited[a][b]=1;
		if(s1[a]==s3[c])
			dfs(a+1,b,c+1);
		if(s2[b]==s3[c])
			dfs(a,b+1,c+1);
	}
}

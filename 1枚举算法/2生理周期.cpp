//����23�죬����28�죬����33�죬�߷���
//���������߷���ֵ�����p��e��i���Լ�d
//��d֮���´������߷�ͬʱ���ֵ����� 
//input & output sample:
//0 0 0 0		//21252
//0 0 0 100		//21152
//4 5 6 7		//16994
//5 20 34 325	//19575
//283 102 34 325	//1821
//203 301 203 40	//10789
//-1 -1 -1 -1
#include <iostream>
using namespace std;

int main()
{
	const int P=23, E=28, I=33;//���� 
	int p, e, i, d, k;
	
	while(cin>>p>>e>>i>>d)
	{
		if(p<0)
		{
			break;
		}
		for(k=d+1;(k-p)%P!=0;k++);
		for(;(k-e)%E!=0;k+=P);
		for(;(k-i)%I!=0;k+=P*E);
		cout<<k-d<<endl;
	}
	return 0;	
}

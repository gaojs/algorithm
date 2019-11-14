#include <iostream>
#include <iomanip>
using namespace std;
double GetDoubleFromString(char * str)
{
	static char *p=NULL;
	double d=0,i;

	if(str)p=str;
	for(; *p&&(*p<'0'||*p>'9'); p++);
	if(*p==0) return -1;
	for(; *p>='0'&&*p<='9'; p++)
		d=d*10+*p-'0';
	if(*p=='.')	{
		p++;
		for(i=10; *p>='0'&&*p<='9'; p++,i*=10)
			d+=(*p-'0')/i;
	}
	return d;
}

int main()
{
	char line[300];
	while(cin.getline(line,280)) {
		double n;
		n = GetDoubleFromString(line);
		while( n > 0) {
			cout << fixed << setprecision(6) << n << endl;
			n = GetDoubleFromString(NULL);
		}
	}
	return 0;
}
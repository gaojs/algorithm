//http://bailian.openjudge.cn/practice/2977/
//体力23天，情商28天，智商33天，高峰日
//给定三个高峰出现的日子p，e，i，以及d
//求d之后，下次三个高峰同时出现的日子 
//input & output sample:
//4 5 6 7		//16994
#include <iostream>
using namespace std;

int main()
{
	const int P = 23, E = 28, I = 33;//互质 
	int p, e, i, d, k;

	cin >> p >> e >> i >> d;
	for (k = d + 1; (k - p) % P != 0; k++);
	for (; (k - e) % E != 0; k += P);
	for (; (k - i) % I != 0; k += P * E);
	cout << (k - d) << endl;
	return 0;
}

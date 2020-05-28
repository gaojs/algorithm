#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_COUNT 100000
typedef struct {
    int a[MAX_COUNT];
    int cnt;
} MedianFinder;

/** initialize your data structure here. */
MedianFinder* medianFinderCreate() 
{
    static MedianFinder smf;
    memset(&smf, 0, sizeof(smf));
    return &smf;
}

int findPos(int *a, int n, int k)
{ // 二分查找 
	int left = 0, right = n - 1;
	while (left <= right) {
		int m = left + (right - left) / 2;
		if (a[m] == k) { // 找到了 
			return m;
		} else if (a[m] < k) {
			left = m + 1;
		} else {
			right = m - 1;
		}
	}
	return left;
} 
 
void medianFinderAddNum(MedianFinder* mf, int num) 
{
	if(mf == NULL) {
		return;
	} else if (mf->cnt >= MAX_COUNT) {
		printf("overflow");
	} else {
		int pos = findPos(mf->a, mf->cnt, num);
		if ((mf->cnt - pos) > 0) {
			memmove(&mf->a[pos+1], &mf->a[pos], sizeof(int)*(mf->cnt - pos));			
		}
		mf->a[pos] = num;
		mf->cnt++;
	}	
}

double medianFinderFindMedian(MedianFinder* mf) 
{
	if(mf == NULL || mf->cnt<=0) {
		return 0;
	} else {
		if (mf->cnt % 2 == 1) {
			return mf->a[mf->cnt / 2];
		} else {
			int m = mf->cnt / 2;
			double s = mf->a[m];
			s += mf->a[m - 1];
			return (s / 2);
		}
	}  
}

void medianFinderFree(MedianFinder* mf) 
{    
}

int main()
{
	MedianFinder *mf = medianFinderCreate();
	medianFinderAddNum(mf, 6);
	printf("%g ", medianFinderFindMedian(mf));
	medianFinderAddNum(mf, 10);
	printf("%g ", medianFinderFindMedian(mf));
	medianFinderAddNum(mf, 2);
	printf("%g ", medianFinderFindMedian(mf));
	medianFinderAddNum(mf, 6);
	printf("%g ", medianFinderFindMedian(mf));
	medianFinderAddNum(mf, 5);
	printf("%g ", medianFinderFindMedian(mf));
	medianFinderAddNum(mf, 0);
	printf("%g ", medianFinderFindMedian(mf));
	medianFinderAddNum(mf, 6);
	printf("%g ", medianFinderFindMedian(mf));
	medianFinderAddNum(mf, 3);
	printf("%g ", medianFinderFindMedian(mf));
	medianFinderAddNum(mf, 1);
	printf("%g ", medianFinderFindMedian(mf));
	medianFinderAddNum(mf, 0);
	printf("%g ", medianFinderFindMedian(mf));
	medianFinderAddNum(mf, 0);
	printf("%g ", medianFinderFindMedian(mf));
	return 0;
} 


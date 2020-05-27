#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_COUNT 10000
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

void medianFinderAddNum(MedianFinder* mf, int num) 
{
	if(mf == NULL) {
		return;
	} else if (mf->cnt >= MAX_COUNT) {
		printf("overflow");
	} else {
		mf->a[mf->cnt] = num;
		mf->cnt++;
	}	
}

int cmp(const void*a, const void*b) {
	return *(int*)a - *(int*)b;
}

double medianFinderFindMedian(MedianFinder* mf) 
{
	if(mf == NULL || mf->cnt<=0) {
		return 0;
	} else {
		qsort(mf->a, mf->cnt, sizeof(int), cmp);
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
	medianFinderAddNum(mf, 1);
	medianFinderAddNum(mf, 2);
	double d1 = medianFinderFindMedian(mf);
	printf("%g ", d1);
	medianFinderAddNum(mf, 3);
	double d2 = medianFinderFindMedian(mf);
	printf("%g ", d2);
	return 0;
} 


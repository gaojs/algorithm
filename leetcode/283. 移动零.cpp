#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void moveZeroes(int* nums, int numsSize){
    int m = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            m++; // ºÜ¾«Ãî 
        } else if (m > 0) {
            nums[i - m] = nums[i];
            nums[i] = 0;
        }
    }
}


void print(int* nums, int numsSize)
{
	for (int i = 0; i < numsSize; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n"); 
}

int main()
{
	int a[] = {0,1,0,3,12}; 
	int size = sizeof(a)/sizeof(a[0]);
	print(a, size); 
	moveZeroes(a, size); 
	print(a, size); 
	return 0;
}


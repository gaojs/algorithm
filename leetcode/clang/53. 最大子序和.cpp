#include <stdio.h>

int maxSubArray(int* nums, int numsSize)
{
	if ( nums== NULL || numsSize <= 0) {
		return 0;		
	}
	int sum = nums[0]; // 默认为第一项 
	int mx = sum; // 最大值 
	for (int i = 1; i < numsSize; i++) {		
		// printf("sum=%d, n[%d]=%d\n", sum, i, nums[i]);
		if (sum + nums[i] > nums[i]) {
			sum += nums[i]; // 累加 
		} else {
			sum = nums[i]; // 重新计数 
		}
		if (mx < sum) {
			mx = sum; // 更新最大值 
			// printf("mx=%d\n", mx);
		}
	}
	return mx;
}

int main()
{
	int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	printf("%d\n", maxSubArray(nums, numsSize));
	return 0;
}

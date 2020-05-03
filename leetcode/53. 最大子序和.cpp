#include <stdio.h>

int maxSubArray(int* nums, int numsSize)
{
	if ( nums== NULL || numsSize <= 0) {
		return 0;		
	}
	int sum = nums[0]; // Ĭ��Ϊ��һ�� 
	int mx = sum; // ���ֵ 
	for (int i = 1; i < numsSize; i++) {		
		// printf("sum=%d, n[%d]=%d\n", sum, i, nums[i]);
		if (sum + nums[i] > nums[i]) {
			sum += nums[i]; // �ۼ� 
		} else {
			sum = nums[i]; // ���¼��� 
		}
		if (mx < sum) {
			mx = sum; // �������ֵ 
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

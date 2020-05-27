// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
 int n1 = 0;
    int n2 = 0;
    int size = 0;
    int total = (nums1Size + nums2Size);
    int mid =  total / 2;
    int num = 0; // ��Сֵ
    int prev = 0; // ǰһ��
    printf("nums1Size=%d, nums2Size=%d\n", nums1Size, nums2Size);
    while (n1 < nums1Size && n2 < nums2Size) {        
        prev = num;
        num = (nums1[n1] < nums2[n2]) ? nums1[n1] : nums2[n2]; // ��Сֵ
        printf("num=%d, prev=%d\n", num, prev);
        if (size == mid) {
            if (total % 2 == 0) { // ż����ȡ��ֵ
                return (float)(num + prev) / 2;
            } else { // ��������ȡ���
                return num;
            }
        } else {
            if (nums1[n1] > nums2[n2]) {
                n2++;
            } else {
                n1++;
            }
            size++;
        }
    }
    while (n1 < nums1Size) {
        prev = num;
        num = nums1[n1];
        printf("num=%d, prev=%d\n", num, prev);
        if (size == mid) {
            if (total % 2 == 0) { // ż����ȡ��ֵ
                return (float)(num + prev) / 2;
            } else { // ��������ȡ���
                return num;
            }
        } else {                
            n1++;
            size++;
        }
    }    
    while (n2 < nums2Size) {
        prev = num;
        num = nums2[n2];
        printf("num=%d, prev=%d\n", num, prev);
        if (size == mid) {
            if (total % 2 == 0) { // ż����ȡ��ֵ
                return (float)(num + prev) / 2;
            } else { // ��������ȡ���
                return num;
            }            
        } else {
            n2++;
            size++;
        }
    }
    return 0;
}

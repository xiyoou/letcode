#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size,
                             int* nums2, int nums2Size) {
    // 确保 nums1 是较短数组
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;
    int totalLeft = (m + n + 1) / 2;

    int left = 0, right = m;

    while (left <= right) {
        int i = (left + right) / 2;      // nums1 分割点
        int j = totalLeft - i;           // nums2 分割点

        int nums1LeftMax  = (i == 0) ? INT_MIN : nums1[i - 1];
        int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
        int nums2LeftMax  = (j == 0) ? INT_MIN : nums2[j - 1];
        int nums2RightMin = (j == n) ? INT_MAX : nums2[j];

        if (nums1LeftMax <= nums2RightMin &&
            nums2LeftMax <= nums1RightMin) {

            if ((m + n) % 2 == 1) {
                return (double)fmax(nums1LeftMax, nums2LeftMax);
            } else {
                return (fmax(nums1LeftMax, nums2LeftMax) +
                        fmin(nums1RightMin, nums2RightMin)) / 2.0;
            }
        } else if (nums1LeftMax > nums2RightMin) {
            right = i - 1;
        } else {
            left = i + 1;
        }
    }
    return 0.0;
}
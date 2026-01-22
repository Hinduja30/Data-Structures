#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0, k = 0;

    int arr[nums1Size + nums2Size];

    // Merge arrays
    while (i < nums1Size && j < nums2Size) {
        arr[k++] = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];
    }

    while (i < nums1Size)
        arr[k++] = nums1[i++];

    while (j < nums2Size)
        arr[k++] = nums2[j++];

    int newSize = nums1Size + nums2Size;

    // Find median
    if (newSize % 2 == 0) {
        double median = arr[newSize/2] + arr[(newSize/2) - 1];
        return median / 2.0;   // use 2.0 for double division
    } else {
        return arr[newSize/2];
    }
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};

    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int size2 = sizeof(nums2) / sizeof(nums2[0]);

    double result = findMedianSortedArrays(nums1, size1, nums2, size2);

    printf("Median = %.2f\n", result);

    return 0;
}

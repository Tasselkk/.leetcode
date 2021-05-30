/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个正序数组的中位数
 */
// @lc code=start

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    //1.先归并排序
    int *nums3=(int *)malloc(sizeof(int)*(nums1Size+nums2Size));
    int i=0,k=0,j=0;
    while(i<nums1Size&&j<nums2Size)//两个数组都没找完
    {
        if(nums1[i]<=nums2[j])
            nums3[k++]=nums1[i++];
        else
            nums3[k++]=nums2[j++];
    }
    while(i<nums1Size)//数组2已经找完
    {
        nums3[k++]=nums1[i++];
    }
    while(j<nums2Size)//数组1已经找完
    {
        nums3[k++]=nums2[j++];
    }
    //2.再找中位数
    if((nums1Size+nums2Size)%2==0)
        return ((double)nums3[(nums1Size+nums2Size)/2]+(double)nums3[(nums1Size+nums2Size)/2-1])/2;
    else
        return (double)nums3[(nums1Size+nums2Size)/2];
}
// @lc code=end


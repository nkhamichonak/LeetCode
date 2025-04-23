
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int	one_last = m - 1;
	int	two_last = n - 1;
	int	total_last = m + n - 1;

	while (one_last >= 0 && two_last >= 0)
	{
		if (nums1[one_last] >= nums2[two_last])
			nums1[total_last] = nums1[one_last--];
		else
			nums1[total_last] = nums2[two_last--];
		total_last--;
	}
	while (two_last >= 0)
		nums1[total_last--] = nums2[two_last--];
}

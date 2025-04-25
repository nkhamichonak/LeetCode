/*
Solution 1. Uses up more memory due to relying on a copy
of the original array, but is more intuitive.
*/

#include <stdlib.h>

void	rotate(int* nums, int numsSize, int k)
{
	if (k == 0 || numsSize <= 1)
		return ;

	int *copy = malloc(numsSize * sizeof(int));
	if (copy == NULL)
		return ;
	k = k % numsSize;
	for (int i = 0; i < numsSize; i++)
		copy[i] = nums[i];
	for (int j = 0; j < numsSize; j++)
		nums[j] = copy[(j - k + numsSize) % numsSize];
	free(copy);
}

/*
Solution 2. Swaps elements in-place with O(1) extra space
(reverse approach). The trick is to reverse the whole array
first, then reverse the first k elements, and finally
reverse the rest.
*/

void	reverse(int *nums, int start, int end)
{
	while (start < end)
	{
		int temp = nums[start];
		nums[start++] = nums[end];
		nums[end--] = temp;
	}
}

void	rotate(int* nums, int numsSize, int k)
{
	if (k == 0 || numsSize <= 1)
		return ;

	k = k % numsSize;
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);
}

/*
Solution 3. Swaps elements in-place with O(1) extra space
(cycle replacement approach). Elements are moved in cycles
to their correct positions in the rotated array.
*/

void	rotate(int* nums, int numsSize, int k)
{
	if (k == 0 || numsSize <= 1)
		return ;

	k = k % numsSize;
	int count = 0;
	for (int i = 0; count < numsSize; i++)
	{
		int current_pos = i;
		int current_val = nums[i];

		while (1)
		{
			int new_pos = (current_pos + k) % numsSize;
			int temp = nums[new_pos];
			nums[new_pos] = current_val;
			current_pos = new_pos;
			current_val = temp;
			count++;

			if (current_pos == i)
				break ;
		}
	}
}

/*
Solution 1. Prefix and suffix products. Builds prefix products left to right,
then multiplies with suffix products from right to left. Avoids division.
Time: O(n). Space: O(1) extra (excluding output array as per instruction).
*/

#include <stdlib.h>

int*	productExceptSelf(int* nums, int numsSize, int* returnSize)
{
	int	*answer = malloc(numsSize * sizeof(int));
	int	suffix_product = 1;

	if (answer == NULL)
		return (NULL);
	answer[0] = 1;
	for (int i = 1; i < numsSize; i++)
		answer[i] = nums[i - 1] * answer[i - 1];
	for (int j = numsSize - 1; j >= 0; j--)
	{
		answer[j] *= suffix_product;
		suffix_product *= nums[j];
	}
	*returnSize = numsSize;
	return (answer);
}

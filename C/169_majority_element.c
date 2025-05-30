/*
Boyer–Moore Majority Vote Algorithm:

We pair off different elements, cancelling them out.
If every different number cancels one instance of the
majority number, the majority number still wins.
*/

int	majorityElement(int* nums, int numsSize)
{
	int	candidate = nums[0];
	int	count = 1;

	for (int i = 1; i < numsSize; i++)
	{
		if (nums[i] == candidate)
			count++;
		else
			count--;
		if (count == 0)
		{
			candidate = nums[i];
			count = 1;
		}
	}
	return (candidate);
}

int	jump(int* nums, int numsSize)
{
	int	farthest = 0;
	int	current_end = 0;
	int	count = 0;

	for (int i = 0; i < numsSize - 1; i++)
	{
		if (i + nums[i] > farthest)
			farthest = i + nums[i];
		if (i == current_end)
		{
			count++;
			current_end = farthest;
		}
	}
	return (count);
}

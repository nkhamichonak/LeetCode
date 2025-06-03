/*
Solution 1. Greedy approach. Tracks total gas balance and current route
viability. If current tank drops below zero, starting point shifts to next
station. Completing the whole route is only possible if total gas ≥ total cost.
Time: O(n). Space: O(1).
*/

int	canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
	int	start = 0;
	int	current = 0;
	int	total = 0;

	for (int i = 0; i < gasSize; i++)
	{
		total += gas[i] - cost[i];
		current += gas[i] - cost[i];
		if (current < 0)
		{
			current = 0;
			start = i + 1;
		}
	}
	return (total >= 0 ? start : -1);
}

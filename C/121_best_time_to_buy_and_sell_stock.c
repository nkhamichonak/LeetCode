int	maxProfit(int* prices, int pricesSize)
{
	if (pricesSize == 1)
		return (0);

	int profit = 0;
	int buy_idx = 0;
	for (int i = 1; i < pricesSize; i++)
	{
		if (prices[i] - prices[buy_idx] > profit)
			profit = prices[i] - prices[buy_idx];
		if (prices[i] < prices[buy_idx])
			buy_idx = i;
	}
	return (profit);
}

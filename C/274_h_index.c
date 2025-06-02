/*
Solution 1. Bucket sort / counting. Counts how many papers have i citations
(or more). Walks from high to low to find the max h such that at least h papers
have ≥ h citations. Time: O(n). Space: O(n).
*/

int	hIndex(int* citations, int citationsSize)
{
	int	frequencies[citationsSize + 1];
	int	total = 0;

	for (int k = 0; k < citationsSize + 1; k++)
		frequencies[k] = 0;
	for (int i = 0; i < citationsSize; i++)
	{
		if (citations[i] > citationsSize)
			citations[i] = citationsSize;
		frequencies[citations[i]]++;
	}
	for (int j = citationsSize; j >= 0; j--)
	{
		total += frequencies[j];
		if (total >= j)
			return (j);
	}
	return (0);
}

/*
Solution 2. Sort-based. Sorts citations in ascending order and iterates
to find the largest h such that at least h papers have ≥ h citations.
Time: O(n log n). Space: O(1).
*/

int	compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	hIndex(int* citations, int citationsSize)
{
	qsort(citations, citationsSize, sizeof(int), compare);
	for (int i = 0; i < citationsSize; i++)
	{
		int h_idx = citationsSize - i;
		if (citations[i] >= h_idx)
			return (h_idx);
	}
	return (0);
}

/*
Solution 3. First attempt, brute-force. Tries all possible h values
from n down to 0. For each h, count how many papers have at least h
citations. Time: O(n²). Space: O(1).
*/

int	hIndex(int* citations, int citationsSize)
{
	int	h_idx = citationsSize;
	int	count = 0;

	while (h_idx >= 0)
	{
		for (int i = 0; i < citationsSize; i++)
			if (citations[i] >= h_idx)
				count++;
		if (count >= h_idx)
			return (h_idx);
		else
		{
			h_idx--;
			count = 0;
		}
	}
	return (0);
}

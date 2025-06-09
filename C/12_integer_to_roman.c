/*
Solution 1. Uses two arrays: one with integer values and another with corresponding
Roman symbols. Iterates from largest to smallest value, subtracting from the input
number and appending the corresponding symbol to the result until the number becomes 0.
*/

char*	intToRoman(int num)
{
	static char	roman_num[16] = "";
	int			values[13] = {1000, 900, 500, 400, 100, 90,
		50, 40, 10, 9, 5, 4, 1};
	char		*symbols[] = {"M", "CM","D", "CD", "C", "XC",
		"L", "XL","X", "IX","V", "IV","I"};
	int			pos = 0;

	for (int i = 0; i < 13; i++)
	{
		while (num - values[i] >= 0)
		{
			num -= values[i];
			for (int j = 0; symbols[i][j]; j++)
				roman_num[pos++] = symbols[i][j];
		}
	}
	roman_num[pos] = '\0';
	return (roman_num);
}

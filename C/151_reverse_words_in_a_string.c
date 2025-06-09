/*
Solution 1. Reverses the words in a string in-place with O(1) extra space.
Steps:
1. Remove extra spaces (leading, trailing, and multiple in-between).
2. Reverse the entire string.
3. Reverse each word individually to correct the letter order.
*/

void	custom_reverse(char *s, int start, int end)
{
	while (start < end)
	{
		char temp = s[start];
		s[start++] = s[end];
		s[end--] = temp;
	}
}

int	remove_spaces(char *s)
{
	int	read = 0;
	int	write = 0;
	int	len = strlen(s);

	while (s[read] == ' ')
		read++;
	while (read < len)
	{
		while (s[read] && s[read] != ' ')
			s[write++] = s[read++];
		while (s[read] == ' ')
			read++;
		if (s[read])
			s[write++] = ' ';
	}
	s[write] = '\0';
	return (write);
}

char*	reverseWords(char* s)
{
	int	new_len = remove_spaces(s);
	custom_reverse(s, 0, new_len - 1);
	int	i = 0;
	while (i < new_len)
	{
		int j = i;
		while (s[j] && s[j] != ' ')
			j++;
		custom_reverse(s, i, j - 1);
		i = j + 1;
	}
	return (s);
}

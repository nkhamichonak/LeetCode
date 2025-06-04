/*
Solution 1. Traverses the string in reverse, skipping trailing spaces,
then counts the characters in the last word (only alphabetic).
*/

int	lengthOfLastWord(char* s)
{
	int	count = 0;

	for (int i = strlen(s) - 1; i >= 0; i--)
	{
		if (s[i] == ' ' && count)
			break ;
		if (isalpha(s[i]))
			count++;
	}
	return (count);
}

/*
Solution 2. Finds the start of the last word (only alphabetic charachters),
then counts its length by iterating from that point.
*/

int	lengthOfLastWord(char* s)
{
	int	count = 0;
	int	last_word = 0;

	for (int i = 0; s[i]; i++)
		if (s[i] == ' ' && s[i + 1] && isalpha(s[i + 1]))
			last_word = i + 1;
	while (s[last_word] && isalpha(s[last_word++]))
		count++;
	return (count);
}

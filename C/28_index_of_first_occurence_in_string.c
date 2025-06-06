/*
Solution 1. Naïve substring search, checking character-by-character for a match.
*/

int	strStr(char* haystack, char* needle)
{
	for (int i = 0; haystack[i]; i++)
	{
		int j = 0;
		while (haystack[i + j] && needle[j]
			&& haystack[i + j] == needle[j])
				j++;
		if (needle[j] == '\0')
			return (i);
	}
	return (-1);
}

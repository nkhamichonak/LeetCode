/*
Solution 1. Finds the longest common prefix among an array of strings by starting
with the first string as the initial prefix and trimming it as soon as a mismatch
is found in subsequent strings. If at any point the prefix becomes empty, there is
no common prefix and an empty string is returned.
*/

char*	longestCommonPrefix(char** strs, int strsSize)
{
	char	*prefix = strs[0];

	for (int i = 1; i < strsSize; i++)
	{
		int j = 0;
		while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j])
			j++;
		prefix[j] = '\0';
		if (j == 0)
			return ("");
	}
	return (prefix);
}

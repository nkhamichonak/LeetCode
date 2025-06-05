/*
 Solution 1. Converts a Roman numeral string to an integer using
 a 256-entry lookup array. Reads the string in reverse and subtracts
 values when a smaller numeral precedes a larger one.
 */

#include <string.h>

int	romanToInt(char* s)
{
	int	map[256] = {0};
	int	result = 0;

	map['\0'] = 0;
	map['I'] = 1;
	map['V'] = 5;
	map['X'] = 10;
	map['L'] = 50;
	map['C'] = 100;
	map['D'] = 500;
	map['M'] = 1000;

	for (int i = strlen(s) - 1; i >= 0; i--)
	{
		if (map[(unsigned char)s[i]] < map[(unsigned char)s[i + 1]])
			result -= map[(unsigned char)s[i]];
		else
			result += map[(unsigned char)s[i]];
	}
	return (result);
}

/*
Solution 2. Converts a Roman numeral string to an integer using std::map.
Reads the string in reverse and subtracts values when a smaller numeral
precedes a larger one.
 */

#include <string>
#include <map>

class Solution {
	public:
		int romanToInt(std::string s)
		{
			int result = 0;
			int last_idx = s.length() - 1;
			std::map<char, int> values = {{'I', 1}, {'V', 5}, {'X', 10},
				{'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

			for (int i = last_idx; i >= 0; i--)
			{
				if (i != last_idx && values.at(s[i]) < values.at(s[i + 1]))
					result -= values.at(s[i]);
				else
					result += values.at(s[i]);
			}
			return (result);
		}
	};

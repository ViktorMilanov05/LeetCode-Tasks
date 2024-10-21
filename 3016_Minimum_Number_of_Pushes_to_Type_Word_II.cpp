#include <iostream>
#include <vector>
#include <algorithm>

/*You are given a string word containing lowercase English letters.

Telephone keypads have keys mapped with distinct collections 
of lowercase English letters, which can be used to form words
by pushing them. For example, the key 2 is mapped with 
["a","b","c"], we need to push the key one time to 
type "a", two times to type "b", and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 
to distinct collections of letters. The keys can be remapped 
to any amount of letters, but each letter must be mapped to 
exactly one key. You need to find the minimum number of times
the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after
remapping the keys.

An example mapping of letters to keys on a telephone keypad 
is given below. Note that 1, *, #, and 0 do not map to any letters.*/

int minimumPushes(std::string word) {
	const int PUSHABLE_DIGITS = 8;
	std::sort(word.begin(), word.end());
	std::vector<int> countOfChars;
	int count = 1;
	for (size_t i = 1; i < word.size(); i++)
	{
		if (word[i] != word[i - 1]) {
			countOfChars.push_back(count);
			count = 1;
		}
		else {
			count++;
		}
	}
	countOfChars.push_back(count);
	std::sort(countOfChars.begin(), countOfChars.end(), std::greater<int>());
	int pushes = 0;
	int pushForChar = 1;
	for (size_t i = 0; i < countOfChars.size(); i++)
	{
		if (i / 8 == pushForChar)
			pushForChar++;
		pushes += pushForChar * countOfChars[i];
	}
	return pushes;
}

int main()
{
	std::string word = "abcde";
    std::cout << minimumPushes(word);
}

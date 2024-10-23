#include <iostream>
#include <string>
#include <vector>

/*You are given a vector of words, where each word consists entirely of lowercase Latin letters. 
Write a program that rearranges the vector such that all words starting with the letter 'a' 
appear first, followed by words starting with the letter 'b', and so on, in alphabetical order. */

void sortWords(std::vector<std::string>& words) {
	const size_t COUNT_OF_DOMAIN = 26;
	std::vector<int> countArr(COUNT_OF_DOMAIN);
	for (size_t i = 0; i < words.size(); i++)
	{
		countArr[words[i][0] - 'a']++;
	}
	for (size_t i = 1; i < COUNT_OF_DOMAIN; i++)
	{
		countArr[i] += countArr[i - 1];
	}
	std::vector<std::string> res(words.size());
	for (int i = words.size() - 1; i >= 0; i--)
	{
		std::string curr = words[i];
		int ind = --countArr[curr[0] - 'a'];
		res[ind] = curr;
	}
	for (size_t i = 0; i < words.size(); i++)
	{
		words[i] = res[i];
	}
}

int main()
{
	std::vector<std::string> words = { "banana", "apple", "alpaca", "cat", "biscuit", "elephant", "string", "house", "progress", "trousers", "mouse" };
	sortWords(words);
	for (size_t i = 0; i < words.size(); i++)
	{
		std::cout << words[i] << " ";
	}
}

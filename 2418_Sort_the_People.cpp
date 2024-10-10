#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/*You are given an array of strings names, and an array heights that consists of 
distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.*/

std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {
	int n = names.size();
	std::vector<std::pair<std::string, int>> namesWithHeights;

	for (size_t i = 0; i < n; i++)
	{
		std::pair<std::string, int> pair;
		pair.first = names[i];
		pair.second = heights[i];
		namesWithHeights.push_back(pair);
	}

	std::sort(namesWithHeights.begin(), namesWithHeights.end(), [](auto a, auto b) {
		return a.second > b.second;
		});

	for (size_t i = 0; i < n; i++)
	{
		names[i] = namesWithHeights[i].first;
	}
	return names;

}

int main()
{
	std::vector<std::string> names = { "Mary","John","Emma" };
	std::vector<int> heights = { 180,165,170 };
	std::vector<std::string> res = sortPeople(names, heights);
	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << res[i];
	}

}

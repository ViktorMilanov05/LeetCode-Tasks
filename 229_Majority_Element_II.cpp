#include <iostream>
#include <vector>
#include <algorithm>

/* Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. */

std::vector<int> majorityElement(std::vector<int>& nums) {
	std::vector<int> res;
	if (nums.size() == 1) {
		return nums;
	}
	int count = nums.size() / 3;
	sort(nums.begin(), nums.end());
	if (count < 1) {
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (res.empty() || res.back() != nums[i]) {
				res.push_back(nums[i]);
			}
		}
		return res;
	}
	int repeating = 1;
	for (size_t i = 1; i < nums.size(); i++)
	{
		if (nums[i] == nums[i - 1]) {
			repeating++;
			if (repeating > count && (res.empty() || res.back() != nums[i]))
				res.push_back(nums[i]);
		}
		else {
			repeating = 1;
		}
	}
	return res;
}

int main()
{
	std::vector<int> n{ 2,2,1,3 };
	std::vector<int> res = majorityElement(n);
	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << res[i] << " ";
	}
}

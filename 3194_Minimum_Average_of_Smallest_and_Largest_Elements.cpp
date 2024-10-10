#include <iostream>
#include <vector>
#include <algorithm>

/*You have an array of floating point numbers averages which is initially empty.You are given an array nums of n integers where n is even.

You repeat the following procedure n / 2 times:

Remove the smallest element, minElement, and the largest element maxElement, from nums.
Add(minElement + maxElement) / 2 to averages.
Return the minimum element in averages*/

double minimumAverage(std::vector<int>& nums) {
	std::sort(nums.begin(), nums.end());
	double min = __DBL_MAX__;
	for (size_t i = 0; i < nums.size() / 2; i++)
	{
		double curMin = (nums[i] + nums[nums.size() - 1 - i]) / 2.0;
		if (curMin < min)
			min = curMin;
	}
	return min;

}

int main()
{
	std::vector<int> v = { 7,8,3,4,15,13,4,1 };
	std::cout << minimumAverage(v) << std::endl;
}

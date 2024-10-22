#include <iostream>
#include <vector>
#include <algorithm>

/*Given an integer array nums of size n, return the minimum number of moves 
required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.*/

int minMoves2(std::vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int midInd = nums.size() / 2;
	int count = 0;
	for (size_t i = 0; i < midInd; i++)
	{
		count += nums[midInd] - nums[i];
	}
	for (size_t i = midInd + 1; i < nums.size(); i++)
	{
		count += nums[i] - nums[midInd];
	}
	return count;
}

int main()
{
	std::vector<int> n{ 1,2,3 };
	std::cout << minMoves2(n);
}

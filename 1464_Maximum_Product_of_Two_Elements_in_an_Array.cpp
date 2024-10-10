#include <iostream>
#include <vector>
#include <algorithm>

/*Given the array of integers nums, you will choose two different indices i and j of that array. 
Return the maximum value of (nums[i]-1)*(nums[j]-1)*/

int maxProduct(std::vector<int>& nums) {
	std::sort(nums.begin(), nums.end(), std::greater<int>());
	return (nums[0] - 1) * (nums[1] - 1);
}

int main()
{
	std::vector<int> v = { 3,4,5,2 };
	std::cout << maxProduct(v) << std::endl;
}

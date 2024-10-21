#include <iostream>
#include <vector>
#include <algorithm>

/*You are given an array of positive integers nums of length n.

A polygon is a closed plane figure that has at least 3 sides. 
The longest side of a polygon is smaller than the sum of its other sides.

Conversely, if you have k (k >= 3) positive real numbers
a1, a2, a3, ..., ak where a1 <= a2 <= a3 <= ... <= ak and 
a1 + a2 + a3 + ... + ak-1 > ak, then there always exists a 
polygon with k sides whose lengths are a1, a2, a3, ..., ak.

The perimeter of a polygon is the sum of lengths of its sides.

Return the largest possible perimeter of a polygon whose sides
can be formed from nums, or -1 if it is not possible to create a polygon.*/

long long largestPerimeter(std::vector<int>& nums) {
	std::sort(nums.begin(), nums.end());
	long long sumOfAll = 0;
	for (size_t i = 0; i < nums.size(); i++)
	{
		sumOfAll += nums[i];
	}
	for (size_t i = nums.size() - 1; i >= 2; i--)
	{
		sumOfAll -= nums[i];
		if (sumOfAll > nums[i]) {
			return sumOfAll + nums[i];
		}
	}
	return -1;
}

int main()
{
	std::vector<int> nums1{ 5, 5, 5 };
    std::cout << largestPerimeter(nums1);
}

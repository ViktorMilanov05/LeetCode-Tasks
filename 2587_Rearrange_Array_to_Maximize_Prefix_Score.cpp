#include <iostream>
#include <vector>
#include <algorithm>

/*You are given a 0-indexed integer array nums. You can rearrange 
the elements of nums to any order (including the given order).

Let prefix be the array containing the prefix sums of nums after 
rearranging it. In other words, prefix[i] is the sum of the elements 
from 0 to i in nums after rearranging it. The score of nums is the 
number of positive integers in the array prefix.

Return the maximum score you can achieve.*/

int maxScore(std::vector<int>& nums) {
    long sum = 0;
    int count = 0;
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum > 0) {
            count++;
        }
    }
    return count;
}

int main()
{
	std::vector<int> nums1{ 2, -1, 0, 1, -3, 3, -3 };
    std::cout << maxScore(nums1);

}

#include <iostream>
#include <vector>
#include <algorithm>

/*You are given an integer array nums and an integer k. You may partition nums 
into one or more subsequences such that each element in nums appears in exactly one of the subsequences.

Return the minimum number of subsequences needed such that the difference between the maximum and
minimum values in each subsequence is at most k.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements
without changing the order of the remaining elements.)*/

int partitionArray(std::vector<int>& nums, int k) {
	int n = nums.size();
	std::sort(nums.begin(), nums.end());
	int separatorInd = 1;
	int startSubArrInd = 0;
	int count = 0;
	while (startSubArrInd < n) {

		while (separatorInd < n && (nums[separatorInd] - nums[startSubArrInd]) <= k) {
			separatorInd++;
		}
		startSubArrInd = separatorInd++;
		count++;
	}
	return count;
}

int main()
{
	std::vector<int> nums = { 3,1,3,4,2 };
	int k = 0;
	std::cout << partitionArray(nums, k);

}


#include <iostream>
#include <vector>
#include <algorithm>

/*Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.*/

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
	std::vector<int> res;
	int firstInd = 0;
	int secondInd = 0;
	std::sort(nums1.begin(), nums1.end());
	std::sort(nums2.begin(), nums2.end());
	while (nums1.size() > firstInd && nums2.size() > secondInd) {
		if (nums1[firstInd] == nums2[secondInd]) {
			if (res.empty() || res.back() != nums1[firstInd])
				res.push_back(nums1[firstInd]);
			firstInd++;
			secondInd++;
		}
		else if (nums1[firstInd] > nums2[secondInd]) {
			secondInd++;
		}
		else {
			firstInd++;
		}
	}
	return res;
}

int main()
{
    std::vector<int> nums1{ 1,2,2,1 };
	std::vector<int> nums2{ 2,2 };
	std::vector<int> res = intersection(nums1, nums2);
	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << res[i];
	}

}

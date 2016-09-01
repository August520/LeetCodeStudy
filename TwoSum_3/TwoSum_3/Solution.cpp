#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		sort(nums.begin(), nums.end());
		unsigned int first = 0;
		unsigned int last = nums.size() - 1;
		int sum = 0;

		vector<int> vecTwoSum;

		while (target != sum)
		{
			sum = nums[first] + nums[last];
			if (sum > target)
				last--;
			else if (sum < target)
				first++;
			else
			{
				vecTwoSum.push_back(first);
				vecTwoSum.push_back(last);
				return vecTwoSum;
			}
				
		}
		return vecTwoSum;

		
		for (unsigned int i=0; i<nums.size(); i++)
			for (unsigned int j=i+1; j<nums.size(); j++)
			{
				if (nums[i]+nums[j] == target)
				{
					vecTwoSum.push_back(i);
					vecTwoSum.push_back(j);
					return vecTwoSum;
				}
			}
			return vecTwoSum;
	}
};

int main()
{
	Solution solu;
	int itarget = 6;
	int ivalues[3] = {3, 2, 4};
	vector<int> numbers(ivalues, ivalues+3);

	vector<int> result = solu.twoSum(numbers, itarget);

	for (vector<int>::iterator iter=result.begin();iter!=result.end();iter++)  
	{  
		cout<<*iter<<'\0';  
	} 

	return 0;
}
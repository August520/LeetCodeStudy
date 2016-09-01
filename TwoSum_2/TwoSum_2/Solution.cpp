#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> vecTwoSum = nums;
		sort(vecTwoSum.begin(), vecTwoSum.end());
		unsigned int start = 0;
		unsigned int end = vecTwoSum.size() - 1;

		int first = 0;
		int second = 0;

		int sum = 0;

		while (start < end)
		{
			sum = vecTwoSum[start] + vecTwoSum[end];
			if (sum > target)
				end--;
			else if (sum < target)
				start++;
			else
			{
				first = vecTwoSum[start];
				second = vecTwoSum[end];
				break;
			}
				
		}

		vecTwoSum.clear();
		if (start > end)
			return vecTwoSum;
		if(first != second)
		{
			vecTwoSum.push_back(find(nums.begin(), nums.end(),first)-nums.begin());
			vecTwoSum.push_back(find(nums.begin(), nums.end(),second)-nums.begin());
		}
		else
		{
			vecTwoSum.push_back(find(nums.begin(), nums.end(),first)-nums.begin());
			vecTwoSum.push_back(find(nums.begin()+vecTwoSum[0]+1, nums.end(),second)-nums.begin());
		}

		return vecTwoSum;
	}
};

int main()
{
	Solution solu;
	int itarget = 0;
	int ivalues[4] = {-3, 4, 3, 90};
	vector<int> numbers(ivalues, ivalues+3);

	vector<int> result = solu.twoSum(numbers, itarget);

	for (vector<int>::iterator iter=result.begin();iter!=result.end();iter++)  
	{  
		cout<<*iter<<'\0';  
	} 

	return 0;
}
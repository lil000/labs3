#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	int nums[] = {1, 2, 3, 1};
	int indexDiff = 3;
	int valueDiff = 0;
	string flag = "false";

	for (int i = 0; i < (sizeof(nums) / sizeof(nums[0])); i++)
	{
		for (int j = 0; j < (sizeof(nums) / sizeof(nums[0]) + 1); j++)
		{
			if (i != j and (abs(i - j) <= indexDiff) and abs(nums[i] - nums[j]) <= valueDiff)
			{
				flag = "true";
				break;
			}
		}
	}
	cout << flag << endl;

	return 0;
}
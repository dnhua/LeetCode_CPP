#include <stdio.h>
/*
1.双指针对撞，可以去重
	选择最左边的作为now固定，然后从now + 1至最右边，开始碰撞
	遇到符合条件的，就加入结果集。
2.怎么去重？
	对于左和右，只要往内部找一直是相等的就移动，直到两个指针已经越过彼此，就移动下一个now
3.防止溢出
	有用例内容是很大的，这时候要考虑malloc出来的结果集内存究竟多大
	怎么计算？
	尝试出来6 * numsSize是可以通过的，也就是max = n * (An3 / Cn3)
4.最需要注意的一点
	returnColumnSize 也需要malloc
*/
int comp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	*returnSize = 0;
	if (numsSize == 0) {
		return 0;
	}
	int **ret = (int **)malloc(sizeof(int *) * (numsSize + 1) * 6);
	*returnSize = 0;
	short left = 0;
	short right = numsSize - 1;;
	int target = 0;

	*returnColumnSizes = malloc(sizeof(int) * (numsSize + 1) * 6);
	qsort(nums, numsSize, sizeof(int), comp);
	ret[*returnSize] = malloc(sizeof(int) * 3);

	while (left + 1 < right) {     
		int i = left + 1;
		int j = right;
		target = 0 - nums[left];
		while (i < j) {
			if (nums[i] + nums[j] < target) {
				i++;
			}
			else if (nums[i] + nums[j] > target) {
				j--;
			}
			else {
				ret[*returnSize][0] = nums[left];
				ret[*returnSize][1] = nums[i];
				ret[*returnSize][2] = nums[j];
				(*returnColumnSizes)[*returnSize] = 3;
				(*returnSize)++;
				ret[*returnSize] = malloc(sizeof(int) * 3);

				while (nums[i] == nums[++i] && i < j) {}
				while (nums[j] == nums[--j] && i < j) {}
			}
		}
		while (nums[left] == nums[++left] && left + 1 < right) {}
	}

	return ret;
}

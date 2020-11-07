#include <stdio.h>
/*
1.˫ָ���ײ������ȥ��
	ѡ������ߵ���Ϊnow�̶���Ȼ���now + 1�����ұߣ���ʼ��ײ
	�������������ģ��ͼ���������
2.��ôȥ�أ�
	��������ң�ֻҪ���ڲ���һֱ����ȵľ��ƶ���ֱ������ָ���Ѿ�Խ���˴ˣ����ƶ���һ��now
3.��ֹ���
	�����������Ǻܴ�ģ���ʱ��Ҫ����malloc�����Ľ�����ڴ澿�����
	��ô���㣿
	���Գ���6 * numsSize�ǿ���ͨ���ģ�Ҳ����max = n * (An3 / Cn3)
4.����Ҫע���һ��
	returnColumnSize Ҳ��Ҫmalloc
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

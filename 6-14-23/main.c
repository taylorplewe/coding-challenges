#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN_BUFF_SIZE 65536 * 4

int* nums;
int len;
int check(int, int);
int iterations;
int main() {
	// get list of ints
	puts("provide comma-separated list of numbers, which were ordered low to high, and then rotated at some point e.g. 3,4,5,1,2");
	char in[IN_BUFF_SIZE];
	scanf("%s", in);
	char* num = strtok(in, ",");
	int i = 0;
	nums = calloc(65536, sizeof(int));
	while (num) {
		nums[i] = atoi(num);
		i++;
		num = strtok(NULL, ",");
	}
	len = i;

	//puts("list:");
	//for (i = 0; i < len; i++) {
	//	printf("%i ", nums[i]);
	//}

	// actual problem
	iterations = 0;
	int ans = check(0, len-1);
	printf("ans: %i\niterations: %i\n", ans, iterations);
	
	free(nums);
	return 0;
}

int check(int low, int high) {
	iterations++;
	int mid_ind = low + (high - low) / 2;
	int q1_ind = low + (high - low) / 4;
	int q3_ind = mid_ind + (high - low) / 4;
	if (q3_ind == mid_ind && q3_ind < high) q3_ind++;
	if (q1_ind == mid_ind && q1_ind > low) q1_ind--;

	int mid = nums[mid_ind];
	int q1 = nums[q1_ind];
	int q3 = nums[q3_ind];
	int left = nums[low];
	int right = nums[high];

	printf("inds: %i %i %i %i %i\n", low, q1_ind, mid_ind, q3_ind, high);
	printf("nums: %i %i %i %i %i\n\n", left, q1, mid, q3, right);

	if (q3 < mid) {
		if (q3_ind - mid_ind <= 1) {
			if (mid < q3) return mid;
			else return q3;
		}
		else return check(mid_ind, q3_ind);
	} else if (q1 > mid) {
		if (mid_ind - q1_ind <= 1) {
			if (mid < q1) return mid;
			else return q1;
		}
		else return check(q1_ind, mid_ind);
	} else {
		if (left > q1) {
			if (q1_ind - low <= 1) return q1;
			else return check(low, q1_ind);
		} else if (right < q3) {
			if (high - q3_ind <= 1) return right;
			else return check(q3_ind, high);
		} else {
			return left;
		}
	}

	puts("end of check error");
	return -1;
}

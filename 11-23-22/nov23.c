#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;
int* nums;
int largestSum();
int main() {
	// get a list of ints from user
	puts("Provide list of integers (separated with commas)");
	char buff[128];
	scanf("%s", buff);
	char* tok = strtok(buff, ",");
	nums = calloc(32, sizeof(int));
	while (tok != NULL) {
		nums[count] = atoi(tok);
		count++;
		tok = strtok(NULL, ",");
	}

	// actual problem
	int lsum = largestSum(0);
	printf("%i\n", lsum);

	// end
	free(nums);
	puts("end");
	return 0;
}
int largestSum(int ind) {
	int csum = 0;
	if (ind + 2 < count) {
		for (int n = ind + 2; n < count; n++) {
			int sum = largestSum(n);
			if (sum > csum) csum = sum;
		}
	}
	return nums[ind] + csum;
}

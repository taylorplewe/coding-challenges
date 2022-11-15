#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char isArrayGood();
int main() {
	puts("What is k?");
	int k;
	scanf("%i", &k);
		
	int* nums = calloc(64, sizeof(int));
	int numNums = 0;
	puts("What numbers can I use? (Separated with commas.)");
	char* buff = calloc(128, sizeof(char));
	scanf("%s", buff);
	char* tok = strtok(buff, ",");
	while (tok != NULL) {
		nums[numNums] = atoi(tok);
		numNums++;
		tok = strtok(NULL, ",");
	}

	if (isArrayGood(nums, k, numNums) > 0) {
		puts("yes");
	} else {
		puts("no");
	}
	return 0;
}

char isArrayGood(int* nums, int k, int numNums) {
	for (int i = 0; i < numNums - 1; i++) {
		for (int j = i + 1; j < numNums; j++) {
			if (nums[i] + nums[j] == k) {
				return 1;
			}
		} 
	}
	return 0;
}

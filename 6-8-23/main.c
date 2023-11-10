#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* nums;
int count = 0;
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

	// get K
	printf("Provide a number K that's less than %i\n", count);
	int k = count;
	while (k >= count) {
		scanf("%i", &k);
		if (k >= count) puts("K is bigger than length of array!");
	}

	// rotate
	for (int i = 0; i < k; i++) {
		int temp = nums[count - 1];
		for (int j = count-1; j >= 0; j--) {
			nums[j] = nums[j-1];
		}
		nums[0] = temp;
	}

	// output
	puts("New array:");
	for (int i = 0; i < count; i++) {
		printf("%i ", nums[i]);
	}
	puts("");

	return 0;
}

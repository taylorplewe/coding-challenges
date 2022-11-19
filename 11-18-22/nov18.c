#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char searchNums();
int main() {
	puts("Enter numbers in array. (Separated by spaces)");
	char buff[64];
	scanf("%s", buff);
	int* nums = calloc(64, sizeof(int));
	int count = 0;
	char* tok = strtok(buff, ",");
	while (tok != NULL) {
		nums[count] = atoi(tok);
		count++;
		tok = strtok(NULL, ",");
	}

	// find that number yaw
	int search = 1;
	while (searchNums(nums, count, search)) {
		search++;
	}
	printf("The missing no. is %i.\n", search);

	puts("end");
	return 0;
}
char searchNums(int* nums, int count, int search) {
	for (int i = 0; i < count; i++) {
		if (nums[i] == search) {
			return 1;
		}
	}
	return 0;
}

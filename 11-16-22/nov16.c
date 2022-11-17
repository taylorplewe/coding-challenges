#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray();
int main() {
	puts("What numbers are in the array? (Separated by commas)");
	int* ogArray = calloc(32, sizeof(int));
	char* buff = calloc(64, 1);
	scanf("%s", buff);
	char* tok = strtok(buff, ",");
	int numNums = 0;
	while (tok != NULL) {
		ogArray[numNums] = atoi(tok);
		numNums++;
		tok = strtok(NULL, ",");
	}
	puts("Originial array:");
	printArray(ogArray, numNums);
	puts("");

	int* newArray = calloc(numNums, sizeof(int));
	puts("With division:");
	int totalProduct = ogArray[0];
	for (int i = 1; i < numNums; i++) {
		totalProduct *= ogArray[i];
	}
	for (int i = 0; i < numNums; i++) {
		newArray[i] = totalProduct / ogArray[i];
	}
	printArray(newArray, numNums);
	puts("");

	puts("Without division:");
	newArray = calloc(numNums, sizeof(int));
	for (int i = 0; i < numNums; i++) {
		int _tot = 1;
		for (int j = 0; j < numNums; j++) {
			if (j != i) _tot *= ogArray[j];
		}
		newArray[i] = _tot;
	}
	printArray(newArray, numNums);

	puts(".");
	return 0;
}

void printArray(int* arr, int len) {
	printf("[ ");
	for (int i = 0; i < len; i++) {
		printf("%i", arr[i]);
		if (i < len - 1) {
			printf(", ");
		}
	}
	printf(" ]\n");
}

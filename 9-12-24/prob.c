#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	if (argc < 2) {
		puts("Please provide an input string.");
		return 1;
	}
	char* word = argv[1];

	char* slots = calloc(256, 1);
	
	for (int i = 0; i < strlen(word); i++) {
		if (slots[word[i]] & 1) {
			printf("%c\n", word[i]);
			return 0;
		}
		slots[word[i]] = 1;
	}
	puts("no duplicates!");
	return 0;
}

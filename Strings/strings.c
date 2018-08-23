#include <ctype.h>
#include <string.h>
#include <stdio.h>

#include "strings.h"

#define DEBUG 1

tBoolean isSpecialChar(char c) {
	return !isalpha(c) && !isdigit(c);
}

//anything non alphanumeric is special
void reverseStringNoSpecialChars(char * string) {
	int front = 0;
	int back = strlen(string) - 1;

	while (front < back) {
		if (isSpecialChar(string[front])) {
			front++;
		} else if (isSpecialChar(string[back])) {
			back--;
		} else {
			string[front] += string[back];
			string[back] = string[front] - string[back];
			string[front] -= string[back];
			front++;
			back--;
		}
	}
	if (DEBUG)
		printf("%s\n", string);
}

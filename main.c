#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "bool.h"
#include "stack.h"

int main(int argc, char **argv) {
	printf("char: %zu\n", sizeof(char));
	printf("int: %zu\n", sizeof(int));
	printf("long: %zu\n", sizeof(long));
	printf("double: %zu\n", sizeof(double));
	printf("void *: %zu\n", sizeof(void *));
	stack_t stack = stack_create(STACK_DOUBLE);
	stack_push(stack, (double)1);
	stack_push(stack, (unsigned long)0);
	stack_push(stack, 2.);
	stack_push(stack, 3);
	while (!stack_is_empty(stack)) {
		double tmp;
		stack_pop(stack, &tmp);
		printf("%f\n", tmp);
	}
	/* handle arguments */
	FILE *input = stdin;

	if (argc >= 2 && strcmp(argv[1], "-") != 0) {
		input = fopen(argv[1], "r");
		if (input == NULL) {
			fprintf(
				stderr,
				"Unable to open file %s for reading: %s\n",
				argv[1],
				strerror(errno)
			);
			exit(EXIT_FAILURE);
		}
	}

	FILE *output = stdout;

	if (argc >= 3 && strcmp(argv[2], "-") != 0) {
		output = fopen(argv[2], "w");
		if (output == NULL) {
			fprintf(
				stderr,
				"Unable to open file %s for writing: %s\n",
				argv[2],
				strerror(errno)
			);
			exit(EXIT_FAILURE);
		}
	}

	/* TODO: tokenize */
	/* TODO: parse */
	/* TODO: generate tree */

	return EXIT_SUCCESS;
}

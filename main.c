#include <stdlib.h>
#include <stdio.h>

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
	return EXIT_SUCCESS;
}

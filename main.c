#include <stdlib.h>
#include <stdio.h>

#include "bool.h"
#include "stack.h"

int main(int argc, char **argv) {
	stack_t stack = stack_create(20, STACK_DOUBLE);
	stack_push(stack, (double)1);
	stack_push(stack, 2.);
	stack_push(stack, 3);
	while (!stack_is_empty(stack)) {
		double tmp;
		stack_pop(stack, &tmp);
		printf("%f\n", tmp);
	}
	return EXIT_SUCCESS;
}

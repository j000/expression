#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "bool.h"
#include "stack.h"

int main(int argc, char **argv) {
	stack_t stack = stack_new(sizeof(double));
	double a = 0;
	stack_push(stack, &a);
	a = 1;
	stack_push(stack, &a);
	stack_push(stack, &(double){2.});
	stack_push(stack, &(double){3});
	while (!stack_is_empty(stack)) {
		double tmp;
		stack_pop(stack, &tmp);
		printf("%.3f\n", tmp);
	}
	return EXIT_SUCCESS;
}

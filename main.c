#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "bool.h"
#include "stack.h"

int main(int argc, char **argv) {
#ifdef _DEBUG
	{
		stack_t stack = stack_new(sizeof(double));
		double a = 0;

		stack_push(stack, &a);
		a = 1;
		stack_push(stack, &a);
		stack_push(stack, &(double){2. });
		stack_push(stack, &(double){3 });

		double t = 0;

		assert(!stack_is_empty(stack));
		stack_pop(stack, &t);
		assert(t == 3.);
		assert(!stack_is_empty(stack));
		stack_pop(stack, &t);
		assert(t == 2.);
		assert(!stack_is_empty(stack));
		stack_pop(stack, &t);
		assert(t == 1.);
		assert(!stack_is_empty(stack));
		stack_pop(stack, &t);
		assert(t == 0.);
		assert(stack_is_empty(stack));
	}
#endif /* ifdef _DEBUG */

	return EXIT_SUCCESS;
}

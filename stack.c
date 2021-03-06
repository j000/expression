#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "stack.h"

union stack_element {
	int val_i;
	long val_l;
	double val_d;
	void *val_p;
};

struct stack {
	size_t top;
	size_t capacity;
	enum stack_type type;
	union stack_element *elements;
};

stack_t stack_create(const enum stack_type type) {
	stack_t new_stack = calloc(1, sizeof(*new_stack));

	if (new_stack == NULL) {
		perror("Couldn't allocate memory for stack");
		exit(EXIT_FAILURE);
	}

	new_stack->capacity = 8;
	new_stack->top = 0;
	new_stack->type = type;

	new_stack->elements = calloc(new_stack->capacity, sizeof(*new_stack->elements));
	if (new_stack->elements == NULL) {
		perror("Couldn't allocate memory for stack elements");
		exit(EXIT_FAILURE);
	}

	return new_stack;
}

void stack_destroy(stack_t stack) {
	free(stack->elements);
	free(stack);
}

void stack_push(stack_t stack, ...) {
	if (stack->top == stack->capacity) {
		stack->capacity *= 2;
		void *tmp = realloc(stack->elements, stack->capacity);
		if (tmp == NULL) {
			perror("Couldn't reallocate memory for stack elements");
			exit(EXIT_FAILURE);
		}
		stack->elements = tmp;
	}

	va_list ap;

	va_start(ap, stack);

	switch (stack->type) {
	case STACK_INT:
		stack->elements[stack->top++].val_i = va_arg(ap, int);
		break;

	case STACK_LONG:
		stack->elements[stack->top++].val_l = va_arg(ap, long);
		break;

	case STACK_DOUBLE:
		stack->elements[stack->top++].val_d = va_arg(ap, double);
		break;

	case STACK_POINTER:
		stack->elements[stack->top++].val_p = va_arg(ap, void *);
		break;

	default:
		fprintf(stderr, "Unknown type in stack_push()\n");
		exit(EXIT_FAILURE);
	}

	va_end(ap);
}

void stack_pop(stack_t stack, void *p) {
	if (stack->top == 0) {
		fprintf(stderr, "Stack empty!\n");
		exit(EXIT_FAILURE);
	}

	switch (stack->type) {
	case STACK_INT:
		*((int *)p) = stack->elements[--stack->top].val_i;
		break;

	case STACK_LONG:
		*((long *)p) = stack->elements[--stack->top].val_l;
		break;

	case STACK_DOUBLE:
		*((double *)p) = stack->elements[--stack->top].val_d;
		break;

	case STACK_POINTER:
		*((void **)p) = stack->elements[--stack->top].val_p;
		break;

	default:
		fprintf(stderr, "Unknown type in stack_pop()\n");
		exit(EXIT_FAILURE);
	}
}

bool stack_is_empty(stack_t stack) {
	return stack->top == 0;
}

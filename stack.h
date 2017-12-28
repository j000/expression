#ifndef STACK_H
#define STACK_H

#include "bool.h"

enum stack_type {
	STACK_INT,
	STACK_LONG,
	STACK_DOUBLE,
	STACK_POINTER
};

typedef struct stack * stack_t;

stack_t stack_create(const enum stack_type type);
void stack_destroy(stack_t stack);
void stack_push(stack_t stack, ...);
void stack_pop(stack_t stack, void *val);
bool stack_is_empty(stack_t stack);

#endif /* STACK_H */

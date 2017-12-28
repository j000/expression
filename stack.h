/* https://see.stanford.edu/materials/icsppcs107/stack-implementation.pdf */
#include <stddef.h>
#include "bool.h"

typedef struct {
	void *elements;
	size_t element_size;
	size_t size;
	size_t capacity;
} *stack_t;

stack_t stack_new(size_t element_size);
void stack_free(stack_t s);
bool stack_is_empty(stack_t s);
void stack_push(stack_t s, const void *element_address);
void stack_pop(stack_t s, void *element_address);

#include "stack.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define INITIAL_CAPACITY 8

typedef struct _stack {
	void *elements;
	size_t element_size;
	size_t size;
	size_t capacity;
} *stack_t;

stack_t stack_new(size_t element_size) {
	assert(element_size > 0);
	stack_t s = calloc(1, sizeof(*s));
	assert(s != NULL);
	s->element_size = element_size;
	s->size = 0;
	s->capacity = INITIAL_CAPACITY;
	s->elements = calloc(s->capacity, s->element_size);
	assert(s->elements != NULL);
	return s;
}

void stack_free(stack_t s) {
	free(s->elements);
	free(s);
}

bool stack_is_empty(stack_t s) {
	return s->size == 0;
}

void stack_push(stack_t s, const void *element_address) {
	void *dest;
	if (s->size == s->capacity) {
		s->capacity *= 2;
		s->elements = realloc(s->elements, s->capacity * s->element_size);
		assert(s->elements != NULL);
	}

	dest = (char *)s->elements + s->size * s->element_size;
	memcpy(dest, element_address, s->element_size);
	s->size += 1;
}

void stack_pop(stack_t s, void *element_address) {
	const void *source;

	assert(!stack_is_empty(s));
	s->size -= 1;
	source = (const char *)s->elements + s->size * s->element_size;
	memcpy(element_address, source, s->element_size);

}

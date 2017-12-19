#ifndef BOOL_H
#define BOOL_H

#if defined(__STDC__) && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
	#include <stdbool.h>
#else
	#ifndef bool
	#define bool uint_fast8_t
	enum {
			false,
			true
	}
	#endif
#endif


#endif /* BOOL_H */

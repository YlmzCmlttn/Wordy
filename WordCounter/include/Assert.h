#pragma once
#undef my_assert
#ifdef NDEBUG
#define my_assert(expression, errormessage) ((void)0)
#else

#include <stdlib.h>
#include <stdio.h>

#if __STDC_VERSION__-199901L >= 0
#define my_assert(expr, msg) \
    ((void)( (expr) ? 0 : do_assert(__FILE__, __LINE__, __func__, msg) ))

#elif defined(__GNUC__)
#define my_assert(expr, msg) \
    ((void)( (expr) ? 0 : do_assert(__FILE__, __LINE__, __FUNCTION__, msg) ))

#else
#define my_assert(expr, msg) \
    ((void)( (expr) ? 0 : do_assert(__FILE__, __LINE__, NULL, msg) ))
#endif

#ifndef HAVE_DO_ASSERT
#define HAVE_DO_ASSERT
static inline int do_assert(const char *const filename,
                            const unsigned long linenum,
                            const char *const funcname,
                            const char *const msg)
{
    if (funcname)
        fprintf(stderr, "%s: Line %lu, function %s(): %s\n", filename, linenum, funcname, msg);
    else
        fprintf(stderr, "%s: Line %lu: %s\n", filename, linenum, msg);
    abort();
    return 0;
}
#endif

#endif
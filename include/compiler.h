#ifndef __TIDY_COMPILER_H__
#define __TIDY_COMPILER_H__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__GNUC__) || defined(__INTEL_COMPILER)
# define ARG_UNUSED(x) x __attribute__((unused))
#else
# define ARG_UNUSED(x) x
#endif

#define NOTNULL(x)                  /*@notnull@*/ x
    /* The pointer passed may not be NULL */

#define NULLOK(x)                   /*@null@*/ x
    /* The pointer passed may be NULL */

#define ARGIN(x)                    /*@in@*/ /*@notnull@*/ x
#define ARGIN_NULLOK(x)             /*@in@*/ /*@null@*/ x
    /* The pointer target must be completely defined before being passed */
    /* to the function. */

#define ARGOUT(x)                   /*@out@*/ /*@notnull@*/ x
#define ARGOUT_NULLOK(x)            /*@out@*/ /*@null@*/ x
    /* The pointer target will be defined by the function */

#define ARGMOD(x)                   /*@in@*/ /*@notnull@*/ x
#define ARGMOD_NULLOK(x)            /*@in@*/ /*@null@*/ x
    /* The pointer target must be completely defined before being passed, */
    /* and MAY be modified by the function. */

#define FUNC_MODIFIES(x)            /*@modifies x@*/
    /* Never applied by a human, only by the headerizer. */

#define ARGFREE(x)                          /*@only@*/ /*@out@*/ /*@null@*/ x
    /* From the Splint manual: The parameter to free() must reference */
    /* an unshared object.  Since the parameter is declared using "only", */
    /* the caller may not use the referenced object after the call, and */
    /* may not pass in a reference to a shared object.  There is nothing */
    /* special about malloc and free --  their behavior can be described */
    /* entirely in terms of the provided annotations. */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __TIDY_COMPILER_H__ */

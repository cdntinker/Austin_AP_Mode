/* Webpage HTML - this is the config page*/ 

#ifndef MACROS_h
#define MACROS_h

/* Convert a #defined value to a string */
#if !defined(ST) && !defined(STR)
#define ST(A) #A
#define STR(A) ST(A)
#endif

#endif // MACROS_h
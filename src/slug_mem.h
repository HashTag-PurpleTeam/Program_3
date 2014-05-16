/* slug_mem.h
 * 
 * This is the file that should be included for end users intending to use our
 * library.
 *
 * CREATED: Leland Miller (5/14/14)
 */

#include "slug_mem.c"

/* LM: The following defines were recommended in the assignment
 *     specs. */

#define FUNCTIONIZE(a,b) a(b)
#define STRINGIZE(a) #a
#define INT2STRING(i) FUNCTIONIZE(STRINGIZE,i)
#define FILE_POS __FILE__ ":" INT2STRING(__LINE__)

<<<<<<< HEAD
#define malloc(s) slug_malloc((s), FILE_POS)

=======
void slug_memstats(void);
>>>>>>> e6705fa9e01ad5a718e9ed673084997a8124f4fd

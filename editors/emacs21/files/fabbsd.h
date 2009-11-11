/* s/ file for fabbsd systems.  */

/* Get most of the stuff from bsd4.3 */
#include "bsd4-3.h"

/* Get the rest of the stuff from that less-POSIX-conformant system */
#include "netbsd.h"

/*  David Mazieres <dm@reeducation-labor.lcs.mit.edu> says this
    is necessary.  Otherwise Emacs dumps core when run -nw.  */
#undef LIBS_TERMCAP

/*  Idea From the FreeBSD port. Seems to work well.
    Needs testing and then commiting to emacs developers */
#define TERMINFO
#define LIBS_TERMCAP -lncurses

/*  We don't need rpath */
#ifdef __ELF__
#undef LD_SWITCH_SYSTEM
#define LD_SWITCH_SYSTEM -L/usr/X11R6/lib -L/usr/local/lib
#undef C_SWITCH_SYSTEM
#define C_SWITCH_SYSTEM -I/usr/X11R6/include -I/usr/local/include -L/usr/local/lib
#endif

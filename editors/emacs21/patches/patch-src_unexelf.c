$OpenBSD: patch-src_unexelf.c,v 1.5 2003/07/05 00:27:08 naddy Exp $
--- src/unexelf.c.orig	Tue Oct 15 11:21:44 2002
+++ src/unexelf.c	Tue Apr 14 19:49:12 2009
@@ -436,7 +436,7 @@ extern void fatal (char *, ...);
 #include <errno.h>
 #include <unistd.h>
 #include <fcntl.h>
-#if !defined (__NetBSD__) && !defined (__OpenBSD__)
+#if !defined (__NetBSD__) && !defined (__OpenBSD__) && !defined(__FabBSD__)
 #include <elf.h>
 #endif
 #include <sys/mman.h>
@@ -460,7 +460,7 @@ extern void fatal (char *, ...);
 #define MAP_FAILED ((void *) -1)
 #endif
 
-#if defined (__alpha__) && !defined (__NetBSD__) && !defined (__OpenBSD__)
+#if defined (__alpha__) && !defined (__NetBSD__) && !defined (__OpenBSD__) && !defined(__FabBSD__)
 /* Declare COFF debugging symbol table.  This used to be in
    /usr/include/sym.h, but this file is no longer included in Red Hat
    5.0 and presumably in any other glibc 2.x based distribution.  */
@@ -535,9 +535,14 @@ typedef struct {
 #endif /* __mips__ */
 #endif /* __NetBSD__ */
 
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__FabBSD__)
 # include <sys/exec_elf.h>
-#endif
+# ifdef __alpha__
+#  include <sys/exec_ecoff.h>
+#  define HDRR		struct ecoff_symhdr
+#  define pHDRR		HDRR *
+# endif /* __alpha__ */
+#endif /* __OpenBSD__ or __FabBSD__ */
 
 #if __GNU_LIBRARY__ - 0 >= 6
 # include <link.h>	/* get ElfW etc */
@@ -549,10 +554,12 @@ typedef struct {
 # else
 #  define ElfBitsW(bits, type) Elf/**/bits/**/_/**/type
 # endif
-# ifdef _LP64
-#  define ELFSIZE 64
-# else
-#  define ELFSIZE 32
+# if !defined(__OpenBSD__) && !defined(__FabBSD__)
+#  ifdef _LP64
+#   define ELFSIZE 64
+#  else
+#   define ELFSIZE 32
+#  endif
 # endif
   /* This macro expands `bits' before invoking ElfBitsW.  */
 # define ElfExpandBitsW(bits, type) ElfBitsW (bits, type)

$OpenBSD: patch-src_m_macppc.h,v 1.3 2002/03/28 00:13:49 mark Exp $
--- src/m/macppc.h.orig	Tue Oct 23 03:43:33 2001
+++ src/m/macppc.h	Tue Apr 14 19:41:02 2009
@@ -74,19 +74,16 @@ Boston, MA 02111-1307, USA.  */
 
 /* #define NO_SOCK_SIGIO */
 
-#if defined(__OpenBSD__)
-#define ORDINARY_LINK
-#endif
-
+#undef UNEXEC
 #define UNEXEC unexelf.o
 
 #define NO_TERMIO
 
-#if defined (LINUX) || defined (__NetBSD__) || defined (__OpenBSD__)
+#if defined (LINUX) || defined (__NetBSD__) || defined (__OpenBSD__) || defined(__FabBSD__)
 # define TEXT_END ({ extern int _etext; &_etext; })
 #endif
 
-#if (defined (__NetBSD__) || defined (__OpenBSD__)) && defined (__ELF__)
+#if (defined (__NetBSD__) || defined (__OpenBSD__) || defined(__FabBSD__)) && defined (__ELF__)
 #define HAVE_TEXT_START
 #endif
 

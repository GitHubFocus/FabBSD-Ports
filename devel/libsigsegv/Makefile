# $FabBSD$
# $OpenBSD: Makefile,v 1.4 2007/12/19 13:15:53 jasper Exp $

ONLY_FOR_ARCHS= 	alpha amd64 arm i386 m68k mips64 powerpc sparc64 sparc

COMMENT=		library for handling page faults in user mode

DISTNAME=		libsigsegv-2.5
SHARED_LIBS=		sigsegv 0.0
CATEGORIES=		devel
HOMEPAGE=		http://libsigsegv.sourceforge.net/

# From OpenBSD:
#MAINTAINER=		Scott Vokes <vokes.s@gmail.com>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${MASTER_SITE_GNU:=libsigsegv/}

SEPARATE_BUILD= 	concurrent

USE_LIBTOOL=		Yes

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS+=	${CONFIGURE_SHARED}

.include <bsd.port.mk>

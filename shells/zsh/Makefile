# $FabBSD$
# $OpenBSD: Makefile,v 1.48 2008/07/02 15:02:54 okan Exp $

COMMENT=	Z shell, Bourne shell-compatible

V=		4.3.6
DISTNAME=	zsh-$V
PKGNAME=	${DISTNAME}p0
CATEGORIES=	shells

# From OpenBSD:
#MAINTAINER=	Pierre-Emmanuel Andre <pea@raveland.org>

HOMEPAGE=	http://www.zsh.org/

MASTER_SITES=	ftp://ftp.zsh.org/zsh/ \
		${HOMEPAGE}pub/ \
		http://mirrors.dotsrc.org/zsh/ \
		ftp://ftp.fu-berlin.de/pub/unix/shells/zsh/ \
		http://www.math.technion.ac.il/pub/zsh/ \
		ftp://ftp.demon.nl/pub/mirrors/zsh/ \
		ftp://sunsite.icm.edu.pl/pub/unix/shells/zsh/

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	c m termcap

MODULES=	converters/libiconv

LIB_DEPENDS=	pcre::devel/pcre

AUTOCONF_VERSION=2.61
CONFIGURE_STYLE=autoconf
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
                LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	${CONFIGURE_SHARED:S/shared/dynamic/} \
		--enable-zsh-mem \
		--enable-zsh-secure-free \
		--enable-maildir-support \
		--with-tcsetpgrp \
		--enable-multibyte \
		--enable-pcre

SUBST_VARS=	V

# required for regression tests
PORTHOME=	${WRKDIR}
REGRESS_FLAGS=	INSTALL_PROGRAM="install -c -s -m 555" \
		INSTALL_DATA="install -c -m 444" \
		INSTALL="install -c" \
		TMPPREFIX=${WRKBUILD}/tmp \
		TERM=xterm

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/zsh/$V/scripts/

.include <bsd.port.mk>

# $FabBSD$
# $OpenBSD: Makefile,v 1.28 2007/09/16 00:27:05 merdely Exp $

COMMENT=	GNU's Ubiquitous Intelligent Language for Extension

DISTNAME=	guile-1.6.7
PKGNAME=	$(DISTNAME)p3
SHARED_LIBS=	guile-ltdl 1.0 \
		guile-srfi-srfi-13-14-v-1 1.0 \
		guile-srfi-srfi-4-v-1 1.0 \
		guile 15.0 \
		guilereadline-v-12 15.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

HOMEPAGE=	http://www.gnu.org/software/guile/

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c m ncurses readline

SEPARATE_BUILD=		Yes
CONFIGURE_STYLE=	gnu
USE_LIBTOOL=		Yes
USE_GMAKE=		Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/aclocal
	${INSTALL_DATA} ${WRKSRC}/guile-config/qthreads.m4 ${PREFIX}/share/aclocal
	@cd ${PREFIX}/share/guile && ln -s ../slib

.include <bsd.port.mk>

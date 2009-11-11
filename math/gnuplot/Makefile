# $FabBSD$
# $OpenBSD: Makefile,v 1.36 2008/07/02 17:53:11 ajacoutot Exp $

COMMENT=	command-driven interactive function plotting program

V=		4.2
PATCHLEVEL=	3
DISTNAME=	gnuplot-${V}.${PATCHLEVEL}
PKGNAME=	${DISTNAME}p1
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnuplot/}

HOMEPAGE=	http://www.gnuplot.info/

# From OpenBSD:
#MAINTAINER=	Weldon Goree <wgoree@bu.edu>

# see Copyright in source
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB=	c m ncurses readline stdc++ z

CONFIGURE_STYLE= gnu
CONFIGURE_ARGS=	--without-linux-vga --without-pdf \
		--without-tutorial --with-readline \
		--with-lasergnu --disable-wxwidgets --without-lisp-files
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/libpng" \
		LDFLAGS="-L${LOCALBASE}/lib"

REGRESS_IS_INTERACTIVE=	Yes
REGRESS_FLAGS=	DISPLAY=${DISPLAY} XAUTHORITY=${XAUTHORITY}

SUBST_VARS=	V

CONFIGURE_ARGS+= --without-x --without-gd

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/lasergnu ${PREFIX}/bin/lasergnu
	-cat ${PATCHDIR}/patch-* >${PREFIX}/share/gnuplot/${V}/patches

.include <bsd.port.mk>

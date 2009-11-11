# $FabBSD$
# $OpenBSD: Makefile,v 1.2 2008/07/04 15:39:17 naddy Exp $

COMMENT-main=		GNU editor: extensible, customizable, self-documenting
COMMENT-el=		elisp sources for those who want to read/modify them

VERSION=		22.2
DISTNAME=		emacs-${VERSION}
PKGNAME-main=		emacs-${VERSION}p0
FULLPKGNAME-el=		emacs-el-${VERSION}p0
FULLPKGPATH-el=		editors/emacs22,-el

CATEGORIES=		editors

HOMEPAGE=		http://www.gnu.org/software/emacs/

# From OpenBSD:
#MAINTAINER=		Eric Faurot <eric@openbsd.org>

# GPLv3
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${MASTER_SITE_GNU:=emacs/}

MULTI_PACKAGES=		-main -el

USE_GMAKE=		Yes

GCCARCH=		${MACHINE_ARCH}-unknown-fabbsd${OPSYS_VER}

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		${GCCARCH} --with-pop --localstatedir=/var

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include \
				  -I${LOCALBASE}/include/libpng" \
			LDFLAGS="-L${LOCALBASE}/lib"

# Disable propolice on powerpc due to gcc3+propolice bug.
.if ${MACHINE_ARCH} == "powerpc"
CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -fno-stack-protector"
.endif

MAKE_ENV=		INSTALL_EMACS="${INSTALL_SCRIPT}" \
			LOGNAME="${SHAREOWN}"

SUBST_VARS=		GCCARCH VERSION

WANTLIB-main=		c m ncurses

CONFIGURE_ARGS+=	--without-x

RUN_DEPENDS-el=		:emacs-${VERSION}*:${PKGPATH}
PKG_ARCH-el=		*

post-patch:
	cp -f ${FILESDIR}/fabbsd.h ${WRKSRC}/src/s

.include <bsd.port.mk>

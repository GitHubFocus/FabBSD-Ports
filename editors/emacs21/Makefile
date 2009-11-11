# $FabBSD$
# $OpenBSD: Makefile,v 1.40 2008/07/04 15:39:17 naddy Exp $

COMMENT-main=		GNU editor: extensible, customizable, self documenting
COMMENT-el=		elisp sources for those who want to read/modify them
COMMENT-leim=		Library of Emacs Input Methods

VERSION=		21.4
DISTNAME=		emacs-${VERSION}
PKGNAME-main=		${DISTNAME}p7
FULLPKGNAME-el=		emacs-el-${VERSION}p0
FULLPKGNAME-leim=	emacs-leim-${VERSION}p0

CATEGORIES=		editors

HOMEPAGE=		http://www.gnu.org/software/emacs/

# From OpenBSD:
#MAINTAINER=		Rich Cannings <cannings@openbsd.org>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		${MASTER_SITE_GNU:=emacs/}
DISTFILES=		emacs-${VERSION}a.tar.gz leim-${VERSION}.tar.gz

MULTI_PACKAGES=		-main -el -leim

GCCARCH=		${MACHINE_ARCH}-unknown-fabbsd${OPSYS_VER}

CONFIGURE_STYLE=	gnu dest
CONFIGURE_ARGS=		${GCCARCH} --with-pop --with-x=no
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include \
				  -I${LOCALBASE}/include/libpng" \
			LDFLAGS="${ELF_TOOLCHAIN:L:S/yes/-Z/:S/no//} \
				 -L${LOCALBASE}/lib"

# Disable propolice on powerpc due to gcc3+propolice bug.
.if ${MACHINE_ARCH} == "powerpc"
CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -fno-stack-protector"
.endif

MAKE_ENV=		INSTALL_EMACS="${INSTALL_SCRIPT}"

SUBST_VARS=		GCCARCH VERSION

WANTLIB-main=		c m ncurses

RUN_DEPENDS=		:emacs-${VERSION}*:${PKGPATH}
RUN_DEPENDS-main=

PKG_ARCH-el=		*

post-patch:
	cp -f ${FILESDIR}/fabbsd.h ${WRKSRC}/src/s

.include <bsd.port.mk>

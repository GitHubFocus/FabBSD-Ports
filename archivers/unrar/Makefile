# $FabBSD$
# $OpenBSD: Makefile,v 1.41 2008/06/09 08:18:01 rui Exp $

COMMENT=	extract, list, and test RAR archives

DISTNAME=	unrarsrc-3.8.1
PKGNAME=	unrar-3.81
CATEGORIES=	archivers

HOMEPAGE=	http://www.rarlab.com/

# From OpenBSD:
#MAINTAINER=	Rui Reis <rui@openbsd.org>

# Restrictive
PERMIT_PACKAGE_CDROM=	no fee
PERMIT_PACKAGE_FTP=	may not modify
PERMIT_DISTFILES_CDROM=	no fee
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c m stdc++

MASTER_SITES=	${HOMEPAGE}rar/

WRKDIST=	${WRKDIR}/unrar

MAKE_FILE=	makefile.unix
MAKE_FLAGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"

# gcc 3.3.5 internal compiler error
.if ${MACHINE_ARCH} == "mips64"
EXTRA_CFLAGS=	-O0
.endif

MAKE_FLAGS+=		EXTRA_CFLAGS=${EXTRA_CFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/unrar ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unrar
	${INSTALL_MAN} ${WRKSRC}/readme.txt ${WRKSRC}/license.txt \
		${PREFIX}/share/doc/unrar

NO_REGRESS=	Yes

.include <bsd.port.mk>

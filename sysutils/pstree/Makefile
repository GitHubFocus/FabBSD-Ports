# $FabBSD$
# $OpenBSD: Makefile,v 1.11 2007/09/15 21:14:02 merdely Exp $

COMMENT=		list processes as a tree
DISTNAME=		pstree-2.27
CATEGORIES=     	sysutils

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c 

MASTER_SITES=		http://fresh.t-systems-sfr.com/unix/src/misc/

NO_REGRESS=		Yes

WRKDIST=		${WRKDIR}

do-build:
	cd ${WRKBUILD} && ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/pstree ${PREFIX}/bin/pstree
	${INSTALL_MAN} ${FILESDIR}/pstree.1 ${PREFIX}/man/man1

.include <bsd.port.mk>

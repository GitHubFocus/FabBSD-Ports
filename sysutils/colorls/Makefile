# $FabBSD$
# $OpenBSD: Makefile,v 1.14 2007/08/11 18:41:28 naddy Exp $

COMMENT=	ls that can use color to display file attributes

DISTNAME=	ls-4.2
PKGNAME=	color${DISTNAME}
CATEGORIES=	sysutils

# From OpenBSD:
#MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	http://sites.inka.de/~mips/unix/distfiles/

WRKDIST=	${WRKDIR}/ls
NO_REGRESS=	Yes

# copy file and substitute a string near a CVS keyword
pre-patch:
	sed 's/^\.Dt LS/.Dt COLORLS/' ${WRKSRC}/ls.1 >${WRKSRC}/colorls.1

.include <bsd.port.mk>

# $FabBSD$
# $OpenBSD: Makefile,v 1.11 2007/09/15 20:34:00 simon Exp $

COMMENT=	library to create disk based hashtables
DISTNAME=	dbh-1.0.24
PKGNAME=	${DISTNAME}p0
CATEGORIES=	databases
SHARED_LIBS +=	dbh                  1.0      # .1.0

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dbh/}

HOMEPAGE=	http://dbh.sourceforge.net/

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

USE_LIBTOOL=	Yes

CONFIGURE_STYLE=gnu

.include <bsd.port.mk>

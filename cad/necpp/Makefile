# $FabBSD$
# $OpenBSD: Makefile,v 1.4 2007/09/15 21:36:57 simon Exp $

COMMENT=	NEC2++ antenna simulator

DISTNAME=	necpp-1.2.3
PKGNAME=	${DISTNAME}p0
CATEGORIES=    	cad hamradio

HOMEPAGE=	http://www.physics.otago.ac.nz/research/electronics/nec/
MASTER_SITES=	${HOMEPAGE}

# From OpenBSD:
#MAINTAINER=	Jason Wright <jason@openbsd.org>

# GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

CONFIGURE_STYLE=gnu

SHARED_LIBS=necpp 0.0

WANTLIB=c m stdc++
USE_LIBTOOL=Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/necpp
	${INSTALL_DATA} ${WRKSRC}/test_data/* ${PREFIX}/share/examples/necpp

.include <bsd.port.mk>

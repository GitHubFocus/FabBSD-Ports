# $FabBSD$
# $OpenBSD: Makefile,v 1.11 2007/09/16 00:33:57 merdely Exp $

COMMENT=	library for Japanese Input Method canna
FULLPKGNAME=	ja-onew${FLAVOR_EXT}-2.2.10

DISTNAME=	jvim2.0r+onew2.2.10
CATEGORIES=	japanese

MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Japan/onew/ \
		ftp://ftp.leo.chubu.ac.jp/pub/editor/jvim/

# From OpenBSD:
#MAINTAINER=	Marc Espie <espie@openbsd.org>

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

PERMIT_PACKAGE_CDROM=	Canna prevents it
LIB_DEPENDS+=	canna.>=1::japanese/canna

WRKDIST=	${WRKDIR}/onew
ALL_TARGET=	

ONEW_CONF=	${FILESDIR}/ONEW_CONF-for${FLAVOR_EXT}
LIB_NAME=	libonew${FLAVOR_EXT}.a
PORT_DOCDIR=	${PREFIX}/share/doc/ja-onew${FLAVOR_EXT}

post-patch:
	ln -s ${ONEW_CONF} ${WRKSRC}/ONEW_CONF

MAKE_FLAGS=LOCALBASE=${LOCALBASE} CFLAGS='${CFLAGS}'
SUBST_VARS=FLAVOR_EXT

NO_REGRESS=	Yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/libonew.a ${PREFIX}/lib/${LIB_NAME}
	${INSTALL_DATA_DIR} ${PORT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ONEW ${PORT_DOCDIR}

.include <bsd.port.mk>

# $FabBSD$
# $OpenBSD: Makefile,v 1.32 2008/01/20 17:45:26 winiger Exp $

SHARED_ONLY=		Yes

COMMENT-main=		PostgreSQL database adapter for Python
COMMENT-examples=	examples for PostgreSQL database adapter for Python

VERSION=		1.1.21
DISTNAME=		psycopg-${VERSION}
PKGNAME=		py-${DISTNAME}p6
PKGNAME-main=		py-${DISTNAME}p6
FULLPKGNAME-examples=	py-psycopg-examples-${VERSION}
CATEGORIES=		databases

HOMEPAGE=		http://initd.org/projects/psycopg1

# From OpenBSD:
#MAINTAINER=		Aleksander Piotrowski <alek@openbsd.org>

PERMIT_PACKAGE_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
WANTLIB-main=		crypto util pq

MASTER_SITES=	http://initd.org/pub/software/psycopg/

MODULES=	lang/python

BUILD_DEPENDS=	:postgresql-server-*:databases/postgresql,-server
RUN_DEPENDS=	:postgresql-client-*:databases/postgresql

FLAVORS=	python2.4 python2.5
FLAVOR?=	python2.5

.if ${FLAVOR:L:Mpython2.4} && !${FLAVOR:L:Npython2.4}
MULTI_PACKAGES=	-main
.elif ${FLAVOR:L:Mpython2.5} && !${FLAVOR:L:Npython2.5}
MULTI_PACKAGES=	-main -examples
.else
ERRORS+=	"Fatal: You must select one version: ${FLAVORS}"
.endif

MODPY_VERSION=	${FLAVOR:S/python//}
BUILD_DEPENDS+=	:py-mxDateTime->=2.0.0*-${FLAVOR}:devel/py-mxDateTime,${FLAVOR}
RUN_DEPENDS+=	:py-mxDateTime->=2.0.0*-${FLAVOR}:devel/py-mxDateTime,${FLAVOR}

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	--with-mxdatetime-includes=${MODPY_SITEPKG}/mx/DateTime/mxDateTime
CONFIGURE_ENV=	PYTHON=${MODPY_BIN}

NO_REGRESS=	Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-psycopg/
	${INSTALL_DATA} ${WRKSRC}/doc/examples/* \
		${PREFIX}/share/examples/py-psycopg/
	${CHOWN} ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/python${MODPY_VERSION}/lib-dynload/psycopgmodule.so

.include <bsd.port.mk>

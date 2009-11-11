# $FabBSD$
# $OpenBSD: Makefile,v 1.33 2008/06/24 02:46:21 kurt Exp $

REVISION=	4
VERSION=	${REVISION}.6.21
PKGNAME=	${DISTNAME}
PKGNAME-main=	${DISTNAME}
DBLIBDIR=	lib/db4
SHARED_LIBS +=	db                   0.0
SHARED_LIBS +=	db_cxx               0.0
SHARED_LIBS +=	db_tcl               0.0

MASTER_SITES0=	${HOMEPAGE}db/update/${VERSION}/

CONFIGURE_STYLE=gnu

DEST_SUBDIR=	${REVISION}
WANTLIB=	c

pre-configure:
	@perl -pi -e "s,db_(archive|checkpoint|deadlock|dump|hotbackup),db4_\1,g" ${WRKSRC}/test/*tcl
	@perl -pi -e "s,db_(load|printlog|recover|stat|upgrade|verify),db4_\1,g" ${WRKSRC}/test/*tcl
	@perl -pi -e "s,!!DBVERSION!!,${LIBdb_VERSION}," ${WRKSRC}/test/include.tcl

.include <bsd.port.mk>

# $FabBSD$
# $OpenBSD: Makefile,v 1.22 2008/07/27 10:47:53 sthen Exp $

COMMENT=	companion library to APR

V=		1.3.8
DISTNAME=	apr-util-$V
FULLPKGNAME=	apr-util${MT}-$Vp1${FLAVOR_EXT:S/-mt//}
SHARED_LIBS +=	aprutil-1${MT}          3.8

CATEGORIES=	devel

# From OpenBSD:
#MAINTAINER=	Aleksander Piotrowski <alek@openbsd.org>

HOMEPAGE=	http://apr.apache.org/

FLAVORS=	mt
FLAVOR?=

# Apache License 2.0
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_APACHE:=apr/}

WANTLIB=	expat
LIB_DEPENDS=	db::databases/db/v4

MODULES=	converters/libiconv		
USE_LIBTOOL=	Yes
CONFIGURE_STYLE=gnu autoconf
AUTOCONF_VERSION=2.59
CONFIGURE_ARGS=	--with-apr=${LOCALBASE} \
		--with-dbm=db4 \
		--with-berkeley-db=${LOCALBASE}/include/db4:${LOCALBASE}/lib/db4 \
		--with-iconv=${LOCALBASE} \
		--includedir=${LOCALBASE}/include/apr-1${MT}/ \
		--with-apr=${LOCALBASE}/bin/apr-1${MT}-config

MT?=
.if ${FLAVOR:L:Mmt}
MT=-mt
LIB_DEPENDS+=	apr-1-mt::devel/apr,mt

post-install:
	sed 's/{APRUTIL_LIBNAME}/{APRUTIL_LIBNAME}-mt/g' ${WRKSRC}/apu-config.out > ${PREFIX}/bin/apu-1-mt-config

.else
LIB_DEPENDS+=	apr-1::devel/apr
.endif

SUBST_VARS+=	MT
MAKE_ENV+=	MT=${MT}

.include <bsd.port.mk>

# $FabBSD$
# $OpenBSD: Makefile,v 1.8 2008/05/21 19:17:24 chl Exp $

COMMENT=	automatically configure source code on many Un*x platforms

DISTNAME=	autoconf-2.54
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=autoconf/}
PKGNAME=	${DISTNAME}p3

HOMEPAGE=	http://www.gnu.org/software/autoconf/
# From OpenBSD:
#MAINTAINER=	Marc Espie <espie@openbsd.org>

# GPL
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes

BUILD_DEPENDS=		:help2man-*:devel/help2man
RUN_DEPENDS=		::devel/metaauto

SUFFIX=			-2.54
CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS+=	--program-suffix=${SUFFIX} \
			--without-lispdir
CONFIGURE_ENV+=		M4="/usr/bin/m4"
CONFIGURE_ENV+=		AWK="${AWK}"
MODGNU_CONFIG_GUESS_DIRS=${WRKSRC}/config
MAKE_FLAGS=		pkgdatadir=${PREFIX}/share/autoconf${SUFFIX}
FAKE_FLAGS=		lispdir=
#USE_GMAKE=		Yes
SUBST_VARS=		SUFFIX

NO_REGRESS=		Yes

.include <bsd.port.mk>

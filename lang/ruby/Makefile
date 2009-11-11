# $FabBSD$
# $OpenBSD: Makefile,v 1.62 2008/07/25 20:25:59 sthen Exp $

SHARED_ONLY=		Yes

COMMENT-main=		object oriented script language with threads
COMMENT-iconv=		libiconv interface for ruby
COMMENT-gdbm=		gdbm interface for ruby

VERSION=		1.8.6
PATCHLEVEL=		114
DISTNAME=		ruby-${VERSION}-p${PATCHLEVEL}
SHARED_LIBS=		ruby 2.0
PKGNAME-main=		ruby-${VERSION}.${PATCHLEVEL}p2
PKGNAME-iconv=		ruby-iconv-${VERSION}.${PATCHLEVEL}p0
PKGNAME-gdbm=		ruby-gdbm-${VERSION}.${PATCHLEVEL}p0

CATEGORIES=		lang

HOMEPAGE=		http://www.ruby-lang.org/

# From OpenBSD:
#MAINTAINER=		Bernd Ahlers <bernd@openbsd.org>

# GPL/Artistic/BSD/Public Domain/Beer-Ware
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=		ftp://www.ruby-lang.org/pub/ruby/1.8/ \
                	ftp://mirror.nucba.ac.jp/pub/ruby/1.8/ \
                	ftp://ftp.kr.freebsd.org/pub/ruby/1.8/

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		${CONFIGURE_SHARED} \
			--enable-ipv6 \
			--with-dbm-type=bogus \
			--with-opt-dir="${LOCALBASE}"
CONFIGURE_ENV=		PREFIX="${PREFIX}" \
			LIBruby_VERSION=${LIBruby_VERSION} \
			CPPFLAGS="-DOPENSSL_NO_STATIC_ENGINE"

MODULES=		converters/libiconv

WANTLIB-main= 		c m readline termcap util crypto ncurses ssl z
LIB_DEPENDS-main=
RUN_DEPENDS-main=

MULTI_PACKAGES=		-main -iconv -gdbm

WANTLIB-iconv=		c m
LIB_DEPENDS-iconv=	ruby.>=1::lang/ruby \
			${MODLIBICONV_LIB_DEPENDS}
RUN_DEPENDS-iconv=	${MODLIBICONV_RUN_DEPENDS}

WANTLIB-gdbm=		c m
LIB_DEPENDS-gdbm=	gdbm.>=0::databases/gdbm \
			ruby.>=1::lang/ruby
RUN_DEPENDS-gdbm=

REGRESS_DEPENDS=	:${PKGNAME-main}:lang/ruby
INSTALL_TARGET=		install install-doc
REV=			1.8
SUB=			${MACHINE_ARCH:S/amd64/x86_64/}-fabbsd${OSREV}
SUBST_VARS=		SUB REV

# Building the ruby documentation consumes lots of memory.
VMEM_WARNING=		Yes

.include <bsd.port.mk>

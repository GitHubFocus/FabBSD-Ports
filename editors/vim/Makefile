# $FabBSD$
# $OpenBSD: Makefile,v 1.94 2008/06/20 05:24:39 ckuethe Exp $

COMMENT-main=	vi clone, many additional features
COMMENT-lang=	vi clone, NLS subpackage

DISTNAME=	vim-7.1
REVISION=	315
VERSION=	7.1.${REVISION}
# keep PKGNAME for full version number
PKGNAME=	vim-${VERSION}
PKGNAME-main=	vim-${VERSION}
PKGNAME-lang=	vim-lang-${VERSION}
P=		${DISTNAME:C/[-\.]//g}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.vim.org/pub/vim/unix/ \
		ftp://ftp.home.vim.org/pub/vim/unix/ \
		ftp://ftp.berlin.de.vim.org/unix/
MASTER_SITES0=	${MASTER_SITES:S/unix/patches\/7.1/}
MASTER_SITES1=	${MASTER_SITES:S/unix/extra/}
DISTFILES=	${DISTNAME}.tar.bz2 \
		${DISTNAME}-lang.tar.gz:1
DIST_SUBDIR=	vim71


HOMEPAGE=	http://www.vim.org/

# From OpenBSD:
#MAINTAINER=	Chris Kuethe <ckuethe@openbsd.org>

PATCHFILES=	#
_patches!=	jot -w%03d - 1 ${REVISION} 1 | \
	egrep -v '003|007|041|065|070|072|080|088|091|092|122|123|124|126|128|129|134|146|158|168|176|178|186|187|191|196|197|204|275|278|280|282|283|285|302|303|309'
.for p in ${_patches}
PATCHFILES+=	7.1.${p}:0
.endfor
PATCHFILES+=	7.1.126ne:0

# allow vim to build on m68k and vax
.if (${MACHINE_ARCH} == "m68k")
PATCH_LIST=	patch-* sup-m68k-*
.elif (${MACHINE_ARCH} == "vax")
PATCH_LIST=	patch-* sup-vax-*
.endif

# donation-ware
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes
WANTLIB=		c curses

MULTI_PACKAGES=	-main -lang

FLAVOR?=
FLAVORS=	huge perl python ruby

CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	CPPFLAGS="-I${DEPBASE}/include" \
		LDFLAGS="-L${DEPBASE}/lib"
CONFIGURE_ARGS+=--with-tlib="curses" --enable-multibyte

.if ${FLAVOR:L:Mhuge}
CONFIGURE_ARGS+=--with-features=huge
.endif

.if ${FLAVOR:L:Mperl}
CONFIGURE_ARGS+=--enable-perlinterp
WANTLIB+=	m perl util
.endif

.if ${FLAVOR:L:Mpython}
MODULES+=	lang/python
CONFIGURE_ENV+=	vi_cv_path_python=${MODPY_BIN}
CONFIGURE_ARGS+=--enable-pythoninterp \
	--with-python-config-dir=${MODPY_LIBDIR}/config
LIB_DEPENDS+=	${MODPY_LIB_DEPENDS}
WANTLIB+=	m pthread util
.endif

.if ${FLAVOR:L:Mruby}
CONFIGURE_ARGS+=--enable-rubyinterp
MAKE_ENV+=	RUBY="${DEPBASE}/bin/ruby"
LIB_DEPENDS+=	ruby::lang/ruby
WANTLIB+=	m
.endif

CONFIGURE_ARGS+=--disable-gui --without-x

RUN_DEPENDS-lang=	::${BUILD_PKGPATH}
PKG_ARCH-lang=		*
LIB_DEPENDS-lang=
WANTLIB-lang=
MODULES+=		devel/gettext

WRKDIST=	${WRKDIR}/${P}
WRKSRC=		${WRKDIST}/src

SUBST_VARS=	P

# don't try to regenerate the configure script. Works around the fact that
# auto/configure.in is newer than auto/configure.
post-patch:
	touch ${WRKBUILD}/auto/configure

post-configure:
	touch ${WRKBUILD}/auto/config.mk

post-install:
	${INSTALL_DATA} ${FILESDIR}/pf.vim ${PREFIX}/share/vim/${P}/syntax
	${INSTALL_DATA} ${FILESDIR}/ngc.vim ${PREFIX}/share/vim/${P}/syntax

.include <bsd.port.mk>

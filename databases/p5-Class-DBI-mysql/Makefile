# $FabBSD$
# $OpenBSD: Makefile,v 1.6 2007/09/15 20:34:01 simon Exp $

COMMENT=	extensions to Class::DBI for MySQL

MODULES=	cpan
DISTNAME=	Class-DBI-mysql-1.00
PKGNAME=	p5-${DISTNAME}p0
CATEGORIES=	databases

# From OpenBSD:
#MAINTAINER=	Sam Smith <S@msmith.net>

# Same as Perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

RUN_DEPENDS=	::databases/p5-Class-DBI \
		::databases/p5-DBD-mysql
REGRESS_DEPENDS=:mysql-server-*:databases/mysql,-server

REGRESS_IS_INTERACTIVE=Yes

pre-regress:
	@mysqladmin ping >/dev/null 2>&1 || (echo 'mysql needs to be running'; exit 1)
	-@mysqladmin create test >/dev/null 2>&1

.include <bsd.port.mk>

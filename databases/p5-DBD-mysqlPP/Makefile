# $FabBSD$
# $OpenBSD: Makefile,v 1.7 2007/09/15 20:34:01 simon Exp $

COMMENT=		Pure Perl MySQL driver for the Perl DBI

DISTNAME=		DBD-mysqlPP-0.04
CATEGORIES=		databases
MODULES=		cpan

# From OpenBSD:
#MAINTAINER=		Peter Stromberg <wilfried@openbsd.org>

# Perl
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

BUILD_DEPENDS=		:p5-DBI->=1.14:databases/p5-DBI \
			:p5-Net-MySQL->=0.08:net/p5-Net-MySQL
RUN_DEPENDS=		:p5-DBI->=1.14:databases/p5-DBI \
			:p5-Net-MySQL->=0.08:net/p5-Net-MySQL

.include <bsd.port.mk>

# $FabBSD$
# $OpenBSD: Makefile,v 1.8 2007/09/15 20:34:01 simon Exp $

COMMENT=	perl DBI driver for CSV files

DISTNAME=	DBD-CSV-0.21
PKGNAME=	p5-${DISTNAME}p0
CATEGORIES=	databases
MODULES=	cpan

# From OpenBSD:
#MAINTAINER=	Chris Kuethe <ckuethe@ualberta.ca>

# Perl
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

RUN_DEPENDS=	:p5-DBI->=1.08:databases/p5-DBI \
		:p5-Text-CSV_XS->0.22:textproc/p5-Text-CSV_XS \
		::databases/p5-SQL-Statement

.include <bsd.port.mk>

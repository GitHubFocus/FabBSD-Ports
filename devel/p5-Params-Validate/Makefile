# $FabBSD$
# $OpenBSD: Makefile,v 1.20 2008/01/23 21:57:50 merdely Exp $

SHARED_ONLY=	Yes

COMMENT=	perl module to validate function/method parameters

MODULES=	cpan
DISTNAME=	Params-Validate-0.89
CATEGORIES=	devel

# From OpenBSD:
#MAINTAINER=	Michael Coulter <mjc@openbsd.org>

# perl
PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

REGRESS_DEPENDS=	:p5-Test-Taint->=1.04:devel/p5-Test-Taint \
			:p5-Readonly->=1.03:devel/p5-Readonly \
			:p5-Readonly-XS->=1.04:devel/p5-Readonly-XS

.include <bsd.port.mk>

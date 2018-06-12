# $OpenBSD: Makefile,v 1.87 2011/01/15 01:09:43 naddy Exp $

COMMENT=	subversion revision control system

VERSION=	1.6.15
DISTNAME=	subversion-${VERSION}
PKGNAME=	${DISTNAME}

SO_VERSION=	1.2
SVN_LIBS=	svn_client-1 svn_delta-1 svn_diff-1 svn_fs-1 \
		svn_fs_base-1 svn_fs_fs-1 svn_fs_util-1 svn_ra-1 svn_ra_neon-1 \
		svn_ra_local-1 svn_ra_neon-1 svn_ra_svn-1 svn_repos-1 svn_subr-1 svn_wc-1
.for _lib in ${SVN_LIBS}
SHARED_LIBS+=	${_lib} ${SO_VERSION}
.endfor

CATEGORIES=	devel

HOMEPAGE=	http://subversion.apache.org

MAINTAINER=	Ports <ports@fabbsd.org>

# BSD alike + Apache License 2.0
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

# Subversion 1.6.x tarballs are still hosted at tigris.org, not apache.org
MASTER_SITES=	http://subversion.tigris.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MODULES=	devel/gettext lang/python
USE_GROFF =	Yes

# autogen.sh checks for libtoolize
#BUILD_DEPENDS=	${MODGNU_AUTOCONF_DEPENDS} \
#		devel/libtool

LIB_DEPENDS=	net/neon>=0.26.2 \
		devel/apr \
		devel/apr-util \
		security/cyrus-sasl2 \
		databases/sqlite3

WANTLIB=	expat db z asn1 c crypto gssapi krb5 ssl \
		neon>=26 apr-1 aprutil-1 sasl2>=2 sqlite3
RUN_DEPENDS=	${MODGETTEXT_RUN_DEPENDS}

CONTRIB_HOOK_SCRIPTS=	case-insensitive.py pre-commit-check.py \
	check-mime-type.pl pre-lock-require-needs-lock.py \
	commit-block-joke.py remove-zombie-locks.py \
	syntax-check.sh commit-email.pl
# There's also 'enforcer', but we handle it separately, see post-install

TOOLS_HOOK_SCRIPTS=	commit-access-control.cfg.example \
	commit-access-control.pl commit-email.rb \
	log-police.py svn2feed.py svnperms.conf.example \
	svnperms.py verify-po.py
# There's also 'mailer', but we handle it separately, see post-install

CONTRIB_CLIENT_SIDE_SCRIPTS=	incremental-update.py search-svnlog.pl \
	svn-clean svn-merge-vendor.py svn_apply_autoprops.py \
	svn_export_empty_files.py

SVN_LOAD_DIRS_FILES=	LICENSE_AFL3.txt svn_load_dirs.README \
	svn_load_dirs.pl svn_load_dirs_property_table.example

CONTRIB_SERVER_SIDE_SCRIPTS=	authz_svn_group.py fsfsverify.py \
	svn-fast-backup svn-tweak-author.py

TOOLS_CLIENT_SIDE_SCRIPTS=	bash_completion change-svn-wc-format.py \
	server-version.py showchange.pl svn-graph.pl

MAKE_FLAGS=	MAKE=${MAKE_PROGRAM}
USE_LIBTOOL=	Yes
# should be 2.63
AUTOCONF_VERSION=2.61
CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	PYTHON2=${MODPY_BIN}
CONFIGURE_ARGS+=${CONFIGURE_SHARED} \
		--with-sasl=${LOCALBASE} \
		--without-jikes \
		--without-jdk \
		--without-apxs \
		--without-swig

REGRESS_DEPENDS=${MODPY_RUN_DEPENDS}
SUBST_VARS+=	LOCALBASE SO_VERSION

pre-patch:
	@ln -s ${MODPY_BIN} ${WRKDIR}/bin/python

pre-configure:
	@${SUBST_CMD} ${WRKSRC}/Makefile.in ${WRKSRC}/configure.ac \
		${WRKSRC}/subversion/libsvn_subr/auth.c
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		AUTOCONF_VERSION=${AUTOCONF_VERSION} ./autogen.sh

post-build:
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} svnmucc
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} svnauthz-validate
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} svn-populate-node-origins-index

do-regress:
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${ALL_REGRESS_FLAGS} check FS_TYPE=bdb
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${ALL_REGRESS_FLAGS} check FS_TYPE=fsfs

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/
	${INSTALL_DATA} ${FILESDIR}/servers \
			${PREFIX}/share/examples/subversion/servers
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/client-side
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/server-side
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/hook-scripts
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/cgi
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/client-side/emacs
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/client-side/svn2cl
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/client-side/svn_load_dirs
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/hook-scripts/mailer
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/hook-scripts/mailer/tests
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/hook-scripts/enforcer
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/server-side/mod_dontdothat
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/xslt
	${INSTALL_DATA} ${WRKSRC}/contrib/cgi/* \
			${PREFIX}/share/examples/subversion/cgi
	${INSTALL_DATA} ${WRKSRC}/contrib/client-side/emacs/* \
			${PREFIX}/share/examples/subversion/client-side/emacs
	${INSTALL_DATA} ${WRKSRC}/contrib/client-side/svn2cl/* \
			${PREFIX}/share/examples/subversion/client-side/svn2cl
.for _file in ${SVN_LOAD_DIRS_FILES}
	${INSTALL_DATA} ${WRKSRC}/contrib/client-side/svn_load_dirs/${_file} \
			${PREFIX}/share/examples/subversion/client-side/svn_load_dirs
.endfor
	${INSTALL_DATA} ${WRKSRC}/contrib/server-side/mod_dontdothat/* \
			${PREFIX}/share/examples/subversion/server-side/mod_dontdothat
.for _script in ${CONTRIB_CLIENT_SIDE_SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/contrib/client-side/${_script} \
			${PREFIX}/share/examples/subversion/client-side
.endfor
.for _script in ${CONTRIB_SERVER_SIDE_SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/contrib/server-side/${_script} \
			${PREFIX}/share/examples/subversion/server-side
.endfor
	${INSTALL_DATA} ${WRKSRC}/contrib/hook-scripts/enforcer/enforcer \
			${PREFIX}/share/examples/subversion/hook-scripts/enforcer/
	${INSTALL_DATA} ${WRKSRC}/contrib/hook-scripts/enforcer/enforcer.conf \
			${PREFIX}/share/examples/subversion/hook-scripts/enforcer/
.for _hook_script in ${CONTRIB_HOOK_SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/contrib/hook-scripts/${_hook_script} \
			${PREFIX}/share/examples/subversion/hook-scripts/
.endfor
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${ALL_FAKE_FLAGS} install-tools
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/backup
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/bdb
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/subversion/xslt
	${INSTALL_DATA} ${WRKBUILD}/tools/backup/hot-backup.py \
			${PREFIX}/share/examples/subversion/backup
	${INSTALL_DATA} ${WRKSRC}/tools/bdb/* \
		${PREFIX}/share/examples/subversion/bdb
	${INSTALL_DATA} ${WRKSRC}/tools/examples/* \
		${PREFIX}/share/examples/subversion
.for _script in ${TOOLS_CLIENT_SIDE_SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/tools/client-side/${_script} \
			${PREFIX}/share/examples/subversion/client-side
.endfor
	${INSTALL_DATA} ${WRKSRC}/tools/server-side/fsfs-reshard.py \
			${PREFIX}/share/examples/subversion/server-side
	${INSTALL_DATA} ${WRKSRC}/tools/server-side/svn-backup-dumps.py \
			${PREFIX}/share/examples/subversion/server-side
	${INSTALL_PROGRAM} ${WRKSRC}/tools/server-side/svn-populate-node-origins-index.c \
		${PREFIX}/share/examples/subversion/server-side
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/README \
			${PREFIX}/share/examples/subversion/hook-scripts/
	${INSTALL_DATA} ${WRKSRC}/tools/xslt/* \
		${PREFIX}/share/examples/subversion/xslt
.for _hook_script in ${TOOLS_HOOK_SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/${_hook_script} \
			${PREFIX}/share/examples/subversion/hook-scripts/
.endfor
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/mailer/mailer.conf.example \
			${PREFIX}/share/examples/subversion/hook-scripts/mailer
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/mailer/mailer.conf.example \
			${PREFIX}/share/examples/subversion/hook-scripts/mailer
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/mailer/mailer.py \
			${PREFIX}/share/examples/subversion/hook-scripts/mailer
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/mailer/tests/* \
			${PREFIX}/share/examples/subversion/hook-scripts/mailer/tests
	find ${PREFIX}/share/examples/subversion -type f | xargs perl -pi \
		-e "s,.*/usr/bin/python.*,#!${MODPY_BIN},;" \
		-e "s,.*env python.*,#!${MODPY_BIN},;"
	find ${PREFIX}/share/examples/subversion -type f -name '*\.orig' \
		-exec rm -f {} \;

.include <bsd.port.mk>

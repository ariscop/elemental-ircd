#!/bin/bash
cd `dirname $0`
testdir=`pwd`
prefix=`sed -n -e 's/^#define IRCD_PREFIX "\(.*\)"/\1/p' "$testdir/../include/setup.h"`
[ -d $prefix ] || { echo Unable to find installation prefix; exit 1; }

echo "Using the pregenned cert"

cp testsuite/ssl* $prefix/etc
cp testsuite/dh.pem $prefix/etc

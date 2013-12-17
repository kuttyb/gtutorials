#! /bin/sh

export TCL_DIR="/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/System/Library/Frameworks/Tcl.framework/Versions/8.5"
echo "TCL dir is $TCL_DIR"
./configure --with-no-root-privileges --prefix=/Users/kutty_banerjee/data/MacPorts-2.2.1/out --with-tcl=$TCL_DIR --with-tclinclude=$TCL_DIR/Headers


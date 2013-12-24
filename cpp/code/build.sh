#! /bin/sh

pushd cpp-code
xcodebuild -target cpp-code -configuration Debug $1
popd

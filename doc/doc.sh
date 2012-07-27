#!/bin/sh

if which doxygen; then
    echo "Building documentation"
    doxygen doxygen.tpl > /dev/null
else
    echo "No doxygen binary - not building documentation"
fi

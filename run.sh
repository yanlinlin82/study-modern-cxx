#!/bin/bash

if [ -z "$1" ]; then
	echo "Usage: $0 <src/xxx.cpp>"
	exit 1
fi

while [ -n "$1" ]; do
	echo 1>&2 "======================"
	echo 1>&2 "Run '$1'"
	cat $1 | grep '^// \$ ' | cut -c6- | bash -x
	shift
done

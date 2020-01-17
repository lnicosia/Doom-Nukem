#!/bin/sh
#
# Print the current source revision, if available

hg parents --template 'hg-{rev}:{node|int}' || (echo "hg-0:baadf00d"; exit 1)

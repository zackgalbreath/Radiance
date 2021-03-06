#!/bin/csh -f
# RCSid: $Id$
# Convert Tcl/Tk help file (used by gethelp.tcl) to troff/nroff format
# for printing.
#

cat << _EOF_
.ds RH "$1:r help
.TL 
`head -1 $1`
.LP
_EOF_
exec sed -e 1d \
-e 's/^\.\([a-zA-Z][a-zA-Z0-9]*\)\.\([a-zA-Z][a-zA-Z0-9]*\)$/.B "\1 \2"/' $1

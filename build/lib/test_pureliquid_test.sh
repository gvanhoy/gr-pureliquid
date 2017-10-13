#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/gvanhoy/gr-pureliquid/lib
export PATH=/home/gvanhoy/gr-pureliquid/build/lib:$PATH
export LD_LIBRARY_PATH=/home/gvanhoy/gr-pureliquid/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-pureliquid 

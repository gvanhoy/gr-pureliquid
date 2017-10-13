#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/gvanhoy/gr-pureliquid/python
export PATH=/home/gvanhoy/gr-pureliquid/build/python:$PATH
export LD_LIBRARY_PATH=/home/gvanhoy/gr-pureliquid/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/gvanhoy/gr-pureliquid/build/swig:$PYTHONPATH
/usr/bin/python2 /home/gvanhoy/gr-pureliquid/python/qa_flex_tx.py 

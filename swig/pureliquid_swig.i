/* -*- c++ -*- */

#define PURELIQUID_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "pureliquid_swig_doc.i"

%{
#include "pureliquid/file_source.h"
#include "pureliquid/flex_tx.h"
%}

%include "pureliquid/file_source.h"
GR_SWIG_BLOCK_MAGIC2(pureliquid, file_source);

%include "pureliquid/flex_tx.h"
GR_SWIG_BLOCK_MAGIC2(pureliquid, flex_tx);

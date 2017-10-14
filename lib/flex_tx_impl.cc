/* -*- c++ -*- */
/*
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "flex_tx_impl.h"

namespace gr {
  namespace pureliquid {

    flex_tx::sptr
    flex_tx::make(unsigned int modulation, unsigned int inner_code, unsigned int outer_code)
    {
      return gnuradio::get_initial_sptr
        (new flex_tx_impl(modulation, inner_code, outer_code));
    }

    /*
     * The private constructor
     */
    flex_tx_impl::flex_tx_impl(unsigned int modulation, unsigned int inner_code, unsigned int outer_code)
      : gr::sync_block("flex_tx",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(0, 0, 0))
    {

    }

    /*
     * Our virtual destructor.
     */
    flex_tx_impl::~flex_tx_impl()
    {
    }

    int
    flex_tx_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {

    }

  } /* namespace pureliquid */
} /* namespace gr */


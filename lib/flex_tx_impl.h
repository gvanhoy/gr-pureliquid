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

#ifndef INCLUDED_PURELIQUID_FLEX_TX_IMPL_H
#define INCLUDED_PURELIQUID_FLEX_TX_IMPL_H

#include <pureliquid/flex_tx.h>
#include <liquid/liquid.h>

namespace gr {
  namespace pureliquid {

    class flex_tx_impl : public flex_tx
    {
     private:
         flexframegenprops_s    d_fgprops;
         flexframegen           d_fg;

     public:
      flex_tx_impl(unsigned int modulation, unsigned int inner_code, unsigned int outer_code);
      ~flex_tx_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace pureliquid
} // namespace gr

#endif /* INCLUDED_PURELIQUID_FLEX_TX_IMPL_H */


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


#ifndef INCLUDED_PURELIQUID_FLEX_TX_H
#define INCLUDED_PURELIQUID_FLEX_TX_H

#include <pureliquid/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace pureliquid {

    /*!
     * \brief <+description of block+>
     * \ingroup pureliquid
     *
     */
    class PURELIQUID_API flex_tx : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<flex_tx> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of pureliquid::flex_tx.
       *
       * To avoid accidental use of raw pointers, pureliquid::flex_tx's
       * constructor is in a private implementation
       * class. pureliquid::flex_tx::make is the public interface for
       * creating new instances.
       */
      static sptr make(unsigned int modulation, unsigned int inner_code, unsigned int outer_code);
      virtual void set_modulation(unsigned int modulation) = 0;
      virtual void set_inner_code(unsigned int inner_code) = 0;
      virtual void set_outer_code(unsigned int outer_code) = 0;
    };

  } // namespace pureliquid
} // namespace gr

#endif /* INCLUDED_PURELIQUID_FLEX_TX_H */


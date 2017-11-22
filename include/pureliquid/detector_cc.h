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


#ifndef INCLUDED_PURELIQUID_DETECTOR_CC_H
#define INCLUDED_PURELIQUID_DETECTOR_CC_H

#include <pureliquid/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace pureliquid {

    /*!
     * \brief <+description of block+>
     * \ingroup pureliquid
     *
     */
    class PURELIQUID_API detector_cc : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<detector_cc> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of pureliquid::detector_cc.
       *
       * To avoid accidental use of raw pointers, pureliquid::detector_cc's
       * constructor is in a private implementation
       * class. pureliquid::detector_cc::make is the public interface for
       * creating new instances.
       */
      static sptr make(std::vector<gr_complex>  &symbols);
    };

  } // namespace pureliquid
} // namespace gr

#endif /* INCLUDED_PURELIQUID_DETECTOR_CC_H */

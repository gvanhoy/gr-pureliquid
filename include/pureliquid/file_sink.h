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


#ifndef INCLUDED_PURELIQUID_FILE_SINK_H
#define INCLUDED_PURELIQUID_FILE_SINK_H

#include <pureliquid/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace pureliquid {

    /*!
     * \brief <+description of block+>
     * \ingroup pureliquid
     *
     */
    class PURELIQUID_API file_sink : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<file_sink> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of pureliquid::file_sink.
       *
       * To avoid accidental use of raw pointers, pureliquid::file_sink's
       * constructor is in a private implementation
       * class. pureliquid::file_sink::make is the public interface for
       * creating new instances.
       */
      static sptr make(std::string file_name);
    };

  } // namespace pureliquid
} // namespace gr

#endif /* INCLUDED_PURELIQUID_FILE_SINK_H */


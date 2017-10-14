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

#ifndef INCLUDED_PURELIQUID_FILE_SINK_IMPL_H
#define INCLUDED_PURELIQUID_FILE_SINK_IMPL_H

#include <pureliquid/file_sink.h>
#include <fstream>
#include <iostream>

namespace gr {
  namespace pureliquid {

    class file_sink_impl : public file_sink
    {
     private:
         std::string d_file_name;
         std::ofstream d_output_stream;

     public:
      file_sink_impl(std::string file_name);
      ~file_sink_impl();

      // Where all the action really happens
      void write_contents(pmt::pmt_t payload_data);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace pureliquid
} // namespace gr

#endif /* INCLUDED_PURELIQUID_FILE_SINK_IMPL_H */


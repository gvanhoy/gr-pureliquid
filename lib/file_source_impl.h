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

#ifndef INCLUDED_PURELIQUID_FILE_SOURCE_IMPL_H
#define INCLUDED_PURELIQUID_FILE_SOURCE_IMPL_H

#include <pureliquid/file_source.h>
#include <string>
#include <sstream>

namespace gr {
  namespace pureliquid {

    class file_source_impl : public file_source
    {
     private:
         boost::shared_ptr<gr::thread::thread> d_thread;
         std::string d_file_name;
         bool d_repeat;
         unsigned int d_period_ms;
         pmt::pmt_t d_msg;

     public:
      file_source_impl(std::string fileName, bool repeat, unsigned int d_period_ms);
      ~file_source_impl();
      bool start();
      bool stop();
      void run();

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace pureliquid
} // namespace gr

#endif /* INCLUDED_PURELIQUID_FILE_SOURCE_IMPL_H */


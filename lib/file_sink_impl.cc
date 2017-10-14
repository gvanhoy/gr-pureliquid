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
#include "file_sink_impl.h"

namespace gr {
  namespace pureliquid {

    file_sink::sptr
    file_sink::make(std::string file_name)
    {
      return gnuradio::get_initial_sptr
        (new file_sink_impl(file_name));
    }

    /*
     * The private constructor
     */
    file_sink_impl::file_sink_impl(std::string file_name)
      : gr::block("file_sink",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(0, 0, 0)),
              d_file_name(file_name)
    {
        std::ofstream d_output_stream(d_file_name.c_str(), std::fstream::out);
        if(!d_output_stream.is_open()) std::cout << "Could not open " << d_file_name << std::endl;

        message_port_register_in(pmt::mp("pdus"));
        set_msg_handler(pmt::mp("pdus"), boost::bind(&file_sink_impl::write_contents, this, _1));
    }

    /*
     * Our virtual destructor.
     */
    file_sink_impl::~file_sink_impl()
    {
        d_output_stream.close();
    }

    void file_sink_impl::write_contents(pmt::pmt_t payload_data){
        pmt::pmt_t bytes = pmt::cdr(payload_data);
        d_output_stream << bytes;
    }

    int
    file_sink_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
        std::cout << "This is not a streaming block" << std::endl;
    }

  } /* namespace pureliquid */
} /* namespace gr */


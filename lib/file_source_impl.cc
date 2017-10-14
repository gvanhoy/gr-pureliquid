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
#include <gnuradio/blocks/pdu.h>
#include "file_source_impl.h"
#include <iostream>
#include <sstream>
#include <fstream>

namespace gr {
  namespace pureliquid {

    file_source::sptr
    file_source::make(std::string file_name, bool repeat, unsigned int period_ms)
    {
      return gnuradio::get_initial_sptr
        (new file_source_impl(file_name, repeat, period_ms));
    }

    /*
     * The private constructor
     */
    file_source_impl::file_source_impl(std::string file_name, bool repeat, unsigned int period_ms)
      : gr::block("file_source",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(0, 0, 0)),
              d_file_name(file_name),
              d_repeat(repeat),
              d_period_ms(period_ms)
    {
        std::ifstream input_file_stream(d_file_name.c_str(), std::fstream::in);
        if(!input_file_stream.is_open()) std::cout << "Could not open " << d_file_name << std::endl;

        std::ostringstream file_contents;
        file_contents << input_file_stream.rdbuf();

        std::string temp_string = file_contents.str();

        std::vector<uint8_t> buffer;
        buffer.insert(buffer.begin(), temp_string.begin(), temp_string.end());
        pmt::pmt_t vec_contents = pmt::init_u8vector(buffer.size(), buffer);
        pmt::pmt_t d_msg(pmt::cons(pmt::PMT_NIL, vec_contents));

        std::cout << "Constructed pdu: " << d_msg << std::endl;

        message_port_register_out(PDU_PORT_ID);
    }

    /*
     * Our virtual destructor.
     */
    file_source_impl::~file_source_impl()
    {
    }

    bool
    file_source_impl::start()
    {
        d_thread = boost::shared_ptr<gr::thread::thread>
        (new gr::thread::thread(boost::bind(&file_source_impl::run, this)));

      return block::start();
    }

    bool
    file_source_impl::stop()
    {
      d_thread->interrupt();
      d_thread->join();

      return block::stop();
    }

    void file_source_impl::run()
    {
        if(d_repeat){
            while(true) {
                std::cout << "Sending new message" << std::endl;
                boost::this_thread::sleep(boost::posix_time::milliseconds(d_period_ms));
                message_port_pub(PDU_PORT_ID, d_msg);
            }
        }
        else{
            message_port_pub(PDU_PORT_ID, d_msg);
        }
    }

    int
    file_source_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
        std::cout << "This is not a streaming block" << std::endl;
    }

  } /* namespace pureliquid */
} /* namespace gr */


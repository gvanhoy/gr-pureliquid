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
#include "detector_cc_impl.h"
#include <iostream>

namespace gr {
  namespace pureliquid {

    detector_cc::sptr
    detector_cc::make(const std::vector<gr_complex>  &symbols)
    {
      return gnuradio::get_initial_sptr
        (new detector_cc_impl(symbols));
    }

    /*
     * The private constructor
     */
    detector_cc_impl::detector_cc_impl(const std::vector<gr_complex>  &symbols)
      : gr::sync_block("detector_cc",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(1, 1, sizeof(gr_complex)))
    {
        d_detector = qdetector_cccf_create(symbols.data(), symbols.size());
    }

    /*
     * Our virtual destructor.
     */
    detector_cc_impl::~detector_cc_impl()
    {
        qdetector_cccf_destroy(d_detector);
    }

    int
    detector_cc_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      gr_complex *in = (gr_complex *) input_items[0];
      gr_complex *out = (gr_complex *) output_items[0];
      void *sample;

      for(unsigned int i = 0; i < noutput_items; i++){
        sample = qdetector_cccf_execute(d_detector, in[i]);
        out[i] = in[i];
        if(sample != NULL){
            std::cout << "Detected packet!" << std::endl;
            std::cout << "Dphi: " << qdetector_cccf_get_dphi(d_detector) << std::endl;
            std::cout << "Gamma: " << qdetector_cccf_get_gamma(d_detector) << std::endl;
            std::cout << "Phy: " << qdetector_cccf_get_phi(d_detector) << std::endl;
            std::cout << "Tau: " << qdetector_cccf_get_tau(d_detector) << std::endl;
            sample = NULL;
        }
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace pureliquid */
} /* namespace gr */


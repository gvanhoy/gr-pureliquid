#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 
# Copyright 2017 <+YOU OR YOUR COMPANY+>.
# 
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

import numpy
from gnuradio import gr
import pmt

class file_sink(gr.basic_block):
    """
    docstring for block file_sink
    """
    def __init__(self, file_name):
        gr.basic_block.__init__(self,
            name="file_sink",
            in_sig=[],
            out_sig=[])
        self.message_port_register_in(pmt.intern("pdus"))
        self.set_msg_handler(pmt.intern("pdus"), self.handler)
        self.file = open(file_name, "w")

    def handler(self, pdu):
        data = pmt.to_python(pmt.cdr(pdu))
        self.file.write(data)
        self.file.write("\n")
        self.file.flush()

    def general_work(self, input_items, output_items):
        output_items[0][:] = input_items[0]
        consume(0, len(input_items[0]))
        #self.consume_each(len(input_items[0]))
        return len(output_items[0])

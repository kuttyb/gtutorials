#!/usr/bin/tclsh

# Return a dword of Physical Memory
proc read_memory_dword {addr } {
    puts "reading $addr"

    return 10
}

# Dump out MMU Table setup for a Given Virtual Address
proc gvtop {contextid va {verbose 0}} {
    if {$verbose == 1} {
	puts "gvtop: verbose output"
    }

    set value  [read_memory_dword $va]

    return $value
}

set return_value [gvtop 0 0x2000 1]

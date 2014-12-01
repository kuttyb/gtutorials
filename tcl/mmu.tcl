#!/usr/bin/tclsh

# Return a dword of Physical Memory
proc read_memory_dword {addr } {
    puts "reading $addr"

    return 0xffff000
}

# Dump out MMU Table setup for a Given Virtual Address
proc gvtop {contextid va {verbose 0}} {
    if {$verbose == 1} {
	puts "gvtop: verbose output"
    }

    set dword [read_memory_dword $va]
    set base  [expr [expr $dword >> 12] & 0x3]

    puts "modified value is $base"

    set base [read_memory_dword $base]
    return $base
}

set return_value [gvtop 0 0x2000 1]

#!/usr/bin/tclsh

# Return a dword of Physical Memory
proc read_memory_dword {addr } {
    return 0xffff000
}

proc dump_memory {start dwords} {
    puts "Dumpign memory $start and $dwords dwords"
    for {set index 0} {$index < $dwords} {incr index} {
	set addr [expr $start + [expr $index * 4]]
	if {[expr $index % 8] == 0} {
	    puts ""
	    puts -nonewline "[format 0x%-8x: $addr] "
	} 
	puts -nonewline " [format 0x%-8x [read_memory_dword $addr]]"
    }
    puts ""
    return 0
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

    set x [dump_memory $base 16]

    return $base
}

set return_value [gvtop 0 0x2000 1]

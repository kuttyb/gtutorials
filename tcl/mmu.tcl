#!/usr/bin/tclsh

# Return a dword of Physical Memory
proc read_memory_dword {addr } {
    return [expr 0xffff000 | $addr]
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

# Returns the Physical address of start of CATBASE
proc read_catbase_index {context_id} {
    # Read the actual GPU Register but for now fake it
    # to test the logic
    return 0xabcd0000
}

# Dump out MMU Table setup for a Given Virtual Address
proc gvtop {context_id va {verbose 0}} {
    if {$verbose == 1} {
	puts "gvtop: verbose output"
    }

    # Obtain catbase 
    set catbase_addr [read_catbase_index context_id]

    # Split Virtual Address into 3 level indices
    set catalogue_index  0
    set directory_index  0
    set pagetable_index  0


    set dword [read_memory_dword $va]
    set base  [expr [expr $dword >> 12] & 0x3]

    puts "modified value is $base"

    set base [read_memory_dword $base]

    set x [dump_memory $base 16]

    return $base
}

set return_value [gvtop 0 0x2000 1]

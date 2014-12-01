#!/usr/bin/tclsh

proc dump_memory {start dwords} {
    puts "Dumpign memory $start and $dwords dwords"
    for {set index 0} {$index < $dwords} {incr index} {
	set addr [expr $start + [expr $index * 4]]
	if {[expr $index % 8] == 0} {
	    puts ""
	    puts -nonewline "[format 0x%-8x: $addr] "
	} 
	puts -nonewline " [format 0x%-8x $addr]"
    }
    puts ""
}

# $stride is in bytes
proc dump_memory_indexed {start stride index elements} {
    set real_start   [expr $start + [expr $index * $stride]]
    set real_dwords  [expr $elements * $stride / 4]

    return [dump_memory $real_start $real_dwords]
}

# Apparently, can't have just a simple proc invocation, needs to be assigned
# to something else
set value [dump_memory 4096 16]
puts "================"
set value [dump_memory_indexed 4096  16  4 3]

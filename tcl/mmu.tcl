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
    # {31 - 24}  {23 - 12}  {12 - 0}
    # TODO: kbb: Verify the actual offsets from the manual
    # TODO: kbb: Verify the actual size of each entry in the various levels
    set catalogue_index  [expr $va >> 24]
    set directory_index  [expr [expr $va >> 12] & 0xfff]
    set pagetable_index  [expr [expr $va & 0xfff]]

    # ==================================================
    # Process First Level (at each level print
    # the entry and the address its at)
    # ==================================================
    set catalogue_entry [read_memory_dword [expr $catbase_addr + [expr $catalogue_index * 4]]]
    # Test if catalogue entry is valid
    if {[expr $catalogue_entry & 0x1] != 1} {
	puts "Catalogue entry does not exist at index $catalogue_index"
	return 0
    }
    puts "$catbase_addr: $catalogue_entry"
    set directory_addr [expr $catalogue_entry & ~0xfff]

    # ==================================================
    # Process Second Level
    # ==================================================
    set directory_entry [read_memory_dword [expr $directory_addr + [expr $directory_index * 4]]]
    if {[expr $directory_entry & 0x1] != 1} {
	puts "Directory entry does not exist at index $directory_index"
	return 0
    }
    puts "$directory_addr: $directory_entry"
    set pagetable_addr [expr $directory_entry & ~0xfff]

    # ==================================================
    # Process Last Level
    # ==================================================
    set pagetable_entry [read_memory_dword [expr $pagetable_addr + [expr $pagetable_index * 8]]]
    if {[expr $pagetable_entry & 0x1] != 1} {
	puts "PageTable entry does not exist at index $pagetable_index"
	return 0
    }
    puts "$pagetable_addr: $pagetable_entry"
    set pagetable_addr [expr $pagetable_entry & ~0xfff]

    return 0
}

set return_value [gvtop 0 0x2000 1]

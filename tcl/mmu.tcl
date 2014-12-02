#!/usr/bin/tclsh

# Return a dword of Physical Memory
proc read_memory_dword {addr } {
    return [expr 0xffff000 | $addr]
}


# For Verbose dumping of Paga Table levels
proc dump_memory {start dwords} {
    for {set index 0} {$index < $dwords} {incr index} {
	set addr [expr $start + [expr $index * 4]]
	if {[expr $index % 8] == 0} {
	    if {$index != 0} {
		puts ""
	    }
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
# ===============================
# Tunables per Chip Architecture:
# ===============================
#       [a] #bits   each level uses from the Virtual Address
#       [b] #bytes  each entry at each level consumes
#       [c] bitpos  for the address into next level 
#       [d] bitpos  for the valid bit in each level's entry
#       [e] large_page handling (whether they are coalesced or contigous)
#       [f] catbase_index register read and obtain catbase address
proc gvtop {context_id va {cat_verbose 0} {dir_verbose 0} {pt_verbose 0}} {
    # Obtain catbase 
    set catbase_addr [read_catbase_index $context_id]

    # Obtain the Indices for each level from the Virtual Address
    # {31 - 24}  {23 - 12}  {12 - 0}
    set catalogue_index  [expr $va >> 24]
    set directory_index  [expr [expr $va >> 12] & 0xfff]
    set pagetable_index  [expr [expr $va & 0xfff]]
    # Track what levels are valid
    set catalogue_valid  1
    set directory_valid  1
    set pagetable_valid  1

    # ==================================================
    # Process First Level (at each level print
    # the entry and the address its at)
    # ==================================================
    set catalogue_entry [read_memory_dword [expr $catbase_addr + [expr $catalogue_index * 4]]]
    # Test if catalogue entry is valid
    if {[expr $catalogue_entry & 0x1] != 1} {
	puts "Catalogue entry does not exist at index $catalogue_index"
	set catalogue_valid 0
	set directory_valid 0
	set pagetable_valid 0
    } else {
	# TODO: kbb: All the else clauses have the address incorrect, its the base address not adjusted for the offset
	puts "CATALOGUE: [format 0x%-8x $catbase_addr] : [format 0x%-8x $catalogue_entry]"
    }

    # ==================================================
    # Process Second Level
    # ==================================================
    if {$directory_valid == 1} {
	set directory_addr [expr $catalogue_entry & ~0xfff]
	set directory_entry [read_memory_dword [expr $directory_addr + [expr $directory_index * 4]]]
	if {[expr $directory_entry & 0x1] != 1} {
	    puts "Directory entry does not exist at index $directory_index"
	    set pagetable_valid 0
	} else {
	    puts "DIRECTORY: [format 0x%-8x $directory_addr] : [format 0x%-8x $directory_entry]"
	}
    }

    # ==================================================
    # Process Last Level
    # ==================================================
    if {[expr $directory_valid && $pagetable_valid] == 1} {
	set pagetable_addr [expr $directory_entry & ~0xfff]
	set pagetable_entry [read_memory_dword [expr $pagetable_addr + [expr $pagetable_index * 8]]]
	if {[expr $pagetable_entry & 0x1] != 1} {
	    puts "PageTable entry does not exist at index $pagetable_index"
	    return 0
	} else {
	    puts "PAGETABLE: [format 0x%-8x $pagetable_addr] : [format 0x%-8x $pagetable_entry]"
	}
    }

    # For verbose, print out entrire catalogue, directory and page table
    # for the said indices
    if {$cat_verbose == 1} {
	if {$catalogue_valid == 1} {
	    puts "Printing Entire Catalogue for VA $va"
	    # Print Catbase   (entire level)
	    set x [dump_memory $catbase_addr 256]
	}
    }

    if {$dir_verbose == 1} {
	if {$directory_valid && $pagetable_valid} {
	    # print Directory (entire level)
	    set x [dump_memory $directory_addr 2048]
	}
    }

    if {$pt_verbose == 1} {
	if {$pagetable_valid == 1} {
	    # Print PageTable (entire level)
	    set x [dump_memory $pagetable_addr 4096]
	}
    }

    return 0
}

set return_value [gvtop 0 0x2000 1 1 1]

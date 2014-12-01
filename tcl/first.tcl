#!/usr/bin/tclsh

set a 3
# nested expressions can be a pain, think LISP style functions except [expr ...] so 
# expr at the start
set b [expr [expr $a + 5] * 2]
puts "and the value is $b"

# Lists
set alist {first second third}
puts [lindex $alist 2]

set blist {1 2 3}
puts [lindex $blist 1]

# Maps (arrays are maps with consecutive integer keys)
puts "====================="
set map(first)   10
set map(second)  20
set map(third)   40
puts $map(second)
puts [array size map]
puts "====================="

# branches (expressions and strings)
if {[expr 10 < 20]} {
    puts "branch worked"
} else {
    puts "branch else path worked"
}
puts "====================="

set first   "first"
set second  "first"

# Works like regular strcmp wrt the return value
if {[string compare $first $second] == 0} {
    puts "string comparison worked"
} else {
    puts "string comparison failed"
}

# loops
puts "====================="
set value 10
for {set index 0} {$index < 10} {incr index} {
    set value [expr $value + 10]
}
puts "after the loop, value is $value"

# strings
puts "====================="
set str "first stupid  string"
puts "string length is [string length $str]"


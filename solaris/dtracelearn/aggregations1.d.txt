#! /usr/sbin/dtrace -s

/** Learn some more about dtrace aggregations
    Oh and as you can see execname, probefunc causes the final
    output to contain those fields in a formatted order.
 */

syscall:::entry
{
	@counts[execname, probefunc] = count();
}

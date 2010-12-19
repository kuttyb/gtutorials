#! /usr/sbin/dtrace -s

syscall:::entry
/ execname == $1 /
{
	@db[probefunc] = count();
}

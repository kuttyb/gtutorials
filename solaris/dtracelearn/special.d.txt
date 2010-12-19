#! /usr/sbin/dtrace -s

syscall::write:entry
/ execname == "firefox" /
{
	ustack();
	exit(0);
}

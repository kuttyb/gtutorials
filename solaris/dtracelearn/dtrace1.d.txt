#! /usr/sbin/dtrace -s
#pragma D option quiet

syscall::read:entry
{
	@sys[probefunc] = count();
}


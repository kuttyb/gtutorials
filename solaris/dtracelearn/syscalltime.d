#! /usr/sbin/dtrace -s

syscall:::entry
/ execname == "emacs-gtk" /
{
	self->ts = timestamp;
}

syscall:::return
/ self->ts /
{
	@database[execname, probefunc] = quantize(timestamp - self->ts);
	self->ts = 0;	
}

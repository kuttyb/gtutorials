#! /usr/sbin/dtrace -s

/** MORAL:
    Note how per thread aggregation is later summed up and displayed.
    Other thing to note being the quantize(arg) function.
*/

syscall::write:entry
{
	self->ts = timestamp;
}

syscall::write:return
/ self->ts /
{
	@db[execname] = quantize(timestamp -self->ts);
	self->ts = 0;	
}

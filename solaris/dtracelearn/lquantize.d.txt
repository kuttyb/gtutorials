#! /usr/sbin/dtrace -s

/** MORAL:
    While quantize will aggregate over the entire range used in powers of 2,
    lquantize will allow you to regard only the range in question and in the step 
    mentioned. So now you will see 4 distinct range values.
*/

syscall::write:entry
{
	@localDB[execname] = lquantize(arg0, 0, 500, 100);
}

#! /usr/sbin/dtrace -s

dtrace:::BEGIN
{
	i = 0;
	printf("start value of i is 0x%x\n", i);
}

/** profile:::tick-1X is the probe where X can be msec/sec */
profile:::tick-1sec
/ i < 0xa /
{
	i++;
	printf("current value i is 0x%x\n", i);
}

dtrace:::END
{
	i++;
	printf("final value of i ix 0x%x\n", i);
	exit(0);
}

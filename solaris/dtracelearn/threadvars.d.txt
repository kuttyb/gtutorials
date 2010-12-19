#! /usr/sbin/dtrace -s

dtrace:::BEGIN
{
}

syscall::read:return,
syscall::write:return
{
	self->localArg0 = arg0;
	printf("Thread 0x%x localArg0 = 0x%x\n", tid, self->localArg0);
}

dtrace:::END
{
}

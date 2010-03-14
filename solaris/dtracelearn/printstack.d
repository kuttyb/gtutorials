#! /usr/sbin/dtrace -s

syscall::write:entry
/ execname == $$1 /
{
	printf("       syscall::write:entry \n");
	printf("==== user mode stack  ====\n");
	ustack();
	printf("==== kernel mode stack ====\n");
	stack();
}

syscall::pollsys:entry
/ execname == $$1 /
{
	printf("        syscall::pollsys:entry\n");
	printf("==== user mode stack ====\n");
	ustack();
	printf("==== kernel mode stack ====\n");
	stack();
}

syscall::read:return
/ execname == $$1 /
{
	printf("        syscall::read:return\n");
	printf("==== user mode stack ====\n");
	ustack();
	printf("==== kernel mode stack ====\n");
	stack();
}

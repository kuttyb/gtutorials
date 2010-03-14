#! /usr/sbin/dtrace -s

syscall::read:return,
syscall::write:return
/pid == $1/
{
	printf("value = %d\n", arg1);
}

/** MORAL:
    $1 , $2 stands for arguments to the dtrace script 
    arg1, arg2 stand for arguments to the probe 
*/
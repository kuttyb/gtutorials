#! /usr/sbin/dtrace -s

int localDB[string];

syscall::write:entry
{
	@storedValues["write system calls"] = count();
	localDB["write"] = localDB["write"] + 1;
}

dtrace:::END
{
	printf("total write system calls = %d\n", localDB["write"]);
	exit(0);
}

/** MORAL:
    When using aggregate functions like count() you can use @associativearrays
    it automatically does the aggregation and accumulation between different threads
    and printing when the script gets completed for you. So you dont have to write
    dtrace:::END part like you just did 
*/

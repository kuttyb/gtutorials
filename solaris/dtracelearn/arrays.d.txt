#! /usr/sbin/dtrace -s

dtrace:::BEGIN
{
	a["hello", 23] = "cat";
	a["hello", 42] = "one";
	printf("%s", a["hello", 42]);	
	printf("\t%s\n", a["hello", 23]);	
}

dtrace:::END
{
	exit(0);
}

/** MORAL:
    a["hello", 23] declares a table with a string int and stores a third column
    whose value is what is being assigned viz., String.

    For example a["hello", 42] = 2 instead of "one" would cause a compile error
    since the 3rd column has already been defined as a String.
*/

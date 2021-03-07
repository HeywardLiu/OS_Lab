//STUDENT ID: 0511330

#include <linux/syscalls.h>
#include <linux/kernel.h>

SYSCALL_DEFINE3(syscalltest_returnIndividualValues, int, studentId, int, a, int, b)
{
	printk("[%d] syscalltest_returnIndividualValues : %d, %d\n", studentId, a, b);
	return 0;
}

SYSCALL_DEFINE3(syscalltest_addition, int, studentId, int, a, int, b) 
{
	printk("[%d] syscalltest_addition : %d, %d, %d\n", studentId, a, b, a+b);
	return a+b;
}

SYSCALL_DEFINE3(syscalltest_multiplication, int, studentId, int, a, int, b) 
{
	printk("[%d] syscalltest_multiplication : %d, %d, %d\n", studentId, a, b, a*b);
	return a*b;
}

SYSCALL_DEFINE1(syscalltest_dataTypes, int, studentId) {

	printk("[%d] Size of unsinged int : %d bytes.\n"       , studentId, sizeof(unsigned int));
	printk("[%d] Size of singed int : %d bytes.\n"         , studentId, sizeof(signed int));
	printk("[%d] Size of unsigned long : %d bytes.\n"      , studentId, sizeof(unsigned long));
	printk("[%d] Size of signed long : %d bytes.\n"        , studentId, sizeof(signed long));
	printk("[%d] Size of unsigned long long : %d bytes.\n" , studentId, sizeof(unsigned long long));
	printk("[%d] Size of signed long long : %d bytes.\n"   , studentId, sizeof(signed long long));
	printk("[%d] Size of double : %d bytes.\n"             , studentId, sizeof(double));	
	printk("[%d] Size of char : %d bytes.\n"               , studentId, sizeof(char));

	return 0;
}



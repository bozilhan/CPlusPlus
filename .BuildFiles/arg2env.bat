::Converts each argument and value into a environment variable
:: arguments must be in the form 	arg=arg_value	Thus an environment variable called 
:: arg is created with its value equal to arg_value i.e. SOL_TYPE=Release 		 

@echo off

:parse_arguments

IF "%1" neq "" (
	set %1=%2
	SHIFT
	SHIFT
	goto:parse_arguments
)

.intel_syntax noprefix # Use Intel syntax
	      
	      .global main	    # Expose main to the linker
	      .extern puts	    # Require puts as an external function

	      .section .text	    # Start the .text section, where the main
				    # code lives.

main:	                            # This is called by the C library startup code
	      lea   rdi, message    # First integer (or pointer) argument in rdi
	      call  puts	    # puts(message)
	      ret		    # Return from main back into C library wrapper

	      
	      .section .data	    # Start the .data section, where static
				    # data  lives
message:
	      .asciz   "Hello, world!" # Note strings must be terminated with 0 in C


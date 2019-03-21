.intel_syntax noprefix
	      .global my_memcmp
	      .section .text

my_memcmp:
        xor r8, r8
        jmp loop
infinity_begone:        
        mov al, byte ptr[rdi+r8]
        sub al, byte ptr[rsi+r8]
        jnz end
        inc r8
loop:   
        cmp r8, rdx
        jnz infinity_begone
end:
        movsx rax, al
        ret

        

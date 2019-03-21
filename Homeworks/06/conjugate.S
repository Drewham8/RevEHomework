.intel_syntax noprefix
        .global conjugate

        .section .text

conjugate:
        xor rax, rax     	# moves normal amount into register
        sub eax, dword ptr[rdi+4]
        mov dword ptr[rdi+4], eax
        ret

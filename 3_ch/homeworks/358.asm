section .data
codes:

section .text
global _start
; nasm -f elf64 -g -F dwarf 358.asm -o prog.o
; ld prog.o -o prog
; echo $? 
decode2:
  sub     rsi, rdx ; rsi = rsi - rdx
  imul    rdi, rsi ; rdi = rdi * rsi
  mov     rax, rsi ; rax = rsi
  shl     rax, 63  ; rax = rax << 63
  sar     rax, 63  ; rax = rax >> 63
  xor     rax, rdi ; rax = rax ^ rdi
  ret

_start:
  ; Argumentos da função:
  ; rdi = x
  ; rsi = y
  ; rdx = z

  mov     rdi, 10
  mov     rsi, 20
  mov     rdx, 5

  call    decode2

  ; rax contém o retorno.
  ; Usaremos esse valor como código de saída.

  ; rax = 0xffffffffffffff69

  mov     rdi, rax
  mov     rax, 60         ; syscall: exit
  syscall
# GCC notes

Compile com gcc -O0 -S para ver o assembly.

-g: Add debugging information for tools like

-O0: No optimization (best for debugging).

-c	Assemble without linking: Creates object files.

-z execstack : allow execution code in stack 

-fno-stack-protector : disable canary

-no-pie : Desativa PIE (Position Independent Executable). O binário é compilado como executável de endereço fixo

-w : random of the acl 

-z execstack -fno-stack-protector -no-pie -w 

# Objdump 

Objdump (objdump -d para desmontar, -t para símbolos).

# GDB notes

### Ver onde está o código
info proc map

### Ver símbolos próximos ao endereço
info symbol 0x0000555555551fa

### Ver o que está em um endereço de código
x/10i 0x0000555555551fa

### Ver a pilha completa
x/40gx $rsp

### Ver o frame atual
bt

### Ver registradores
info registers

## Como Encontrar o Endereço de Retorno
#### O endereço de retorno está em [RBP + 8]
x/gx $rbp + 8

#### Ver o valor no topo da pilha
x/gx $rsp

#### OU ver com contexto
x/2gx $rsp   # Mostra: [endereço de retorno] [RBP antigo]

# Mostra informações do frame atual
info frame

# Mostra o endereço de retorno salvo
info frame 0

# Mostra informações do frame atual
info frame

# Mostra o endereço de retorno salvo
info frame 0

# Ver o endereço de retorno e o que tem lá
x/2gx $rsp

# Ver o endereço de retorno e desassemblar
x/i *(unsigned long *)($rbp + 8)

# Ver o frame completo
info frame

# Ver a pilha de chamadas
where
# ou
backtrace
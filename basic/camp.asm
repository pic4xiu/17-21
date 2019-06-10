data segment
buffer db 128,?,128 dup(0)
num dw 0
words dw 0
other dw 0
crlf db 0ah,0dh,'$'
data ends

stack segment stack
dw 20h dup(?)
top label word
stack ends

code segment
    assume ds:data,cs:code,ss:stack
camp proc far
start:
    mov ax,data
    mov ds,ax
    mov ax,stack
    mov ss,ax
    lea sp,top

 lea dx,buffer
 mov ah,0Ah
 int 21h
 mov ah,9h
 lea dx,crlf
 int 21h
 lea si,buffer
 inc si
 mov cl,[si]
 xor ch,ch
l0:
 inc si 
 mov al,[si]
 cmp al,30h
 jl l1
 cmp al,39h
 ja l1
 inc num 
 jmp l4
l1:
 cmp al,'a'
 jl l3
 cmp al,'z'
 ja l3
 inc words
 jmp l4
l3:
 cmp al,'A'
 jl l6
 cmp al,'Z'
 ja l6
 inc words
 jmp l4
l6:
 inc other
l4:
 loop l0
 mov cx,3
 lea si,num
l5:
 mov ah,2
 mov dx,[si]
 add dl,30h
 int 21h
 add si,2
 mov ah,9
 lea dx,crlf
 int 21h
 loop l5
 mov ah,4ch
 int 21h
code ends
camp endp
end start
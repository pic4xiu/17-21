
data segment
N dw 0111111100001101b
data ends

stack segment stack
dw 20h dup(?)
top label word
stack ends

code segment
    assume ds:data,cs:code,ss:stack
p proc far

    mov ax,data
    mov ds,ax

    mov ax,stack
    mov ss,ax
    lea sp,top

    mov bx,n



    mov cx,4
l1: push cx     
    mov cl,4

    rol bx,cl
    mov dl,bl
    and dl,1111b    

    add dl,30h  

    cmp dl,39h
    jbe input
    add dl,7
input:
    mov ah,02h
    int 21h 
    pop cx
    loop l1 

    mov ah,4ch
    int 21h

p endp
    code ends
    end p



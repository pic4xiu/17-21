data segment

socre db 76,69,84,90,73,88,99,63,100,80

s6 db 0
s7 db 0
s8 db 0
s9 db 0
s10 db 0
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


    lea si,socre
    mov cx,10

l1: mov al,[si]
    call pppp
    inc si
    loop l1

    call input  
    jmp exit



pppp proc near

    cmp al,100
    je is10

    cmp al,69
    jbe is6

    cmp al,79
    jbe is7

    cmp al,89
    jbe is8

    cmp al,99
    jbe is9

is6:
    inc s6
    ret
is7:
    inc s7
    ret
is8:
    inc s8
    ret
is9:
    inc s9
    ret
is10:
    inc s10
    ret

pppp endp

input proc near

    lea si,s6
    mov cx,5

l2: mov dl,[si]
    add dl,30h
    mov ah,02h
    int 21h

    mov dl,0ah
    mov ah,02h
    int 21h

    inc si
    loop l2
    ret
input endp


exit:
    mov ah,4ch
    int 21h     

    p endp      
code ends 
    end p
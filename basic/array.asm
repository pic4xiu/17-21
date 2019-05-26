data segment
str1 db 'arrayP:','$'    
str2 db 'arrayN:','$'
array  dw -1,-2,-3,-4,-5,-6,-7,-8,-7,-8,-9,-1,-1,-1,-2,3,4,5,6,7 
data ends
 
ext segment
	pdata dw 20 dup(?)
	ndata dw 20 dup(?)
	a db 30h       
	b db 30h
ext ends    
 
code segment
assume cs:code,ds:data,es:ext
start:
    mov ax,data
    mov ds,ax
    mov ax,ext
    mov es,ax 
    
    lea bx,array
    lea si,pdata
    lea di,ndata
    mov cx,20
    
T:  mov ax,[bx]
    cmp ax,0
    jg P
    mov es:[di],ax 
    add es:[a],1
    add di,2
    jmp L
 P: mov es:[si],ax 
    add es:[b],1  
    add si,2 
 
 L:add bx,2
 loop T   
 
 mov dx,offset str1
    mov ah,09h
    int 21h
    mov ah,2
    mov dl,es:[b] 
    cmp dl,3ah
    jb  q
    mov cl,dl
    sub cl,10
    mov dl,'1'
    int 21h
    mov dl,cl
q:
    int 21h
    
    mov dl,20h
    mov ah,2
    int 21h
    
 mov dx,offset str1
    mov ah,09h
    int 21h
    mov ah,2
    mov dl,es:[a]
    cmp dl,3ah
    jb  m
    mov cl,dl
    sub cl,10
    mov dl,'1'
    int 21h
    mov dl,cl
m:
    int 21h
 
    mov ax,4c00h
    int 21h
code ends
end start 
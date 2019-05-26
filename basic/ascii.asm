codesg segment
assume CS:codesg
start:
 mov ah,1                     
 int 21h
 mov bl,al                  
 mov ah,2
 mov dl,':'                                 
 int 21h
 mov cx,8                                
again:
 shl bl,1                     
 mov dl,0                               
 adc dl,30h                        
 mov ah,2
 int 21h 
 loop again 
 mov ax,4c00h
 int 21h
codesg ends
end start
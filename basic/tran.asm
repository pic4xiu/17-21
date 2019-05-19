	.model small
	.stack
	.data
buf	db 255
	db 0
	db 255 dup(?)
	.code
	mov ax,@data
	mov ds,ax
	mov dx,seg buf
	mov ds,dx			;使ds为buf的段地址
	mov dx,offset buf			;使dx为buf的偏移地址
	mov ah,0Ah
	int 21h				;输入字符串
	mov si,offset buf
	inc si
	inc si				;使si的值让出前两个字符
	mov cx,0ffh
again: 	lodsb				;串操作
	cmp al,0dh			;比较al和回车符
	jz done
	cmp al,61h			;61h为a，小于则直接展示
	jb display
	sub al,20h			;否则减20h
display:	mov ah,02h
	mov dl,al
	int 21h
	loop again
done:	mov ax,4c00h
	int 21h
	end

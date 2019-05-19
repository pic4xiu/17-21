	.model small
	.stack
	.data
msg 	db 'Input Number:0-9',0dh,0ah,'$'
wrong 	db 'ERROR',0dh,0ah,'$'	;定义两个提示输出
	.code
	mov ax,@data
	mov ds,ax
	mov dx,offset msg
	mov ah,9h
	int 21h		;输出msg内容
again: 	mov ah,1h
	int 21h		;输入字符
	cmp al,'0'
	jb next
	cmp al,'9'
	ja next		;判断是否跳转
	mov dl,al
	mov ah,2h
	int 21h
	jmp done
next:  	mov dx,offset wrong
	mov ah,9h
	int 21h		;输出wrong内容
	jmp again
done:	int 3h
	mov ax,4c00h
	int 21h
	end

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <lua5.1/lua.h>
#include <lua5.1/lualib.h>
#include <lua5.1/lauxlib.h>
char flag[0x20];
char* c;
uint8_t *enc(uint8_t *data, int size) {
	uint8_t *temp = (uint8_t *)malloc(size);
	int k[3]={2,3,5};
	int i;
	if (size) {
		for (i = 0; i < size; i++) {
			temp[i] = data[i]^k[i%3];
		}
	return temp;
	}
}
int main()
{
	setvbuf(stdout,0,2,0);
	FILE *f = fopen("main.lua", "rb");
	if (f == NULL)
		return -1;
	fseek(f, 0, SEEK_END);
	long file_size = ftell(f);
	uint8_t *buf = (uint8_t *)malloc(file_size);
	rewind(f);
	fread(buf, sizeof(char), file_size, f);
	uint8_t *rea = enc(buf,file_size);
	lua_State *luaEnv = lua_open();
	luaopen_base(luaEnv);
	luaL_openlibs(luaEnv);
	if(!luaEnv)
	{
		return -1;
	}
	int loadInfo = luaL_loadstring(luaEnv,rea);
	if(loadInfo)
	{
		return -1;
	}

	int i,j,a,k=3;
	puts("Hello I'm lua.\nLet's experience something different");
	while(k){
		puts("Enter two numbers in your heart;)");
		scanf("%d",&i);
		scanf("%d",&j);
		lua_pcall(luaEnv,0,0,0);
		lua_getglobal(luaEnv,"hndl");
		lua_pushnumber(luaEnv,i);
		lua_pushnumber(luaEnv,j);
		puts("mamimami hon~~~~");
		lua_pcall(luaEnv,2,1,0);
		a=lua_tonumber(luaEnv,-1);
		puts("who am I?");
		sleep(1);
		printf("%d!!\n",a);
		if(a==random())
			k--;
		else
		{	puts("Your ideas are different from Lua's :( sry");
			exit(0);
		}
	}
	char b[4];
	FILE *fp;
	fp = fopen("flag","r");
	fread(flag,1,0x20,fp);
	puts("All right,the magic failed");
	read(0,b,280);
	return 0;
}
/*
function BitXOR(a,b)
    local p,c=1,0
    while a>0 and b>0 do
        local ra,rb=a%2,b%2
        if ra~=rb then c=c+p end
        a,b,p=(a-ra)/2,(b-rb)/2,p*2
    end
    if a<b then a=b end
    while a>0 do
        local ra=a%2
        if ra>0 then c=c+p end
        a,p=(a-ra)/2,p*2
    end
    return c
end

function hndl(i,j)
	j = BitXOR(5977654,j)
	return BitXOR(i,j)
end
*/

// HelloLuaCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

#define lua_open()  luaL_newstate()

/* the Lua interpreter */
lua_State* L;

int main ( int argc, char *argv[] )
{
	/* initialize Lua */
	L = lua_open();

	/* load Lua base libraries */
	luaL_openlibs(L);

	/* run the script */
	luaL_dofile(L, "test.lua");

	/* cleanup Lua */
	lua_close(L);

	/* pause */
	printf( "Press enter to exit..." );
	getchar();

	return 0;
}
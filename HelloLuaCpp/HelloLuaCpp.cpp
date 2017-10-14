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

// Calls to Lua
int luaadd(int x, int y)
{
	int sum;

	/* the function name */
	lua_getglobal(L, "add");

	/* the first argument */
	lua_pushnumber(L, x);

	/* the second argument */
	lua_pushnumber(L, y);

	/* call the function with 2 arguments, return 1 result */
	lua_call(L, 2 /* argument_count */, 1 /* return_count */);

	/* get the result */
	sum = (int) lua_tointeger(L, -1);
	lua_pop(L, 1);

	return sum;
}


int main ( int argc, char *argv[] )
{
	// Lesson 1
	
	/* initialize Lua */
	L = lua_open();

	/* load Lua base libraries */
	luaL_openlibs(L);

	/* run the script */
	luaL_dofile(L, "test.lua");

	/* cleanup Lua */
	lua_close(L);

	// Lesson 2: Calling Lua from C++

	int sum;

	/* initialize Lua */
	L = lua_open();

	/* load Lua base libraries */
	luaL_openlibs(L);

	/* load the script */
	luaL_dofile(L, "add.lua");

	/* call the add function */
	sum = luaadd(10, 15);

	/* print the result */
	printf("The sum is %d\n", sum);

	/* cleanup Lua */
	lua_close(L);

	// Lesson 3: Calling C++ from Lua

	/* pause */
	printf( "Press enter to exit..." );
	getchar();

	return 0;
}


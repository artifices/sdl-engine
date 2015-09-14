#include "engine.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main(int argc, char* argv[])
{	
	Engine engine;
	engine.execute();
	_CrtDumpMemoryLeaks();

	return 0;
}

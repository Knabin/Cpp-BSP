#include <iostream>

#include "define.h"
#include "include.h"

#include "GenerateMap.h"

int main()
{
	srand(time(NULL));
	auto* map = new GenerateMap();
	map->Start();

	return 0;
}
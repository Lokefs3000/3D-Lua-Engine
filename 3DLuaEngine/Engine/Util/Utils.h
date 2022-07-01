#pragma once

#include <list>
#include <fstream>
#include <iostream>

static class Utils
{
public:
	static std::list<char*> readPathAsLines(char* path);
};


#include "ConsoleUtility.h"

void ConsoleUtility::pause()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
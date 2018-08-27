#include "FileLoader.h"

// Public functions

// add top most files to vector
std::vector<std::experimental::filesystem::path> FileLoader::loadTopDown(const std::experimental::filesystem::path& currentPath)
{
	std::vector<std::experimental::filesystem::path> fileVector;

	loadTopDownHelper(fileVector, currentPath);

	return fileVector;
}

// add bottom most files to vector
std::vector<std::experimental::filesystem::path> FileLoader::loadBottomUp(const std::experimental::filesystem::path& currentPath)
{
	std::vector<std::experimental::filesystem::path> fileVector;

	loadBottomUpHelper(fileVector, currentPath);

	return fileVector;
}

std::vector<std::experimental::filesystem::path> FileLoader::getDirectoryFiles(const std::experimental::filesystem::path& currentPath)
{
	std::vector<std::experimental::filesystem::path> fileVector;

	if (std::experimental::filesystem::exists(currentPath) && std::experimental::filesystem::is_directory(currentPath))
	{
		for (std::experimental::filesystem::directory_entry p : std::experimental::filesystem::directory_iterator(currentPath))
		{
			fileVector.push_back(p.path());
		}
	}

	return fileVector;
}

// Private functions

void FileLoader::loadTopDownHelper(std::vector<std::experimental::filesystem::path>& fileVector, const std::experimental::filesystem::path& currentPath)
{
	if (std::experimental::filesystem::exists(currentPath))
	{
		if (std::experimental::filesystem::is_directory(currentPath))
		{

		}
		else if (std::experimental::filesystem::is_regular_file(currentPath)) // && ISVALIDEXTENSION( currentPath.extension())
		{
			fileVector.push_back(currentPath);
		}
	}

	
}

void FileLoader::loadBottomUpHelper(std::vector<std::experimental::filesystem::path>& fileVector, const std::experimental::filesystem::path& currentPath)
{
	if (std::experimental::filesystem::exists(currentPath))
	{
		if (std::experimental::filesystem::is_directory(currentPath))
		{

		}
		else if (std::experimental::filesystem::is_regular_file(currentPath)) // && ISVALIDEXTENSION( currentPath.extension())
		{
			fileVector.push_back(currentPath);
		}
	}
}
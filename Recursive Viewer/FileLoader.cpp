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

void FileLoader::splitDirectoriesFromFiles(const std::vector<std::experimental::filesystem::path>& allFiles, std::vector<std::experimental::filesystem::path>& directories, std::vector<std::experimental::filesystem::path>& regularFiles)
{
	for (int i = 0; i < allFiles.size(); ++i)
	{
		if (std::experimental::filesystem::is_directory(allFiles[i]))
		{
			directories.push_back(allFiles[i]);
		}
		else if (std::experimental::filesystem::is_regular_file(allFiles[i])) // && ISVALIDEXTENSION( currentPath.extension())
		{
			regularFiles.push_back(allFiles[i]);
		}
	}
}

// Private functions

void FileLoader::loadTopDownHelper(std::vector<std::experimental::filesystem::path>& fileVector, const std::experimental::filesystem::path& currentPath)
{
	if (std::experimental::filesystem::exists(currentPath))
	{
		if (std::experimental::filesystem::is_directory(currentPath))
		{
			std::vector<std::experimental::filesystem::path> directories;
			std::vector<std::experimental::filesystem::path> regularFiles;

			splitDirectoriesFromFiles(getDirectoryFiles(currentPath), directories, regularFiles);

			// Files then directories
			for (int i = 0; i < regularFiles.size(); ++i)
			{
				fileVector.push_back(regularFiles[i]);
			}
			for (int i = 0; i < directories.size(); ++i)
			{
				loadBottomUpHelper(fileVector, directories[i]);
			}
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
			std::vector<std::experimental::filesystem::path> directories;
			std::vector<std::experimental::filesystem::path> regularFiles;

			splitDirectoriesFromFiles(getDirectoryFiles(currentPath), directories, regularFiles);

			// Directories then files
			for (int i = 0; i < directories.size(); ++i)
			{
				loadBottomUpHelper(fileVector, directories[i]);
			}
			for (int i = 0; i < regularFiles.size(); ++i)
			{
				fileVector.push_back(regularFiles[i]);
			}
		}
		else if (std::experimental::filesystem::is_regular_file(currentPath)) // && ISVALIDEXTENSION( currentPath.extension())
		{
			fileVector.push_back(currentPath);
		}
	}
}
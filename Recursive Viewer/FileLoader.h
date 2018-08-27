#pragma once
#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include <vector>
#include <filesystem>

class FileLoader
{
public:
	static std::vector<std::experimental::filesystem::path> loadTopDown(const std::experimental::filesystem::path& currentPath);
	static std::vector<std::experimental::filesystem::path> loadBottomUp(const std::experimental::filesystem::path& currentPath);
	static std::vector<std::experimental::filesystem::path> getDirectoryFiles(const std::experimental::filesystem::path& currentPath);
	static void splitDirectoriesFromFiles(const std::vector<std::experimental::filesystem::path>& allFiles, std::vector<std::experimental::filesystem::path>& directories, std::vector<std::experimental::filesystem::path>& regularFiles);

private:

	static void loadTopDownHelper(std::vector<std::experimental::filesystem::path>& fileVector, const std::experimental::filesystem::path& currentPath);
	static void loadBottomUpHelper(std::vector<std::experimental::filesystem::path>& fileVector, const std::experimental::filesystem::path& currentPath);
};

#endif
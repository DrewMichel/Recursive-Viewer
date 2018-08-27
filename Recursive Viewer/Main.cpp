#include <vector>
#include <filesystem>
#include <iostream>
#include <limits>
#include "FileLoader.h"

#include "ConsoleUtility.h"

using namespace std; // refactor later
// namespace fs = std::experimental::filesystem; // shorten namespace

int main(int argc, char *argv[])
{
	//cout << argc << endl;
	//cout << argv[0] << endl;

	int position = 0;

	if (argc >= position + 1)
	{
		experimental::filesystem::path primaryPath(argv[position]);

		//experimental::filesystem::file_type ftype;

		//primaryPath = primaryPath.root_directory();

		//cout << primaryPath.parent_path() << endl;

		primaryPath = primaryPath.parent_path(); // MODIFY THIS

		if (experimental::filesystem::exists(primaryPath)) // Determines if the file exists
		{
			if (experimental::filesystem::is_directory(primaryPath)) // Directory
			{
				cout << primaryPath << " is a directory" << endl;

				//vector<experimental::filesystem::path> directoryFiles = FileLoader::getDirectoryFiles(primaryPath.parent_path());
				vector<experimental::filesystem::path> directoryFiles = FileLoader::getDirectoryFiles(primaryPath);

				cout << directoryFiles.size() << endl;

				for (int i = 0; i < directoryFiles.size(); ++i)
				{
					cout << directoryFiles[i] << endl;
				}
			}
			else if(experimental::filesystem::is_regular_file(primaryPath)) // Regular file
			{
				cout << primaryPath << " is a regular file" << endl;
			}
		}
	}

	// Usage of filesystem
	//std::cout << std::experimental::filesystem::path(argv[0]).extension() << std::endl;

	//std::cout << std::experimental::filesystem::is_directory(std::experimental::filesystem::path(argv[0])) << std::endl;

	ConsoleUtility::pause();

	return 0;
}
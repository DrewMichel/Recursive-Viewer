#include <vector>
#include <filesystem>
#include <iostream>
#include <limits>
#include "FileLoader.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>

#include "ConsoleUtility.h"

using namespace std; // refactor later
// namespace fs = std::experimental::filesystem; // shorten namespace

int main(int argc, char *argv[])
{
	QApplication qApplicationInstance(argc, argv);
	QMainWindow qMainWindowInstance;
	//QLabel hello("<center>Welcome to my first label</center>");
	//hello.setWindowTitle("First title");
	//hello.resize(400, 400);
	//hello.show();

	QMenuBar *qMenuBarInstance = new QMenuBar();

	qMainWindowInstance.resize(400, 400);
	qMainWindowInstance.setWindowTitle("Window Title");

	QMenu qFileMenuInstance("Menu");
	qFileMenuInstance.addAction("Sub Action");
	qFileMenuInstance.addAction("Sub Menu");
	qMenuBarInstance->addMenu(&qFileMenuInstance);
	qMenuBarInstance->addSeparator();
	qMenuBarInstance->addAction("Action");
	qMainWindowInstance.setMenuBar(qMenuBarInstance);

	//qMainWindowInstance.addToolBar("Tool Bar");

	//qMenuBarInstance->show();
	qMainWindowInstance.show();
	//qMainWindowInstance.showFullScreen();
	//qMenuBarInstance->hide();


	return qApplicationInstance.exec();

	//cout << argc << endl;
	//cout << argv[0] << endl;

	int position = 1;

	// TODO: OPEN GUI

	// TODO: scan argv for flags and file

	if (argc >= position + 1)
	{
		experimental::filesystem::path primaryPath(argv[position]);

		//experimental::filesystem::file_type ftype;

		//primaryPath = primaryPath.root_directory();

		//cout << primaryPath.parent_path() << endl;

		//primaryPath = primaryPath.parent_path(); // MODIFY THIS

		if (experimental::filesystem::exists(primaryPath)) // Determines if the file exists
		{
			if (experimental::filesystem::is_directory(primaryPath)) // Directory
			{
				cout << primaryPath << " is a directory" << endl;

				//vector<experimental::filesystem::path> directoryFiles = FileLoader::getDirectoryFiles(primaryPath.parent_path());

				//vector<experimental::filesystem::path> directoryFiles = FileLoader::loadBottomUp(primaryPath);
				vector<experimental::filesystem::path> directoryFiles = FileLoader::loadTopDown(primaryPath);

				for (int i = 0; i < directoryFiles.size(); ++i)
				{
					cout << directoryFiles[i] << endl;
				}

				cout << "NUMBER OF FILES: " << directoryFiles.size() << endl;
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

	cout << "Press enter to continue..." << endl;
	ConsoleUtility::pause();

	return 0;
}
#ifndef D_MAIN_WINDOW_H
#define D_MAIN_WINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtCore/QMetaObject>
#include <QtWidgets/QFileDialog>
#include "FileLoader.h"
#include <vector>
#include <filesystem>

class DMainWindow : public QMainWindow
{
	private:
		// Member variables
		QString recentFilePath;
		std::vector<std::experimental::filesystem::path> filePaths;

	//Q_OBJECT
	public:

		// Constructors
		DMainWindow();
		DMainWindow(QWidget *parent, Qt::WindowFlags *flags);

	signals:
	public slots:
		void openFileDialog();
		void openDirectoryDialog();
};

#endif
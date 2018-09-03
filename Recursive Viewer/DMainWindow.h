#ifndef D_MAIN_WINDOW_H
#define D_MAIN_WINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtCore/QMetaObject>
#include <QtWidgets/QFileDialog>
#include "FileLoader.h"
#include <vector>
#include <filesystem>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtGui/QCloseEvent>

class DMainWindow : public QMainWindow
{
	private:
		// Member variables
		QString recentFilePath;
		std::vector<std::experimental::filesystem::path> filePaths;
		QLabel imageLabel;
		QScrollArea imageScrollArea;

	//Q_OBJECT
	public:

		// Constructors
		DMainWindow();
		DMainWindow(QWidget *parent, Qt::WindowFlags *flags);

		// Functions

		bool displayImage(int index);
		bool setup();

		void resizeEvent(QResizeEvent *qEvent);
		void closeEvent(QCloseEvent *qEvent);

	signals:
	public slots:
		void openFileDialog();
		void openDirectoryDialog();
};

#endif
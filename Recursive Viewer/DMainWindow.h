#ifndef D_MAIN_WINDOW_H
#define D_MAIN_WINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtCore/QMetaObject>
#include <QtWidgets/QFileDialog>

class DMainWindow : public QMainWindow
{
	private:
		// Member variables
		QString recentFilePath;

	//Q_OBJECT
	public:

		// Constructors
		DMainWindow();
		DMainWindow(QWidget *parent, Qt::WindowFlags *flags);

	signals:
	public slots:
		void openFileDialog();
};

#endif
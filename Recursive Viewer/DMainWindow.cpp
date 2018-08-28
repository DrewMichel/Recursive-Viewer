#include "DMainWindow.h"


// Constructors
DMainWindow::DMainWindow() : QMainWindow()
{

}

DMainWindow::DMainWindow(QWidget *parent = nullptr, Qt::WindowFlags *flags = nullptr) : QMainWindow(parent, *flags)
{

}

// signals

// slots
void DMainWindow::openFileDialog()
{
	recentFilePath = QFileDialog::getOpenFileName(this);

	setWindowTitle(recentFilePath);
}
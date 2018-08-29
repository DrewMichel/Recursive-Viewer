#include "DMainWindow.h"
#include <string>
#include <QFlags>

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
	//QFlags<QFileDialog::Options> flags;
	QFileDialog::Options flags(QFileDialog::AnyFile);// | QFileDialog::ReadOnly | QFileDialog::DontUseNativeDialog);

	//QUrl url = QFileDialog::getOpenFileUrl(this, QObject::tr("Open File"), QDir::home, QObject::tr("All files (*.*);; Text files (*.txt)"), &QObject::tr("All files (*.*)"), flags);
	//QUrl url = QFileDialog::getOpenFileUrl(this, QObject::tr("Open File"));
	//recentFilePath = url.toString();

	recentFilePath = QFileDialog::getOpenFileName(this, QObject::tr("Open File"), QDir::homePath(), QObject::tr("All files (*.*);; Text files (*.txt)"), &QObject::tr("All files (*.*)"), flags);

	if (!recentFilePath.isEmpty())
	{
		filePaths = FileLoader::loadBottomUp(recentFilePath.toStdString());

		setWindowTitle(QString(std::to_string(filePaths.size()).data()));
	}
	else
	{
		// warning
	}
}

void DMainWindow::openDirectoryDialog()
{
	QFileDialog::Options flags(QFileDialog::AnyFile);

	recentFilePath = QFileDialog::getExistingDirectory(this, QObject::tr("Open Directory"), QDir::homePath(), flags);

	if (!recentFilePath.isEmpty())
	{
		filePaths = FileLoader::loadBottomUp(recentFilePath.toStdString());

		setWindowTitle(QString(std::to_string(filePaths.size()).data()));
	}
	else
	{
		// warning
	}
}
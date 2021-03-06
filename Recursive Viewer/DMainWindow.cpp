#include "DMainWindow.h"
#include <string>
#include <QFlags>
#include "GeneralConstants.h"

// Constructors
DMainWindow::DMainWindow() : QMainWindow()
{
	setup();
}

DMainWindow::DMainWindow(QWidget *parent = nullptr, Qt::WindowFlags *flags = nullptr) : QMainWindow(parent, *flags)
{
	setup();
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

		//setWindowTitle(QString(std::to_string(filePaths.size()).data()));

		displayImage(0);
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

		//setWindowTitle(QString(std::to_string(filePaths.size()).data()));

		displayImage(0);
	}
	else
	{
		// warning
	}
}

bool DMainWindow::displayImage(int index)
{
	if (index >= 0 && index < filePaths.size())
	{
		QPixmap pixmapImage(QPixmap(filePaths[index].string().data()));

		imageLabel.setPixmap(pixmapImage);
		imageLabel.resize(imageLabel.pixmap()->size());
		//imageLabel.setAlignment(Qt::AlignCenter);
		imageLabel.setIndent(0);
		imageLabel.setMargin(0);
		imageScrollArea.resize(this->size().width(), this->size().height());
		imageLabel.resize(this->size().width() - SCROLLING_PREVENTION_OFFSET, this->size().height() - SCROLLING_PREVENTION_OFFSET);
		imageScrollArea.setVisible(true);
		return true;
	}

	return false;
}

bool DMainWindow::setup()
{
	
	imageScrollArea.setParent(this);
	imageLabel.setParent(&imageScrollArea);

	imageLabel.setBackgroundRole(QPalette::Base);
	imageLabel.setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	imageLabel.setScaledContents(true);

	
	//imageLabel.setParent(this);
	
	imageScrollArea.setBackgroundRole(QPalette::Dark);
	imageScrollArea.setWidget(&imageLabel);

	imageScrollArea.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	imageScrollArea.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//imageScrollArea.setVisible(true);
	//setCentralWidget(&imageScrollArea);
	imageScrollArea.setVisible(false);

	return true;
}

void DMainWindow::resizeEvent(QResizeEvent *qEvent)
{
	QMainWindow::resizeEvent(qEvent);
	imageScrollArea.resize(this->size().width(), this->size().height());
	imageLabel.resize(this->size().width() - SCROLLING_PREVENTION_OFFSET, this->size().height() - SCROLLING_PREVENTION_OFFSET); // prevents minor scrolling
}

void DMainWindow::closeEvent(QCloseEvent *qEvent)
{
	qEvent->ignore();

	exit(1);
}
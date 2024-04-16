#include "ViewLogDialog.h"

#include <QHBoxLayout>
#include <QFileDialog>
#include <QTimer>
#include <QTextStream>

ViewLogDialog::ViewLogDialog(/*QWidget *parent*/)
{
		this->setWindowTitle(u8"日志");
		//this->setAttribute(Qt::WA_DeleteOnClose, true);
		setupLayout();

		levelColor[0].set("critical]", Qt::red);
		levelColor[1].set("error]", QColor(200, 0, 0));
		levelColor[2].set("warning]", QColor(207, 204, 41));
		levelColor[3].set("info]", QColor(0, 200, 0));
		levelColor[4].set("debug]", QColor(90, 180, 90));
		levelColor[5].set("trace]", QColor(90, 220, 90));

		lastModifiedTime = QDateTime::currentDateTime();
		readLogFile();

		timer = new QTimer(this);
		timer->start(500);
		connect(timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
}

ViewLogDialog::~ViewLogDialog()
{

}

// layout
void ViewLogDialog::setupLayout()
{
	logText = new QTextEdit();
	logText->setReadOnly(true);
	logText->setFontFamily("Consolas");
	logText->setFontPointSize(12);
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	mainLayout->addWidget(logText);
}

// Highlight log leve: Error, warning, trace, info, debug
void ViewLogDialog::highlightText()
{
	QTextDocument* document = logText->document();

	for (int i = 0; i < 6; ++i) {
		QTextCursor highlight_cursor(document);
		QTextCharFormat color_format(highlight_cursor.charFormat());
		color_format.setForeground(levelColor[i].color);
		while (!highlight_cursor.isNull() && !highlight_cursor.atEnd()) {
			highlight_cursor = document->find(levelColor[i].level, highlight_cursor, QTextDocument::FindWholeWords);
			if (!highlight_cursor.isNull()) {
				highlight_cursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor);
				highlight_cursor.mergeCharFormat(color_format);
			}
		}
	}
}

// Read log file's content
void ViewLogDialog::readLogFile()
{
	QFile file(logFilePath);
	if (!file.open(QFile::ReadOnly | QFile::Text))
		return;

	logText->setText(file.readAll());
	file.close();
	highlightText();
	logText->moveCursor(QTextCursor::End);
}

void ViewLogDialog::delLog()
{	
	QFile file(logFilePath);
	if (!file.open(QFile::WriteOnly | QFile::Truncate)) {
		return;
	}
	// 创建文本流并写入空字符串
	QTextStream stream(&file);
	stream << "";
	logText->setText(file.readAll());
	file.close();
}

// slot of timer
// check log file every 500ms
void ViewLogDialog::handleTimeout()
{
	QFileInfo fileInfo(logFilePath);
	QDateTime modifiedTime = fileInfo.lastModified();

	// log file was changed
	if (modifiedTime != lastModifiedTime) {
		lastModifiedTime = modifiedTime;
		readLogFile();
	}
}

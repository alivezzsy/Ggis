#pragma once

#include <QDialog>
#include <QTextEdit>
#include <QFileInfo>
#include <QDateTime>

struct LogLevelColor {
	void set(const char* levelStr, const QColor& colorIn) {
		snprintf(level, 12, levelStr, strlen(levelStr));
		color = colorIn;
	}
	char level[12] = { 0 };
	QColor color;
};

class ViewLogDialog :public QDialog
{
	Q_OBJECT
public:
	ViewLogDialog(/*QWidget *parent*/);
	~ViewLogDialog();

	// layout
	void setupLayout();

	// Highlight log level: Error, warning, trace, info, debug
	void highlightText();

	void readLogFile();

	void delLog();

public slots:
	// check log file every 500ms
	void handleTimeout();

public:
	QTextEdit* logText;

private:
	QTimer* timer;
	LogLevelColor levelColor[6];
	QDateTime lastModifiedTime;
	const char* logFilePath = "logs/basic-logger.txt";
};


#include "js.h"

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QScriptEngine>
#include <QScriptValue>



js::js(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	connect(ui.btncube_, SIGNAL(clicked())
		, this, SLOT(OnCubeClickedSlot()));
	connect(ui.btnfactorial_, SIGNAL(clicked())
		, this, SLOT(OnfactorialClickedSlot()));
	connect(ui.btnpi_, SIGNAL(clicked())
		, this, SLOT(OnpiClickedSlot()));
}

js::~js()
{

}

void js::OnCubeClickedSlot()
{
	QFile file("cube.js");
	if (!file.open(QIODevice::ReadOnly))
		return;

	QTextStream in(&file);
	in.setCodec("UTF-8");
	QString script = in.readAll();

	QScriptEngine interpreter;
	interpreter.installTranslatorFunctions();
	interpreter.evaluate(script, "cube.js");

	QScriptValueList args;
	args << 10;

	QScriptValue funSquare = interpreter.globalObject().property("square");

	QScriptValue result = funSquare.call(QScriptValue(), args);
	int rtn = result.toNumber();
}

void js::OnfactorialClickedSlot()
{

}

void js::OnpiClickedSlot()
{

}


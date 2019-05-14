#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
//#include <QUiLoader>
#include <QFile>
#include <Inventor/nodes/SoBaseColor.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoSphere.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Quarter/Quarter.h>
#include <Quarter/QuarterWidget.h>
#include <Quarter/eventhandlers/DragDropHandler.h>
#include "ui_QuarterViewer.h"

using namespace SIM::Coin3D::Quarter;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Quarter::init();
	QWidget * viewer = new QWidget;
	Ui::QuarterViewer ui;
	ui.setupUi(viewer);
	SoSeparator * root = new SoSeparator;
	root->ref();
	SoMaterial* m = new SoMaterial();
	m->diffuseColor.setValue(1, 0, 0);
	root->addChild(m);
	root->addChild(new SoSphere);
	//QuarterWidget * viewer = new QuarterWidget;
	ui.QuarterWidget->setSceneGraph(root);
	//viewer->setSceneGraph(root);
	viewer->show();
	return a.exec();
}

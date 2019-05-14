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
#include <ui_QuarterViewer.h>

using namespace SIM::Coin3D::Quarter;
int main(int argc, char *argv[])
{
	// start application
	QApplication a(argc, argv);
	Quarter::init();

	// widget = screen we see
	QWidget * viewer = new QWidget;
	// style?
	Ui::QuarterViewer ui;
	ui.setupUi(viewer);

	SoSeparator * root = new SoSeparator;
	root->ref();
	// new thing/material
	SoMaterial* m = new SoMaterial();
	m->diffuseColor.setValue(1, 0, 0); // make red
	root->addChild(m); // add to root
	root->addChild(new SoSphere); // add sphere to root

	ui.QuarterWidget->setSceneGraph(root); // format??

	viewer->show(); // show widget
	return a.exec();
}

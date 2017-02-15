#include "engine.h"
#include "window.h"

int main(int argc, char* argv[])
{
	// Read conf
	// ConfReader conf;
	ObjView::Engine engine;
	ObjView::Window window(640, 480, "ObjView");
	engine.setWindow(&window);
	
	engine.startMainLoop();
	
	window.close();
	
	return 0;
}
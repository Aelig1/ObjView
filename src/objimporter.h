#ifndef OBJIMPORTER_H
#define OBJIMPORTER_H

#include "iimporter.h"
#include <fstream>

namespace ObjView
{

class ObjImporter: public IImporter
{
public:
	std::shared_ptr<Mesh> import(const char* filepath);
	std::vector<const char*> getSupportedFileExtensions() const;
	
private:
	bool parseFile(std::ifstream& file, Mesh* mesh);
	void readLine(std::ifstream& file, std::string& out);
	void trimLine(std::string& line);
	std::vector<std::string> splitLine(const std::string& line);
	bool parseLine(const std::string& line, Mesh* mesh);
	
};

}

#endif // OBJIMPORTER_H
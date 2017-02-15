#ifndef OBJPARSER_H
#define OBJPARSER_H

#include "mesh.h"
#include <vector>
#include <memory>
#include <fstream>

namespace ObjView
{

class ObjParser
{
	enum ParseState {
		WaitForElement,
		WaitForValue,
		WaitForEndLine,
		ReadingElement,
	};
	
public:	
	std::shared_ptr<Mesh> loadObj(const char* path);
	
private:
	bool parseFile(std::ifstream& file, Mesh* mesh);
	void readLine(std::ifstream& file, std::string& out);
	void trimLine(std::string& line);
	std::vector<std::string> splitLine(const std::string& line);
	bool parseLine(const std::string& line, Mesh* mesh);

	ParseState m_state;
	
};

}

#endif // OBJPARSER_H
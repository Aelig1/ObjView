#ifndef IIMPORTER_H
#define IIMPORTER_H

#include "mesh.h"
#include <memory>
#include <vector>

namespace ObjView
{

class IImporter
{
public:
	virtual std::shared_ptr<Mesh> import(const char* filepath) = 0;
	virtual std::vector<const char*> getSupportedFileExtensions() const = 0;

};

}

#endif // IIMPORTER_H
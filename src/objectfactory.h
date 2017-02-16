#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "iimporter.h"
#include "object.h"
#include <memory>
#include <map>
#include <string>

namespace ObjView
{

class ObjectFactory
{
public:
	ObjectFactory();

	std::shared_ptr<Object> create();
	std::shared_ptr<Object> create(const char* mesh_file);
	
private:
	template <class T>
	void addImporter(T* importer);
	std::string getFileExtension(const std::string& filename) const;

	std::map<std::string, std::shared_ptr<IImporter>> m_importers;
	std::map<std::string, std::shared_ptr<Mesh>> m_mesh_pool;
	
};

}

#endif // OBJECTFACTORY_H
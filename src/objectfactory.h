#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "objparser.h"
#include "object.h"
#include <memory>
#include <map>

namespace ObjView
{

class ObjectFactory
{
public:
	std::shared_ptr<Object> create();
	std::shared_ptr<Object> create(const char* mesh_file);
	
private:
	ObjParser m_obj_parser;
	std::map<const char*, std::shared_ptr<Mesh>> m_mesh_pool;
	
};

}

#endif // OBJECTFACTORY_H
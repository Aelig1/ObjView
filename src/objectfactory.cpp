#include "objectfactory.h"

namespace ObjView
{

std::shared_ptr<Object> ObjectFactory::create()
{
	// Create object and return it
	return std::make_shared<Object>(Object());
}

std::shared_ptr<Object> ObjectFactory::create(const char* mesh_file)
{
	// Find mesh from mesh pool
	auto mesh_it = m_mesh_pool.find(mesh_file);
	if (mesh_it == m_mesh_pool.end())
	{
		// If mesh is not in pool, read obj file and add mesh to pool
		// TODO: Invalid obj files not added in pool
		auto ret = m_mesh_pool.insert(std::pair<const char*, std::shared_ptr<Mesh>>
									 (mesh_file, m_obj_parser.loadObj(mesh_file)));
		// Iterator to inserted mesh
		mesh_it = ret.first;
	}
	
	// Create object and return it
	return std::make_shared<Object>(Object(mesh_it->second));
}

}

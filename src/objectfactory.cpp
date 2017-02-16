#include "objectfactory.h"
#include "objimporter.h"
#include <vector>

namespace ObjView
{

ObjectFactory::ObjectFactory()
{
	addImporter(new ObjImporter());
}

// Returns Object without a mesh
std::shared_ptr<Object> ObjectFactory::create()
{
	// Create object and return it
	return std::make_shared<Object>();
}

// Returns an Object with a mesh read from the filepath specified by mesh_file.
// Returns nullptr if reading mesh_file was not successful.
std::shared_ptr<Object> ObjectFactory::create(const char* mesh_file)
{
	// Make file path lower case for mesh pool key
	std::string filename(mesh_file);
	for (size_t i = 0; i < filename.length(); ++i)
	{
		filename[i] = tolower(filename[i]);
	}

	// Search mesh from mesh pool
	auto mesh_it = m_mesh_pool.find(filename);
	// If mesh was found
	if (mesh_it != m_mesh_pool.end())
	{
		// Create object with the mesh
		return std::make_shared<Object>(mesh_it->second);
	}

	std::shared_ptr<Object> object = nullptr;

	std::string format = getFileExtension(filename);
	if (format == "")
	{
		fprintf(stderr, "Error: Unable to identify file format from mesh file name \"%s\".\n", mesh_file);
	}
	else
	{
		// Find the correct importer for the mesh file
		auto importer_it = m_importers.find(format);
		if (importer_it == m_importers.end())
		{
			fprintf(stderr, "Error: Mesh file format \"%s\" is not supported.\n", format.c_str());
		}
		else
		{
			// Import mesh
			std::shared_ptr<Mesh> mesh = importer_it->second->import(mesh_file);

			// If mesh was successfully imported
			if (mesh != nullptr)
			{
				// Add to mesh pool
				m_mesh_pool.insert(std::pair<std::string, std::shared_ptr<Mesh>>(filename, mesh));
				// Create an Object with the mesh
				object = std::make_shared<Object>(mesh);
			}
		}
	}
	
	return object;
}

// Adds an object derived from IImporter to the map of file extension and importer pairs.
template <class T>
void ObjectFactory::addImporter(T* importer)
{
	std::shared_ptr<IImporter> shared_importer = std::make_shared<T>(*importer);
	// Assign with filename extensions
	std::vector<const char*> extensions = shared_importer->getSupportedFileExtensions();
	for (auto it = extensions.begin(); it != extensions.end(); ++it)
	{
		m_importers[*it] = shared_importer;
	}
}

// Returns the file extension from a file name. The file name can include path directories.
// Returns an empty string if extension was not found.
std::string ObjectFactory::getFileExtension(const std::string& filename) const
{
	// Find the last dot
	size_t dot = filename.rfind('.');
	
	// Find the last directory separator
#ifdef _WIN32
	size_t slash = filename.find_last_of("/\\");
#else
	size_t slash = filename.rfind('/');
#endif

	// If a dot was found and it is after the last directory separator
	if (dot != std::string::npos && (slash == std::string::npos || slash < dot))
	{
		return filename.substr(dot + 1);
	}

	return "";
}

}

#include "objimporter.h"
#include <stdio.h>
#include <string>

namespace ObjView
{

std::shared_ptr<Mesh> ObjImporter::import(const char* filepath)
{
	std::ifstream obj_file(filepath);

	if (!obj_file.is_open())
	{
		fprintf(stderr, "Error: Unable to open file %s\n", filepath);
		return nullptr;
	}

	std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
	bool success = parseFile(obj_file, mesh.get());
	
	obj_file.close();

	if (!success)
	{
		fprintf(stderr, "Error: Failed to parse file \"%s\"\n", filepath);
		return nullptr;
	}
	
	return mesh;
}

std::vector<const char*> ObjImporter::getSupportedFileExtensions() const
{
	return std::vector<const char*>{ "obj" };
}

bool ObjImporter::parseFile(std::ifstream& file, Mesh* mesh)
{
	std::string line;

	while (!file.eof())
	{
		if (!file.good())
		{
			return false;
		}
		
		readLine(file, line);
		if (!parseLine(line, mesh))
		{
			return false;
		}
	}

	// TODO: Remove
	mesh->vertices = {
		{ -1.0f,-1.0f,-1.0f },
		{ -1.0f,-1.0f, 1.0f },
		{ -1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f,-1.0f },
		{ -1.0f,-1.0f,-1.0f },
		{ -1.0f, 1.0f,-1.0f },
		{ 1.0f,-1.0f, 1.0f },
		{ -1.0f,-1.0f,-1.0f },
		{ 1.0f,-1.0f,-1.0f },
		{ 1.0f, 1.0f,-1.0f },
		{ 1.0f,-1.0f,-1.0f },
		{ -1.0f,-1.0f,-1.0f },
		{ -1.0f,-1.0f,-1.0f },
		{ -1.0f, 1.0f, 1.0f },
		{ -1.0f, 1.0f,-1.0f },
		{ 1.0f,-1.0f, 1.0f },
		{ -1.0f,-1.0f, 1.0f },
		{ -1.0f,-1.0f,-1.0f },
		{ -1.0f, 1.0f, 1.0f },
		{ -1.0f,-1.0f, 1.0f },
		{ 1.0f,-1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f },
		{ 1.0f,-1.0f,-1.0f },
		{ 1.0f, 1.0f,-1.0f },
		{ 1.0f,-1.0f,-1.0f },
		{ 1.0f, 1.0f, 1.0f },
		{ 1.0f,-1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f,-1.0f },
		{ -1.0f, 1.0f,-1.0f },
		{ 1.0f, 1.0f, 1.0f },
		{ -1.0f, 1.0f,-1.0f },
		{ -1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f },
		{ -1.0f, 1.0f, 1.0f },
		{ 1.0f,-1.0f, 1.0f }
	};


	return true;
}

void ObjImporter::readLine(std::ifstream& file, std::string& out)
{
	out.clear();

	// In obj files backslash at the end of a line means the next line is treated as a part of the current line
	bool endline = false;
	while (!endline)
	{
		std::string line;
		std::getline(file, line);

		// Check if last character is backslash
		size_t last_char = line.find_last_not_of(" \t");

		if (last_char != std::string::npos && line[last_char] == '\\')
		{
			// Replace backslash with space
			line[last_char] = ' ';
		}
		else
		{
			endline = true;
		}

		out.append(line);
	}

	trimLine(out);
}

// Removes spaces and tabs from the start and end of parameter line and trims consecutive spaces and tabs.
void ObjImporter::trimLine(std::string& line)
{
	// Trim start and end
	std::size_t start = line.find_first_not_of(" \t");
	if (start == std::string::npos)
	{
		line.clear();
		return;
	}
	std::size_t end = line.find_last_not_of(" \t");
	line = line.substr(start, end - start + 1);

	// Trim consecutive spaces and tabs.
	start = line.find_first_of(" \t");

	while (start != std::string::npos)
	{
		end = line.find_first_not_of(" \t", start);

		line.erase(start, end - start);
		line.insert(start, " ");

		start = line.find_first_of(" \t", start + 1);
	}
}

// Returns a vector of substrings in the line using space as the separator.
std::vector<std::string> ObjImporter::splitLine(const std::string& line)
{
	std::vector<std::string> fields;

	size_t start = 0;
	size_t end = 0;
	while (end != std::string::npos)
	{
		end = line.find(' ', start);
		std::string field = line.substr(start, end - start);
		if (!field.empty())
		{
			fields.push_back(field);
		}
		start = end + 1;
	}

	return fields;
}

bool ObjImporter::parseLine(const std::string& line, Mesh* mesh)
{
	std::vector<std::string> fields = splitLine(line);

	if (fields.empty())
	{
		return true;
	}

	if (fields[0] == "v")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "vt")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "vn")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "vp")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "cstype")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "deg")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "bmat")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "step")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "p")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "l")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "f")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "curv")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "curv2")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "surf")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "parm")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "trim")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "hole")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "scrv")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "sp")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "end")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "con")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "g")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "s")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "mg")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "o")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "bevel")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "c_interp")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "d_interp")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "lod")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "usemtl")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "mtllib")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "shadow_obj")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "trace_obj")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "ctech")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else if (fields[0] == "stech")
	{
		printf("Warning: No implementation for keyword \"%s\".\n", fields[0].c_str());
	}
	else
	{
		// If not comment
		if (fields[0][0] != '#')
		{
			fprintf(stderr, "Error: Unknown keyword \"%s\"\n", fields[0].c_str());
			return false;
		}
	}

	return true;
}

}
#include "Mesh.h"



Mesh::Mesh(std::string file_name)
{
	std::ifstream mesh_file;
	
	mesh_file.open(file_name);

	
	readGMSH(mesh_file);

	mesh_file.close();
}


Mesh::~Mesh() {}


void Mesh::readGMSH(std::ifstream & mesh_file)
{
	std::string msh_line;
	std::string physical_names_start = "$PhysicalNames";
	std::string nodes_start = "$Nodes";
	std::string elements_start = "$Elements";

	std::regex end_regex("\\$End([A-Z]+[a-z]+)*");
	std::smatch base_match;

	if (mesh_file.is_open())
	{
		while (getline(mesh_file, msh_line))
		{
			if (msh_line.compare(physical_names_start) == 0)
				std::cout << "Physical names" << std::endl;

			if (msh_line.compare(nodes_start) == 0)
				readPoints(mesh_file);

			if (msh_line.compare(elements_start) == 0)
				std::cout << "Elements" << std::endl;

			if (std::regex_match(msh_line, base_match, end_regex))
				std::cout << "End" << std::endl;
		}
	}
}


void Mesh::readPoints(std::ifstream& mesh_file)
{
	std::string msh_line;
	std::regex end_regex("\\$End([A-Z]+[a-z]+)*");
	std::smatch base_match;

	int p_ind, nodes_num;
	double x, y, z;

	getline(mesh_file, msh_line);
	std::stringstream coord_stream(msh_line);
	coord_stream >> nodes_num;

	while (getline(mesh_file, msh_line))
	{
		if (std::regex_match(msh_line, base_match, end_regex))
			break;

		std::stringstream coord_stream(msh_line);
		coord_stream >> p_ind;
		coord_stream >> x;
		coord_stream >> y;
		coord_stream >> z;

		nodes.push_back(Point(x, y, z));
	}

	std::cout << "Nodes control sum: " << nodes.size() - nodes_num << std::endl;
}
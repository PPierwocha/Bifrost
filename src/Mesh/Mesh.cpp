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
				readElements(mesh_file);

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

void Mesh::readElements(std::ifstream& mesh_file)
{
	std::string msh_line;
	std::regex end_regex("\\$End([A-Z]+[a-z]+)*");
	std::smatch base_match;

	int elements_num, tmp_num;
	int points_ctr = 0;
	std::vector<int> element_def;

	getline(mesh_file, msh_line);
	std::stringstream element_stream(msh_line);
	element_stream >> elements_num;

	while (getline(mesh_file, msh_line))
	{
		if (std::regex_match(msh_line, base_match, end_regex))
			break;

		std::stringstream element_stream(msh_line);
		while (element_stream)
		{
			element_stream >> tmp_num;
			element_def.push_back(tmp_num);
		}

		if (element_def[1] == 1) // line
			elements.push_back(Line(element_def));
		else if (element_def[1] == 2) // triangle
			elements.push_back(Triangle(element_def));
		else if (element_def[1] == 3) // quad
		{
		}
		else if (element_def[1] == 4) // tetrahedron
		{
		}
		else if (element_def[1] == 5) // hexahedron
		{
		}
		else if (element_def[1] == 15) // point
		{
			points_ctr++;
		}
		else
			std::cout << "Mesh contains elements not available in Bifrost !" << std::endl;
		

		element_def.clear();
	}

	std::cout << "Elements control sum: " << elements.size() + points_ctr - elements_num << std::endl;
}
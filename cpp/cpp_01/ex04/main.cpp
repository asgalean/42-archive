#include <string>
#include <iostream>
#include <fstream>


int main(int argc, char *argv[])
{
	if (argc != 4)
		return(std::cout << "Input 'filename' 'string_to_replace' 'new_string', please, and nothing else, please" << std::endl ,0);

	std::string filename = argv[1];
	filename+=".replace";
	char *outname = &filename[0]; //.data() returns a "const char*"
	
	std::fstream infile(argv[1], std::ios::in);
	std::fstream outfile(outname, std::ios::out | std::ios::trunc);

	std::string str;
	std::string a = argv[2];
	std::string b = argv[3];
	
	if (a == "")
	{
		a = "a";
		b = "a";
	}
	while (std::getline(infile, str))
	{
		long unsigned int i = str.find(a);
		while (i != std::string::npos)
		{
			str.erase(i, a.size());
			str.insert(i, b);
			
			i = str.find(a, i+1);
		}
		outfile << str << std::endl;
	}
	
	infile.close();
	outfile.close();
}

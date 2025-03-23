#include <fstream>
#include <string>

struct item {
	int id;
	std::string desc;
	std::string status;
	std::string createdAt;
	std::string updatedAt;
};


int main (int argc, char *argv[]) {
	
	std::fstream fs;
	fs.open("data.json", std::fstream::in | std::fstream::out | std::fstream::app);
	
	fs << " more lorem ipsum" << std::endl;

	fs.close();



	return 0;
}

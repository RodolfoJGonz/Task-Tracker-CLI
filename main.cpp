#include <fstream>
#include <iostream>
#include <string>

struct item {
	
public:
	// Constructor
	item(int id, std::string description, std::string stat, std::string created, std::string updated) : id{id}, desc {description}, status{stat}, createdAt{created}, updatedAt{updated}{}


	//Getters; we might need some setters
	int getID(){return id;};
	std::string getDescription(){return desc;};
	std::string getStatus(){return status;};
	std::string getCreation(){return createdAt;};
	std::string getUpdate(){return updatedAt;};
	
	//Setters

private:
	int id;
	std::string desc;
	std::string status;
	std::string createdAt;
	std::string updatedAt;
	
};
std::string objectToJSON(item x); 

int main (int argc, char *argv[]) {

	item temp = item(1, "A thing", "todo", "yesterday", "today");

	std::fstream fs;
	fs.open("data.json", std::fstream::in | std::fstream::out | std::fstream::app);
	
	if(!fs.is_open()){
		std::cout << "Error opening file" << std::endl;
		return -1;

	}
	fs.seekg(0);
  std::cout << "File Contents:\n"
            << fs.rdbuf() << "\n\n";
	std::string xd;
	
	fs << "[" << std::endl;
	fs << objectToJSON(temp);

	fs << "\n]" << std::endl;
	fs.close();


	return 0;
}


std::string objectToJSON(item x){
	std::string res = "{\n";

	res += ("\"id\":" + std::to_string(x.getID()) + ",\n"); 
	res += ("\"desc\":\"" + x.getDescription() + "\",\n");
	res += ("\"status\":\"" + x.getStatus() + "\",\n");
	res += ("\"createdAt\":\"" + x.getCreation() + "\",\n");
	res += ("\"updatedAt\":\"" + x.getUpdate() + "\"\n");
	
	res += "},";
	return res;
}

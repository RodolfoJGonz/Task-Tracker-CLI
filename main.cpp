#include <fstream>
#include <iostream>
#include <string>

//TODO: Figure out storage system, some sort of database like sqlite
//TODO: Setup setters for updating task info
//TODO: figure out ID checking to make sure no ID repeats (Could be fixed with sqlite Autoincrement)
//TODO: Make CLI menu for users to pick what to do.


// Item Struct
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


// Function Declarations
std::string objectToJSON(item x); 



// MAIN
int main (int argc, char *argv[]) {
	
	//Making a test item
	item temp = item(1, "A thing", "todo", "yesterday", "today");

	std::fstream fs;
	fs.open("data.json", std::fstream::in | std::fstream::out | std::fstream::app);
	
	if(!fs.is_open()){
		std::cout << "Error opening file" << std::endl;
		return -1;
	}

	//Inserting item into json file
	fs << "[" << std::endl;
	fs << objectToJSON(temp);
	fs << "\n]" << std::endl;
	
	//Printing contents of json file
	fs.seekg(0);
	std::cout << "File Contents:\n"
            << fs.rdbuf() << "\n\n";
	std::string xd;

	fs.close();


	return 0;
}


// Function Implementations
std::string objectToJSON(item x){
	std::string res = "\t{\n";

	res += ("\t\"id\":" + std::to_string(x.getID()) + ",\n"); 
	res += ("\t\"desc\":\"" + x.getDescription() + "\",\n");
	res += ("\t\"status\":\"" + x.getStatus() + "\",\n");
	res += ("\t\"createdAt\":\"" + x.getCreation() + "\",\n");
	res += ("\t\"updatedAt\":\"" + x.getUpdate() + "\"\n");
	
	res += "\t},";
	return res;
}

#include <iostream>
#include <string>
#include <filesystem>
#include <regex>

using namespace std;
namespace fs = std::filesystem;

void file_search(fs::path dir,string type);

int main(){
	
	string file_type, s_parent_dir;

	cout << "Recursive file type search!" << endl << "Please enter path to start directory: ";
	cin >> s_parent_dir;
	cout << "Please enter file extension (ex: .txt): ";
	cin >> file_type;
	cout << endl;

	fs::path parent_dir(s_parent_dir);

	file_search(parent_dir,file_type);

	cout << endl;
	system("pause");
	return 0;
}

//functions---------------------------------------------------------------------------

void file_search(fs::path dir, string type) {

	for (auto& element : fs::directory_iterator(dir)) {
		
		fs::path element_path = element.path();

		if (element_path.extension() == type) cout << element_path.string()<<endl;
	}

	for (auto& element : fs::directory_iterator(dir)) {

		fs::path element_path = element.path();

		if (fs::is_directory(element_path)) file_search(element_path, type);
	}
}

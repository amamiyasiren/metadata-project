#include <iostream>
#include <filesystem>
#include <taglib/fileref.h>
#include <taglib/tag.h>

using namespace std;
namespace fs = filesystem;

void change_data(const fs::path& file_path, const int& choice, const string& new_content) {
	TagLib::FileRef file(file_path.c_str());

	static int counter = 1; // for numbered titles

		
	switch (choice) {
		case 1:
			file.tag()->setArtist(new_content.c_str());
			file.save();
			
			break;	
		case 2: {
			string numbered_title = "#" + to_string(counter) + " " + new_content;
			counter++;
			file.tag()->setTitle(numbered_title.c_str());
			file.save();
			break;		
		}
		case 3:
			file.tag()->setAlbum(new_content.c_str());
			file.save();
			break;

		case 4:
			file.tag()->setGenre(new_content.c_str());
			file.save();
			break;
		case 5:
			file.tag()->setComment(new_content.c_str());
			file.save();
			break;
		case 6:
			cout << "Exiting program..." << endl;
			exit(0);
			break;




	}

}

void loop_folder(const fs::path& folder_path, int &choice, string& new_content) {
	for (const auto& file : fs::directory_iterator(folder_path)) {
		if (file.is_regular_file() && file.path().extension() == ".mp3"){
			change_data(file.path(),choice,new_content);

		}


	}

}

int menu() {

	int choice;
	cout << "Choose the field you want to change:" << endl;
	cout << "\t1. Change artist" << endl;
	cout << "\t2. Change title" << endl;
	cout << "\t3. Change album" << endl;
	cout << "\t4. Change genre" << endl;
	cout << "\t5. Change comment" << endl;
	cout << "\t6. Exit" << endl;
	cout << "Enter your choice: ";

	
	do {
		cin >> choice;
		if (cin.fail() || choice < 1 || choice > 6) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please select a valid option: ";
		}
	} while (cin.fail() || choice < 1 || choice > 6);

	return choice;
	
}

string content(int& choice){
	string new_content;

	switch (choice) {
		case 1:
			cout << "What do you want to change the artist to? ";
			break;
		case 2:
			cout << "What do you want to change the title to? ";
			break;
		case 3:
			cout << "What do you want to change the album to? ";
			break;
		case 4:
			cout << "What do you want to change the genre to? ";
			break;
		case 5:
			cout << "What do you want to change the comment to? ";
			break;
	}
	cin.ignore();
	getline(cin, new_content);
	return new_content;

}

int main() {
	string folder_path; 

	do { //make sure input is a valid folder path
		cout << "Enter folder path of the files you want to change: ";
		getline(cin, folder_path);
		if (!fs::exists(folder_path) || !fs::is_directory(folder_path)) {
			cout << "Invalid folder path. Please try again." << endl;
		}
	} while (!fs::exists(folder_path) || !fs::is_directory(folder_path));
	
	int choice = menu(); //choice of the user

	string new_content = content(choice); //use choice to determine new content

	fs::path path(folder_path); //variable called path to store the folder path
	loop_folder(path, choice, new_content); //send everything to loop_folder and change_data

}
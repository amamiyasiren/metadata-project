#include <iostream>
#include <filesystem>
#include <taglib/fileref.h>
#include <taglib/tag.h>

using namespace std;
namespace fs = filesystem;

void change_data(const fs::path& file_path) {
	TagLib::FileRef file(file_path.c_str());
	if (!file.isNull() && file.tag()) {

		TagLib::Tag* tag = file.tag();

		tag->setArtist("Shingeki no Kyojin");
		file.save();
		cout << "Updated artist" << endl;

	}
	else {
		cout << "Failed to open or process file." << endl;


	}




}

void loop_folder(const fs::path& folder_path) {
	for (const auto& file : fs::directory_iterator(folder_path)) {
		if (file.is_regular_file() && file.path().extension() == ".mp3"){
			change_data(file.path());

		}


	}

}

void main() {
	string folder_path;
	cout << "Enter folder path of the files you want to change: ";
	getline(cin, folder_path);

	fs::path path(folder_path);
	loop_folder(path);






}
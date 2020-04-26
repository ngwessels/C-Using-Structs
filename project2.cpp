#include <iomanip>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

//Media Struct. Will store specific information about each media
struct Media {
	int id, year;
	char category[256], title[256], description[256];
};

char printMenu() { //Prints Menu for list of commands
	cout << "*** Welcome to your media library! ***" << endl;
	cout << "    Here are all commands:" << endl;
	cout << "    a - Add media to your library" << endl;
	cout << "    c - Print all media of a specific category from your library" << endl;
	cout << "    d - Delete media from your library" << endl;
	cout << "    p - Print all media that you have in your library" << endl;
	cout << "    q - Quit Program" << endl;
	cout << "Enter Command: ";
	char command;
	cin >> command;
	return command; //Returns the command
}


void printAllCategories() { //Prints all categories
        cout << "*** All your Categories ***" << endl;
        cout << "    video" << endl;
        cout << "    audio" << endl;
        cout << "    printed" << endl;
}

void addMedia(Media mediaLibrary[], int &instance) { //Adds a media to the mediaLibrary
	char title[256], category[256], description[256];
	cout << "Title: ";
	cin.clear(); //Clears cin
	cin.ignore(100, '\n'); 
	cin.getline(title, 256, '\n');
	printAllCategories();
	cout << "Category: ";
	cin.getline(category, '\n');
	if(strcmp(category, "video") == 0 || strcmp(category, "audio") == 0 || strcmp(category, "printed") == 0) { //Compare strings and cStrings
		cout << "Movie Description: ";
		cin.getline(mediaLibrary[instance].description, 256, '\n');
		cout << "Year: ";
        	cin >> mediaLibrary[instance].year;
        	mediaLibrary[instance].id = instance;
		strcpy(mediaLibrary[instance].title, title);
		strcpy(mediaLibrary[instance].category, category);
        	instance++;
	} else {
		cout << "This Category does not exist. Try again!" << endl;	
	}
}


void printAllMedia(Media mediaLibrary[], int instance) { //Print all media
	for(int i = 0; i <= instance; i++) {
		cout << "Category: " << mediaLibrary[i].category << endl;
		if(strcmp(mediaLibrary[i].category, "video") == 0 || strcmp(mediaLibrary[i].category, "audio") == 0 || strcmp(mediaLibrary[i].category, "printed") == 0) { //Compare cStrings and strings
			cout << "*** Media = " << i + 1 << endl;
			cout << "    Title: " << mediaLibrary[i].title << endl;
			cout << "    Description: " << mediaLibrary[i].description << endl;
			cout << "    Category: " << mediaLibrary[i].category << endl;
			cout << "    Year: " << mediaLibrary[i].year << endl;
			cout << "    Id: " << mediaLibrary[i].id << endl;
			cout << endl;
		}
	}
}


void printCategory(Media mediaLibrary[], int instance) { //Will print all media for a specific category
	printAllCategories();
	string categoryChosen;
	cout << "Select Category: ";
	cin.clear();
	cin.ignore(100, '\n');
	getline(cin, categoryChosen);
	cout << "All Your media with category " << categoryChosen << endl;
	for(int i = 0; i <= instance; i++) {
		if(mediaLibrary[i].category == categoryChosen && (categoryChosen == "video" || categoryChosen == "audio" || categoryChosen == "printed")) {
			cout << "*** Media = " << i + 1 << endl;
                        cout << "    Title: " << mediaLibrary[i].title << endl;
			cout << "    Description: " << mediaLibrary[i].description << endl;
                        cout << "    Category: " << mediaLibrary[i].category << endl;
                        cout << "    Year: " << mediaLibrary[i].year << endl;
                        cout << "    Id: " << mediaLibrary[i].id << endl;
			cout << endl;
		}
	}
}

void deleteMedia(Media mediaLibrary[], int &instance) {
	printAllMedia(mediaLibrary, instance);
	cout << "Select a media to delete. Find the medias id number and type below" << endl;
	cout << "Media Id: ";
	int id;
	cin >> id;
	for(int i = id; i < instance; i++) {
		mediaLibrary[i] = mediaLibrary[i + 1];
		mediaLibrary[i].id = i;
	}
	instance--;
}

int main() {
	bool isRunning = true; //If the do while loop should be running
	Media mediaLibrary[100] = {};
	int arrayInstance = 0;
	do {
		char command;
		command = printMenu();
		switch(command) {
			case 'a':
				addMedia(mediaLibrary, arrayInstance);
				break;
			case 'c':
				printCategory(mediaLibrary, arrayInstance);
				break;
			case 'd':
				deleteMedia(mediaLibrary, arrayInstance);
				break;
			case 'p':
				printAllMedia(mediaLibrary, arrayInstance);
				break;
			case 'q':
				isRunning = false;
				cout << "Have a nice day!" << endl;
				break;
		}	
	}while(isRunning);
}

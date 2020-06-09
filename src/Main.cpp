#include <iostream>
#include "Timer.h"
#include "IndexLinkedList.h"
#include "MainFunctions.h" // this already has IndexLinkedList.h included

/* This is the real deal */
int main() {
	IndexLinkedList index;
	std::string idxCreationTime;
	Timer timer;

	std::cout << "Initializing Index Please Wait.." << std::endl;

	//	Start timer to measure duriation of index creation
	timer.Start();

	//	DIR_NUMBER = 9598
	MainFunctions::CreateIndex(index, 9598);
//	MainFunctions::CreateIndex(index, 6);

	//	stop the timer
	timer.Stop();

	//	convert time into std::string and store in idxCreationTime
	timer.GetElapsed();
	int min = timer.GetMinutes();
	double sec = timer.GetSeconds();

	idxCreationTime = std::to_string(min) + '.' + std::to_string(sec);

	int option;
	std::string word;
	std::vector<std::string> listOfFilesNames;
	std::vector<std::pair<std::string, int>> tops;
	std::vector<std::pair<std::string, int>> leasts;


	while (true) {
		MainFunctions::PrintMenu(idxCreationTime);
		MainFunctions::GetValidOption(option);

		switch (option) {
			case 1:
				word = MainFunctions::GetAWord();
				listOfFilesNames = index.GetListOfFiles(word);
				MainFunctions::PrintFiles(listOfFilesNames, word);
				getchar();
				std::cout << "press \'enter\' to continue";
				getchar();
				break;
			case 2:
				tops = index.GetMostFrequentWords(10);
				MainFunctions::PrintTops(tops, 10);
				std::cout << "press \'enter\' to continue";
				getchar();
				getchar();
				break;
			case 3:
				leasts = index.GetLeastFrequentWords(10);
				MainFunctions::PrintLeast(leasts, 10);
				std::cout << "press \'enter\' to continue";
				getchar();
				getchar();
				break;
			default:
				getchar();
				break;
		}
		if (option == 4) break;
	}
	std::cout << "press \'enter\' for exit";
	getchar();

	return 0;
}

//int main() {
//	using std::cout;
//	using std::endl;
//	// Create timer
//	Timer t;
//
//	cout << "press any key to start the timer";
//	getchar();
//	t.Start();
//	// Start the timer
//
//	getchar();
//
//	// Stop the timer
//	t.Stop();
//
//	// Get time elapsed
//	t.GetElapsed();
//
//	std::cout << "It took me " << t.GetElapsed() << " seconds." << endl;
//	std::cout << "It took me " << t.GetMinutes() << " minutes and " << t.GetSeconds() << " seconds" << endl;
//	std::cout << std::endl;
//
//	return 0;
//}
#include <iostream>
#include "Timer.h"
#include "IndexLinkedList.h"
#include "MainFunctions.h" // this already has IndexLinkedList.h included

///* This is the real deal */
//int main() {
//	IndexLinkedList index;
//	std::string idxCreationTime;
//	Timer timer;
//
//	/*Start timer to measure duriation of index creation*/
//	timer.Start();
//	MainFunctions::CreateIndex(index, 9598);
//	//MainFunctions::CreateIndex(index, 5);
//	timer.Stop();
//	/*stop the timer*/
//
//	/*convert time into std::string and store in idxCreationTime*/
//
//	int min = timer.GetMinutes();
//	int sec = timer.GetSeconds();
//
//	idxCreationTime = std::to_string(min) + '.' + std::to_string(sec);
//
//	//std::cout << "and the winner timeee iiis:.." << std::endl;
//	//std::cout << timer.GetElapsedAsSeconds() << std::endl;
//	//std::cout << idxCreationTime << std::endl << std::endl;
//
//	int option;
//	std::string word;
//	std::vector<std::string> listOfFilesNames;
//	std::vector<std::pair<std::string, int>> tops;
//	std::vector<std::pair<std::string, int>> leasts;
//
//
//	while (true) {
//		system("CLS");
//		MainFunctions::PrintMenu(idxCreationTime);
//		MainFunctions::GetValidOption(option);
//
//		switch (option) {
//			case 1:
//				system("CLS");
//				word = MainFunctions::GetAWord();
//				listOfFilesNames = index.GetListOfFiles(word);
//				MainFunctions::PrintFiles(listOfFilesNames, word);
//				getchar();
//				std::cout << "press \'enter\' to continue";
//				getchar();
//				break;
//			case 2:
//				system("CLS");
//				tops = index.GetMostFrequentWords(10);
//				MainFunctions::PrintTops(tops, 10);
//				getchar();
//				std::cout << "press \'enter\' to continue";
//				getchar();
//				break;
//			case 3:
//				system("CLS");
//				leasts = index.GetLeastFrequentWords(10);
//				MainFunctions::PrintLeast(leasts, 10);
//				getchar();
//				std::cout << "press \'enter\' to continue";
//				getchar();
//				break;
//			default:
//				getchar();
//				break;
//		}
//		if (option == 4) break;
//	}
//	std::cout << "press \'enter\' for exit";
//	getchar();
//
//
////std::cout << "Hello" << std::flush; //flush forces the printing to the screen before it clears
//
//
////index.PrintListWithSpecificLetter("a"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("b"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("c"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("d"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("e"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("f"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("g"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("h"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("i"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("j"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("k"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("l"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("m"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("n"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("o"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("p"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("q"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("r"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("s"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("t"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("u"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("v"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("w"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("x"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("y"); std::cout << std::endl;
////index.PrintListWithSpecificLetter("z"); std::cout << std::endl;
//	return 0;
//}

//int main() {
//	using std::cout;
//	using std::endl;
//	using namespace std::chrono;
//	// Create timer
//
//	cout << "press any key to start the timer";
//	getchar();
//	high_resolution_clock::time_point t1 = high_resolution_clock::now();
//	// Start the timer
//
//	getchar();
//
//	// Stop the timer
//	high_resolution_clock::time_point t2 = high_resolution_clock::now();
//
//
//	// Get time elapsed
//	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
//
//	std::cout << "It took me " << time_span.count() << " seconds.";
//	std::cout << std::endl;
//
//	return 0;
//}

int main() {
	using std::cout;
	using std::endl;
	// Create timer
	Timer t;

	cout << "press any key to start the timer";
	getchar();
	t.Start();
	// Start the timer

	getchar();

	// Stop the timer
	t.Stop();

	// Get time elapsed
	t.GetElapsed();

	std::cout << "It took me " << t.GetElapsed() << " seconds." << endl;
	std::cout << "It took me " << t.GetMinutes() << " minutes and " << t.GetSeconds() << " seconds" << endl;
	std::cout << std::endl;

	return 0;
}
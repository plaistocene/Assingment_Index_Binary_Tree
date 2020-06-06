#include <iostream>
#include "CHRTimer.h"
#include "IndexLinkedList.h"
#include "MainFunctions.h" // this already has IndexLinkedList.h included

//#include <fstream>
//#include <algorithm>
//#include <functional>
//#include <sstream>

///* This is a vector test main */
//#include <vector>
//int main() {
//	std::vector<int> abc;
//	abc.push_back(15);
//	abc.push_back(25);
//	abc.push_back(35);
//	abc.push_back(45);
//	abc.push_back(55);
//
//	for(auto &i : abc) {
//		std::cout << i << ' ';
//	}
//	std::cout << std::endl;
//
//	std::vector<int>::iterator it;
//	it = abc.begin() + 0;
//	abc.insert(it, 2000);
//	//myvector.insert ( it , 200 );
//
//	for(auto &i : abc) {
//		std::cout << i << ' ';
//	}
//	std::cout << std::endl;
//	return 0;
//}


/* This is the real deal */
int main() {
	IndexLinkedList index;
	std::string idxCreationTime;
	CHRTimer timer;

	/*Start timer to measure duriation of index creation*/
	timer.Start();
	MainFunctions::CreateIndex(index, 9598);
	//MainFunctions::CreateIndex(index, 5);
	timer.Stop();
	/*stop the timer*/

	/*convert time into std::string and store in idxCreationTime*/

	int min = (int)timer.GetElapsedAsSeconds() / 60;
	int sec = (int)timer.GetElapsedAsSeconds() % 60;

	idxCreationTime = std::to_string(min) + '.' + std::to_string(sec);

	//std::cout << "and the winner timeee iiis:.." << std::endl;
	//std::cout << timer.GetElapsedAsSeconds() << std::endl;
	//std::cout << idxCreationTime << std::endl << std::endl;

	int option;
	std::string word;
	std::vector<std::string> listOfFilesNames;
	std::vector<std::pair<std::string, int>> tops;
	std::vector<std::pair<std::string, int>> leasts;


	while(true) {
		system("CLS");
		MainFunctions::PrintMenu(idxCreationTime);
		MainFunctions::GetValidOption(option);

		switch(option) {
		case 1:
			system("CLS"); 
			word = MainFunctions::GetAWord();
			listOfFilesNames = index.GetListOfFiles(word);
			MainFunctions::PrintFiles(listOfFilesNames, word);
			getchar();
			std::cout << "press \'enter\' to continue";
			getchar();
			break;
		case 2:
			system("CLS");
			tops = index.GetMostFrequentWords(10);
			MainFunctions::PrintTops(tops, 10);
			getchar();
			std::cout << "press \'enter\' to continue";
			getchar();
			break;
		case 3:
			system("CLS");
			leasts = index.GetLeastFrequentWords(10);
			MainFunctions::PrintLeast(leasts, 10);
			getchar();
			std::cout << "press \'enter\' to continue";
			getchar();
			break;
		default:
			getchar();
			break;
		}
		if(option == 4) break;
	}
	std::cout << "press \'enter\' for exit";
	getchar();


//std::cout << "Hello" << std::flush; //flush forces the printing to the screen before it clears


//index.PrintListWithSpecificLetter("a"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("b"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("c"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("d"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("e"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("f"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("g"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("h"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("i"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("j"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("k"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("l"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("m"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("n"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("o"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("p"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("q"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("r"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("s"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("t"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("u"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("v"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("w"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("x"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("y"); std::cout << std::endl;
//index.PrintListWithSpecificLetter("z"); std::cout << std::endl;
	return 0;
}






//// Not so Driver funtion
//int main() {
//	std::string dirName = "AllDocs";
//	IndexLinkedList index;
//	std::string idxCreationTime;
//	CHRTimer timer;
//
//	/*Start timer to measure duriation of index creation*/
//	timer.Start();
//	MainFunctions::CreateIndex(index, dirName);
//	timer.Stop();
//	/*stop the timer*/
//
//	/*convert time into std::string and store in idxCreationTime*/
//
//	int min = (int)timer.GetElapsedAsSeconds() / 60;
//	int sec = (int)timer.GetElapsedAsSeconds() % 60;
//
//	idxCreationTime = std::to_string(min) + '.' + std::to_string(sec);
//
//	int opt;
//	do {
//		opt = PrintDecoratedMenu(idxCreationTime);
//		switch(opt) {
//		case 1:
//		{
//			std::string queryWord;
//			//prompt user to enter single query word 
//			index.GetListOfFiles(queryWord);
//			break;
//		}
//		case 2: index.GetMostFrequentWords(10); break;
//		case 3: index.GetLeastFrequentWords(10); break;
//		}
//	} while(opt != 4);
//	
//	return 0;
//}







//int main() {
//	using std::cout;
//	using std::endl;
//	// Create timer
//	CHRTimer timer;
//	cout << "press any key to start the timer";
//	getchar();
//	// Start the timer
//	timer.Start();
//
//	getchar();
//
//	// Stop the timer
//	timer.Stop();
//
//	// Get time elapsed
//	cout << timer.GetElapsed() << endl;
//	cout << timer.GetElapsedAsSeconds() << endl;
//
//	int min = (int)timer.GetElapsedAsSeconds() / 60;
//	int sec = (int)timer.GetElapsedAsSeconds() % 60;
//
//	cout << min << '.' << sec;
//}
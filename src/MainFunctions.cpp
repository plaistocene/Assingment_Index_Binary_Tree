#include <fstream>
#include <algorithm>
#include <functional>
#include <sstream>
#include <iomanip>

#include "MainFunctions.h"

// This is Where we are Getting Word from a File at the same time Removing any Puntuation
bool MainFunctions::CreateIndex(IndexLinkedList &index, const int DIR_NUMBER) { //, const std::string dirName
	//TODO create a FileNameNode for WordTypeNode
	for (int i = 1; i <= DIR_NUMBER; i++) {
		std::string dirName;
		dirName = std::to_string(i) + ".txt";

		// filestream variable file 
		std::fstream file;
		std::string word, result;

		int dummy = 0;

		// opening file 
		file.open(dirName.c_str());

		if (file) {
			// extracting words from the file 
			while (file >> word) {
				std::replace_if(word.begin(), word.end(), ispunct, ' ');    //	with sstream divide into two strings
				std::stringstream ss(word);
				while (ss >> result)
					if (!(std::stringstream(result) >> dummy)) {
						std::transform(result.begin(), result.end(), result.begin(), ::tolower);
						index.AddWord(result, dirName);
						break;
					}
			}

			file.close();
		} else { std::cout << "file not opened" << std::endl; }
	}
	return false;
}

void MainFunctions::PrintMenu(std::string &idxCreationTime) {
	// 123456789 123456789 123456789 123456789 132456789 123456789 123456789 123456789 123456789 //
	std::cout <<
			  (char) 201 <<
			  //"=============================================="
			  "══════════════════════════════════════════════" << (char) 187 << std::endl <<
			  "║       Simple Document Retrieval System       ║" << std::endl <<
			  "║       Time as min:sec:.." << idxCreationTime << "           ║" << std::endl <<
			  //"║==============================================║"
			  "╠══════════════════════════════════════════════╣" << std::endl <<
			  "║   1. Enter a word to list documents          ║" << std::endl <<
			  "║   2. Print  most frequent 10 words           ║" << std::endl <<
			  "║   3. Print least frequent 10 words           ║" << std::endl <<
			  "║   4. Exit                                    ║" << std::endl
			  << (char) 200 <<
			  //"=============================================="
			  "══════════════════════════════════════════════" << (char) 188 << std::endl <<
			  "║   Enter Your Choice:.. "; /*<<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl <<
"                        m                       " << std::endl;*/
}

int MainFunctions::GetValidOption(int &option) {
	while (true) {
		std::cin >> option;
		if (option < 0) {
			std::cout <<
					  //"|===========================================================================================|"
					  "╠═══════════════════════════════════════════════════════════════════════════════════════════╣"
					  << std::endl <<
					  "    You entered a value that is too low  which even not exists, please try a higher value..  "
					  << std::endl <<
					  //"|===========================================================================================|"
					  "╠═══════════════════════════════════════════════════════════════════════════════════════════╣"
					  << std::endl;
		}
		if (4 < option) {
			std::cout <<
					  //"|============================================================================================|"
					  "╠═══════════════════════════════════════════════════════════════════════════════════════════╣"
					  << std::endl <<
					  "    You entered a value that is too high which even not exists, please try a higher value..  "
					  << std::endl <<
					  //"|============================================================================================|"
					  "╠═══════════════════════════════════════════════════════════════════════════════════════════╣"
					  << std::endl;
		}
		if (0 < option && option < 5) {
			std::cout <<
					  //"|==============================================|"
					  "╠══════════════════════════════════════════════╣" << std::endl;
			return option;
		}
	}
}

std::string MainFunctions::GetAWord() {
	std::cout <<
			  //"|==============================================|"
			  "╠══════════════════════════════════════════════╣" << std::endl <<
			  "|   Enter Your KeyWord:.. ";
	std::string word;
	std::cin >> word;
	std::cout <<
			  //"|==============================================|"
			  "╠══════════════════════════════════════════════╣";
	return word;
}

void MainFunctions::PrintFiles(const std::vector<std::string> &listOfFilesNames, const std::string &singleWordQuery) {
	//TODO: do a loop get the goods
	std::cout << "The Files That Include" << ' ' << '\"' << singleWordQuery << '\"' << ' ' << "are:.." << std::endl;
	for (auto &j : listOfFilesNames)
		std::cout << std::setw(6) << std::left << j << ' ' << ':' << ' ';
	std::cout << std::endl;
}

void MainFunctions::PrintTops(const std::vector<std::pair<std::string, int>> &tops, const int topWhat) {
	//TODO: do a loop get the goods
	std::cout << "Top" << ' ' << topWhat << ' ' << "Words are:.." << "(this is 10 at main.cpp)" << std::endl;
	std::cout << std::setw(15) << std::left << "Words" << ':' << std::setw(5) << std::left << "Frequency" << std::endl;
	for (auto &j : tops)
		std::cout << std::setw(15) << std::left << j.first << ':' << std::setw(5) << std::left << j.second << std::endl;
	std::cout << std::endl;
}

void MainFunctions::PrintLeast(const std::vector<std::pair<std::string, int>> &leasts, const int leastWhat) {
	//TODO: do a loop get the goods
	std::cout << "Least" << ' ' << leastWhat << ' ' << "Words are:.." << "(this is 10 at main.cpp)" << std::endl;
	std::cout << std::setw(15) << std::left << "Words" << ':' << std::setw(5) << std::left << "Frequency" << std::endl;
	for (auto &j : leasts)
		std::cout << std::setw(15) << std::left << j.first << ':' << std::setw(5) << std::left << j.second << std::endl;
	std::cout << std::endl;
}



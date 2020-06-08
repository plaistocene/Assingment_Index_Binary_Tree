#pragma once

#include "IndexLinkedList.h"

class MainFunctions {
public:
	// This is Where we are Getting Word from a File at the same time Removing any Puntuation
	static bool CreateIndex(IndexLinkedList &index, const int DIR_NUMBER);    //	, const std::string dirName

	static void PrintMenu(std::string &idxCreationTime);

	static int GetValidOption(int &option);

	static std::string GetAWord();

	static void PrintFiles(const std::vector<std::string> &listOfFilesNames, const std::string &singleWordQuery);

	static void PrintTops(const std::vector<std::pair<std::string, int>> &tops, const int topWhat);

	static void PrintLeast(const std::vector<std::pair<std::string, int>> &leasts, const int leastWhat);
};


#pragma once
#include <string>

class FileNameNode {
public:
	std::string fileName;
	FileNameNode *next;

	FileNameNode(const std::string _dirName) : fileName(_dirName), next(nullptr) {}
};
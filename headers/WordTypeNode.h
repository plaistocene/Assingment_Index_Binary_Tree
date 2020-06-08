#pragma once

#include "FileNameNode.h"    //	includes string

class WordTypeNode {
private:
	std::pair<std::string, int> word_freq;

public:
	void SetWord(std::string _word) {
		word_freq.first = _word;
	}

	void UpdateFreq() {
		word_freq.second += 1;
	}

	std::string GetWord() {
		return word_freq.first;
	}

	int GetFreq() {
		return word_freq.second;
	}

public:
	FileNameNode *fileListHead;
	WordTypeNode *right;
	WordTypeNode *left;

	WordTypeNode(std::string _word, std::string _fileName) : word_freq(_word, 1), right(nullptr), left(nullptr) {
		fileListHead = new FileNameNode(_fileName);
	}

	void AddFileNameNode(std::string _dirName) {
		if (!fileListHead) {
			fileListHead = new FileNameNode(_dirName);
			return;
		} else {
			FileNameNode *walk = fileListHead;
			FileNameNode *prev = walk;
			while (walk) {
				if (walk->fileName == _dirName) {
					return;
				}
				prev = walk;
				walk = walk->next;
			}
			auto *t = new FileNameNode(_dirName);
			prev->next = t;
		}
	}
};
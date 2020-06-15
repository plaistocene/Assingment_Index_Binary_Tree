#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "WordTypeNode.h"    //	includes FileNameNode.h

#define WALKNEXT walk = walk->next

class IndexLinkedList {
private:
	enum Letter {
		a = 0, b, c, d, e,
		f, g, h, i, j,
		k, l, m, n, o,
		p, q, r, s, t,
		u, v, w, x, y, z = 25
	};
	WordTypeNode *head[26];
public:
	IndexLinkedList() : head() {}

	void AddWord(const std::string &word,
				 const std::string &fileName) {
		const int theHead = FindWhichHead(word);
		if (head[theHead] == nullptr) {
			head[theHead] = new WordTypeNode(word, fileName);
			return;
		}
		AddWordRec(head[theHead], word, fileName);
	}

	void AddWordRec(WordTypeNode *root, const std::string &word, const std::string &fileName) {
		if (root->GetWord() == word) {
			wordLessEqualRoot(root, word, fileName);
			return;
		}

		if (!LexiSmall(root->GetWord(), word)) {
			if (root->left == nullptr) {
				root->left = new WordTypeNode(word, fileName);
				return;
			}
			if (root->left != nullptr) {
				AddWordRec(root->left, word, fileName);
				return;
			}
		}
		if (LexiSmall(root->GetWord(), word)) {
			if (root->right == nullptr) {
				root->right = new WordTypeNode(word, fileName);
				return;
			}
			if (root->right != nullptr) {
				AddWordRec(root->right, word, fileName);
				return;
			}
		}
	}

private:
	static void wordLessEqualRoot(WordTypeNode *&r, const std::string &word, const std::string &fileName) {
		r->UpdateFreq();
		r->AddFileNameNode(fileName);
	}

	static inline bool LexiSmall(const std::string &rootWord, const std::string &word) {
		return std::lexicographical_compare(rootWord.begin(), rootWord.end(), word.begin(), word.end());
	}

public:
	std::vector<std::string> GetListOfFiles(const std::string &singleWordQuery) const {
		std::vector<std::string> listOfFilesNames;

		const int theHead = FindWhichHead(singleWordQuery);
		GetListOfFilesRec(head[theHead], listOfFilesNames, singleWordQuery);

		return listOfFilesNames;
	}

private:
	void GetListOfFilesRec(WordTypeNode *root, std::vector<std::string> &listOfFilesNames,
						   const std::string &singleWordQuery) const {
		if (root == nullptr) return;
		if (root->GetWord() == singleWordQuery) {
			FillTheVector(root, listOfFilesNames);
			return;
		}
		if (LexiSmall(root->GetWord(), singleWordQuery))
			GetListOfFilesRec(root->right, listOfFilesNames, singleWordQuery);
		if (!LexiSmall(root->GetWord(), singleWordQuery))
			GetListOfFilesRec(root->left, listOfFilesNames, singleWordQuery);
	}

	void FillTheVector(WordTypeNode *r, std::vector<std::string> &listOfFilesNames) const {
		FileNameNode *walk = r->fileListHead;
		while (walk) {
			listOfFilesNames.push_back(walk->fileName);
			WALKNEXT;
		}
	}

public:
	std::vector<std::pair<std::string, int>> GetMostFrequentWords(const int topWhat) {
		std::pair<std::string, int> dummyPair("", 0);
		std::vector<std::pair<std::string, int>> tops(topWhat, dummyPair);

		for (auto theHead : head) {
			if (theHead) {
				WordTypeNode *root = theHead;
				GetMostFrequentWordsRec(root, tops);
			}
		}

		return tops;
	}

private:
	void GetMostFrequentWordsRec(WordTypeNode *root, std::vector<std::pair<std::string, int>> &tops) {
		if (!root) return;
		auto it = tops.begin();
		for (auto &i: tops) {
			if (root->GetFreq() > i.second) {
				std::pair<std::string, int> ins(root->GetWord(), root->GetFreq());
				tops.insert(it, ins);
				tops.pop_back();
				break;
			}
			it++;
		}
		GetMostFrequentWordsRec(root->left, tops);
		GetMostFrequentWordsRec(root->right, tops);
	}

public:
	std::vector<std::pair<std::string, int>> GetLeastFrequentWords(int leastWhat) {
		std::vector<std::pair<std::string, int>> leasts;
		int countForFirstNItem = 0;

		for (auto theHead : head) {
			WordTypeNode *root = theHead;
			GetLeastFrequentWordsRec(root, leasts, countForFirstNItem, leastWhat);
		}

		return leasts;
	}
/*
		int countForFirstNItem = 0;

		std::vector<std::pair<std::string, int>> leasts;

		for(auto &theHead : head) {
			WordTypeNode *walk = theHead;

			while(walk) {
				if(countForFirstNItem < leastWhat) {
					std::pair<std::string, int> ins(walk->GetWord(), walk->GetFreq());
					leasts.push_back(ins);
				} else {
					for(int i = 0; i < leasts.size(); i++) {
						if(walk->GetFreq() < leasts[i].second) {
							std::vector<std::pair<std::string, int>>::iterator it;
							it = leasts.begin() + i;
							std::pair<std::string, int> ins(walk->GetWord(), walk->GetFreq());
							leasts.insert(it, ins);
							leasts.pop_back();
							break;
						}
					}
				}
				countForFirstNItem++;
				walk = walk->next;
			}
		}
		return leasts;
 * */
private:
	static bool SortBySecond(const std::pair<std::string, int> &a,
							 const std::pair<std::string, int> &b) {
		return (a.second < b.second);
	}

	void GetLeastFrequentWordsRec(WordTypeNode *root, std::vector<std::pair<std::string, int>> &leasts,
								  int &countForFirstNItem, const int leastWhat) {
		if (!root) return;
		if (countForFirstNItem < leastWhat) {
			std::pair<std::string, int> ins(root->GetWord(), root->GetFreq());
			leasts.push_back(ins);
			countForFirstNItem++;
			std::sort(leasts.begin(), leasts.end(), SortBySecond);
		} else {
			for (int i = 0; i < leasts.size(); i++) {
				if (root->GetFreq() < leasts[i].second) {
					auto it = leasts.begin() + i;
					std::pair<std::string, int> ins(root->GetWord(), root->GetFreq());
					leasts.insert(it, ins);
					leasts.pop_back();
					break;
				}
			}
		}
		GetLeastFrequentWordsRec(root->left, leasts, countForFirstNItem, leastWhat);
		GetLeastFrequentWordsRec(root->right, leasts, countForFirstNItem, leastWhat);
	}

	/* other private helper methos or public method that you may wish to add */
private:
	static int FindWhichHead(const std::string &word) {
		if (word[0] == 'a') return a;
		if (word[0] == 'b') return b;
		if (word[0] == 'c') return c;
		if (word[0] == 'd') return d;
		if (word[0] == 'e') return e;
		if (word[0] == 'f') return f;
		if (word[0] == 'g') return g;
		if (word[0] == 'h') return h;
		if (word[0] == 'i') return i;
		if (word[0] == 'j') return j;
		if (word[0] == 'k') return k;
		if (word[0] == 'l') return l;
		if (word[0] == 'm') return m;
		if (word[0] == 'n') return n;
		if (word[0] == 'o') return o;
		if (word[0] == 'p') return p;
		if (word[0] == 'q') return q;
		if (word[0] == 'r') return r;
		if (word[0] == 's') return s;
		if (word[0] == 't') return t;
		if (word[0] == 'u') return u;
		if (word[0] == 'v') return v;
		if (word[0] == 'w') return w;
		if (word[0] == 'x') return x;
		if (word[0] == 'y') return y;
		if (word[0] == 'z') return z;
		else { return -1; }
	}

};
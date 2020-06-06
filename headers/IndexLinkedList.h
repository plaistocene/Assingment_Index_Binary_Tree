#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#include "WordTypeNode.h"	//	includes FileNameNode.h

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
	IndexLinkedList() :head() {}

	void AddWord(const std::string &word, const std::string &fileName) {	//	I fixed the lexicographical thing but needed to fixthis
		const int theHead = FindWhichHead(word);
		if(head[theHead] == nullptr) {
			head[theHead] = new WordTypeNode(word, fileName);
			return;
		}

		WordTypeNode *walk = head[theHead];
		WordTypeNode *prev = walk;
		while(walk->next) {	//TODO: FIXME:	make this thing as while(walk)
			std::string walkWord = walk->GetWord(), walkNextWord = walk->next->GetWord();
			if(walk->GetWord() == word) {
				walk->UpdateFreq();
				walk->AddFileNameNode(fileName);
				return;
			} else if(std::lexicographical_compare(word.begin(), word.end(),	//	Make them inline functions 
												   walkWord.begin(), walkWord.end())) {
				if(walk == head[theHead]) {
					WordTypeNode *t = new WordTypeNode(word, fileName);
					t->next = head[theHead];
					head[theHead] = t;
					return;
				} else {
					WordTypeNode *t = new WordTypeNode(word, fileName);
					t->next = walk;
					prev->next = t;
					return;
				}
			} else if(std::lexicographical_compare(walkWord.begin(), walkWord.end(),
												   word.begin(), word.end()) &&
					  std::lexicographical_compare(word.begin(), word.end(),
												   walkNextWord.begin(), walkNextWord.end())) {
				WordTypeNode *t = new WordTypeNode(word, fileName);
				t->next = walk->next;
				walk->next = t;
				return;
			}
			prev = walk;
			walk = walk->next;
		}

		if(!walk->next) {
			std::string walkWord = walk->GetWord();
			if(walk->GetWord() == word) {
				walk->UpdateFreq();
				walk->AddFileNameNode(fileName);
				return;
			} else if(std::lexicographical_compare(word.begin(), word.end(),	//	Make them inline functions 
												   walkWord.begin(), walkWord.end())) {
				if(walk == head[theHead]) {
					WordTypeNode *t = new WordTypeNode(word, fileName);
					t->next = head[theHead];
					head[theHead] = t;
					return;
				} else {
					WordTypeNode *t = new WordTypeNode(word, fileName);
					t->next = walk;
					prev->next = t;
					return;
				}
			} else {
				WordTypeNode *t = new WordTypeNode(word, fileName);
				walk->next = t;
				return;
			}
		}
	}

	std::vector<std::string> GetListOfFiles(const std::string &singleWordQuery)const {
		std::vector<std::string> listOfFilesNames;

		bool flag = false;
		const int theHead = FindWhichHead(singleWordQuery);

		WordTypeNode *walk = head[theHead];
		while(walk) {
			if(walk->GetWord() == singleWordQuery) {
				FileNameNode *fileWalker = walk->fileListHead;
				while(fileWalker) {
					listOfFilesNames.push_back(fileWalker->fileName);
					fileWalker = fileWalker->next;
					if(!fileWalker)
						flag = true;
				}
				std::cout << std::endl;
			}
			if(flag)
				break;
			walk = walk->next;
		}

		return listOfFilesNames;
	}

	std::vector<std::pair<std::string, int>> GetMostFrequentWords(const int topWhat)const {
		using std::cout;
		using std::endl;

		std::pair<std::string, int> i;
		i.first = "";
		i.second = 0;

		std::vector<std::pair<std::string, int>> tops(topWhat, i);

		for(auto &theHead : head) {
			WordTypeNode *walk = theHead;

			while(walk) {
				if(walk->GetFreq() > tops[topWhat].second) {
					for(int j = tops.size(); 0 <= j; j--) {
						if(walk->GetFreq() < tops[j].second || j == 0) {
							std::vector<std::pair<std::string, int>>::iterator it;
							if(j == 0 && walk->GetFreq() > tops[0].second)
								it = tops.begin();
							else
								it = tops.begin() + j + 1;

							std::pair<std::string, int> ins(walk->GetWord(), walk->GetFreq());
							tops.insert(it, ins);
							tops.pop_back();
							break;
						}
					}
				}
				walk = walk->next;
			}
		}
		return tops;
	}

	std::vector<std::pair<std::string, int>> GetLeastFrequentWords(int leastWhat) {
		using std::cout;
		using std::endl;
		//std::pair<std::string, int> i;
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

		//			if(walk->GetFreq() < leasts[0].second) {
		//				std::vector<std::pair<std::string, int>>::iterator it;
		//				it = leasts.begin();
		//				std::pair<std::string, int> ins(walk->GetWord(), walk->GetFreq());
		//				leasts.insert(it, ins);
		//			} else {
		//				for(int j = tops.size(); 0 <= j; j--) {
		//					if(walk->GetFreq() < tops[j].second || j == 0) {
		//						std::vector<std::pair<std::string, int>>::iterator it;
		//						if(j == 0 && walk->GetFreq() > tops[0].second)
		//							it = tops.begin();
		//						else
		//							it = tops.begin() + j + 1;

		//						std::pair<std::string, int> ins(walk->GetWord(), walk->GetFreq());
		//						tops.insert(it, ins);
		//						tops.pop_back();
		//						break;
		//					}
		//				}
		//			}
		//			walk = walk->next;
		//		}
		//	}
		//}
		////TODO: do a loop get the goods
		//cout << "Least" << ' ' << topWhat << ' ' << "Words are:.." << endl;
	}


public:
	void PrintListWithSpecificLetter(const std::string &letter)const {
		using std::cout;
		using std::endl;
		//TODO: do a loop get the goods
		int theHead = FindWhichHead(letter);
		WordTypeNode *walk = head[theHead];

		cout << "The Words That Starts with" << ' ' << letter << ' ' << "are:.." << endl;

		while(walk) {
			cout << walk->GetWord() << ':' << walk->GetFreq() << endl;
			walk = walk->next;
		}
	}

	/* other private helper methos or public method that you may wish to add */
private:
	int FindWhichHead(const std::string &word)const {
		if(word[0] == 'a') return a;
		if(word[0] == 'b') return b;
		if(word[0] == 'c') return c;
		if(word[0] == 'd') return d;
		if(word[0] == 'e') return e;
		if(word[0] == 'f') return f;
		if(word[0] == 'g') return g;
		if(word[0] == 'h') return h;
		if(word[0] == 'i') return i;
		if(word[0] == 'j') return j;
		if(word[0] == 'k') return k;
		if(word[0] == 'l') return l;
		if(word[0] == 'm') return m;
		if(word[0] == 'n') return n;
		if(word[0] == 'o') return o;
		if(word[0] == 'p') return p;
		if(word[0] == 'q') return q;
		if(word[0] == 'r') return r;
		if(word[0] == 's') return s;
		if(word[0] == 't') return t;
		if(word[0] == 'u') return u;
		if(word[0] == 'v') return v;
		if(word[0] == 'w') return w;
		if(word[0] == 'x') return x;
		if(word[0] == 'y') return y;
		if(word[0] == 'z') return z;
	}

};
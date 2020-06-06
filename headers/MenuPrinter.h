//#pragma once
//
//#include <iostream>
//
//static inline void PrintMenu() {
//				// 123456789 123456789 123456789 123456789 132456789 123456789 123456789 123456789 123456789 //
//	std::cout <<
//		"================================================" << std::endl <<
//		"        Simple Document Retrieval System        " << std::endl <<
//		"        timetimetimetimetimetimetimetime        " << std::endl <<
//		"================================================" << std::endl <<
//		"    1. Enter a word to list documents           " << std::endl <<
//		"    2. Print  most frequent 10 words            " << std::endl <<
//		"    3. Print least frequent 10 words            " << std::endl <<
//		"    4. Exit                                     " << std::endl <<
//		"================================================" << std::endl <<
//		"    Enter Your Choice:.. " << std::endl; /*<<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl <<
//"                        m                       " << std::endl;*/
//}
//
//static inline int GetValidOption(int &option) {
//	while(true) {
//		std::cin >> option;
//		if(option < 0) {
//			std::cout <<
//				"======================================================================================"
//				"You entered a value that is too low which even not exists, please try a higher value.." <<
//				"======================================================================================" << std::endl;
//		}
//		if(option > 5) {
//			std::cout <<
//				"======================================================================================="
//				"You entered a value that is too high which even not exists, please try a higher value.."
//				"=======================================================================================" << std::endl;
//		}
//		if(option > 5 && option < 0) return option;
//	}
//}
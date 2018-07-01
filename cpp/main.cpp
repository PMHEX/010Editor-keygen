#include <iostream>
#include <ctime>
//#include "stdafx.h" 	// deprecate, this is for windows only
#include "_010EditorKeygen.hpp"
//#include <tchar.h> 	// deprecate, this is for windows only
//#include <windows.h> 	// deprecate, this is for windows only

// based on @DeltaFoX
int main(int argc, char* argv[]) {
	static_assert(sizeof(std::time_t) == 8, "We use 64-bits time_t only.");
	
	if (argc < 5) {
		std::cout << "Usage:" << std::endl;
		std::cout << "        010Editor-keygen.exe <your name> <year> <month> <day> <numbers of user>" << std::endl << std::endl;
		std::cout << "Example:" << std::endl << std::endl;
		std::cout << "        010Editor-keygen.exe DeltaFoX 2106 02 08 999" << std::endl;
		return 0;
	}

	std::string name(argv[1]);

	int ExpireYear = atoi(argv[2]);
	int ExpireMonth = atoi(argv[3]);
	int ExpireDay = atoi(argv[4]);
	int LicenseCount = (argv[5] != NULL && atoi(argv[5]) > 0 && atoi(argv[5]) <= 1000) ? atoi(argv[5]) : 1;
	
	std::tm ExpireDate = { 0, 0, 0, ExpireDay, ExpireMonth - 1, ExpireYear - 1900 };
	std::time_t ExpireTimestamp = std::mktime(&ExpireDate);
	if (ExpireTimestamp == -1) {
		std::cout << "Invalid ExpireDate!" << std::endl;
		return 0;
	}
	
	uint32_t ExpireDaystamp = ExpireTimestamp / 3600 / 24;
	std::vector<byte> name_bytes(name.begin(), name.end());
	
	_010Editor::Keygen<_010Editor::KeyType::TimeLicense> keygen;
	std::cout << keygen.GetKey(name_bytes, ExpireDaystamp, LicenseCount) << std::endl;
	return 1;
}

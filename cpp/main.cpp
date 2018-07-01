#include <iostream>
#include <ctime>
#include "stdafx.h"
#include "_010EditorKeygen.hpp"
#include <tchar.h>
#include <windows.h>

int main(int argc, CHAR* argv[])
{
	if (argc < 5) {
		_tprintf_s(TEXT("Usage:\n"));
		_tprintf_s(TEXT("        010Editor-keygen.exe <your name> <year> <month> <day> <numbers of user>\n\n"));
		_tprintf_s(TEXT("Example:\n\n"));
		_tprintf_s(TEXT("        010Editor-keygen.exe DeltaFoX 2106 02 08 999\n"));
		return 0;
	}

	std::string name(argv[1]);

	std::tm ZeroDate = { 0, 0, 0, 1, 1, 1970 - 1900 };

	int ExpireYear = atoi(argv[2]);
	int ExpireMonth = atoi(argv[3]);
	int ExpireDay = atoi(argv[4]);
	int LicenseCount = (argv[5] != NULL && atoi(argv[5]) > 0 && atoi(argv[5]) < 1000) ? atoi(argv[5]) : 1;
	std::tm ExpireDate = { 0, 0, 0, ExpireDay + 2, ExpireMonth, ExpireYear - 1900 };
	uint32_t ExpireDaystamp = static_cast<uint32_t>(std::difftime(std::mktime(&ExpireDate), std::mktime(&ZeroDate)) / 3600 / 24);

	std::vector<byte> name_bytes(name.begin(), name.end());
	_010Editor::Keygen<_010Editor::KeyType::TimeLicense> keygen;
	std::cout << keygen.GetKey(name_bytes, ExpireDaystamp, LicenseCount) << std::endl;
	return 1;
}

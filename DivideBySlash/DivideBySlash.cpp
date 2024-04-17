#define _CRT_SECURE_NO_WARNINGS 1

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <string>
#include <iostream>

const std::wstring getFilenameFromUser()
{
	return L"C:∖SensitiveFiles∖WorldDominationPlans.txt";
}

std::string ConvertWideToANSI(const std::wstring& wstr)
{
	int count = WideCharToMultiByte(CP_OEMCP, 0, wstr.c_str(), wstr.length(), NULL, 0, NULL, NULL);
	std::string str(count, 0);
	WideCharToMultiByte(CP_OEMCP, 0, wstr.c_str(), -1, &str[0], count, NULL, NULL);
	return str;
}

int main()
{
	const std::wstring path = getFilenameFromUser();
	if (path.find(L"\\") != std::wstring::npos) {
		std::wcout << L"Found '\\' in the path" << std::endl;
		return 1;
	}

	auto str = ConvertWideToANSI(path);

	// Do something sensitive with the path
	std::cout << str << std::endl;

	std::string ipLH = "lοcalhοst";
	if (ipLH == "localhost") {
		std::cout << "You can't access localhost, go away" << std::endl;
	}


	return 0;
}


#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include "bitextractor.hpp"
#include <thread>
using namespace std;
using namespace bit7z;
struct Timer {
	std::chrono::time_point<std::chrono::system_clock> start;
	wstring operation;
	Timer(const wstring& op):operation(op)
	{
		start = std::chrono::system_clock::now();
	}
	~Timer()
	{
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_seconds = end - start;
		wprintf(L"Time taken for %ls is %lf\n", operation, elapsed_seconds);
		//std::wcout << "elapsed time for " << operation << " is : " << elapsed_seconds.count() << "s\n";
	}	
};

class CompressUtil
{
	 wstring fileName;
public:
	CompressUtil( wstring file_in) : fileName(file_in) {};
	~CompressUtil() = default;

	bool testPassword(const wstring& password) const
	{
		/*if (password[0] == '1')
		Timer t(password);*/
		Bit7zLibrary lib{ L"C:\\Program Files\\7-Zip\\7z.dll" };
		BitExtractor extractor{ lib, BitFormat::Rar5 };
		extractor.setPassword(password);
		try {
			extractor.test(fileName);
		}
		catch (...)
		{
			return false;
		}
		return true;
		//{
		//	//printAllCombinations(3, charset);

		////BitExtractor extractor{ lib, BitFormat::SevenZip };
		//	BitExtractor extractor{ lib, BitFormat::Rar5 };

		//	//extractor.extract(L"D:\\Others\\Test\\EditedDoc.7z", L"D:\\Others\\Test\\"); //extracting a simple archive

		//	//extractor.extractMatching(L"path/to/arc.7z", L"file.pdf", L"out/dir/"); //extracting a specific file

		//	//extracting the first file of an archive to a buffer
		//	//std::vector< byte_t > buffer;
		//	//extractor.extract(L"path/to/archive.7z", buffer);

		//	//extracting an encrypted archive
		//	extractor.setPassword(L"12345676");
		//	//extractor.extract(L"D:\\Others\\Test\\EditedDoc.7z", L"D:\\Others\\Test\\");
		//	//extractor.extract(L"D:\\Others\\Test\\NewRichTextDocument.rar", L"D:\\Others\\Test\\");
		//	{
		//		Timer t("extractor. test");
		//		extractor.test(L"D:\\Others\\Test\\test.rar");
		//	}

		//	{
		//		Timer t("extractor. test");
		//		extractor.extract(L"D:\\Others\\Test\\test.rar", L"D:\\Others\\Test\\");
		//	}
		//}
	}
};

class CombinationUtil
{
	const wstring& characters;
private:
	void checkUtil(int k, int idx, wstring& chosen, const CompressUtil& util, bool &success)
	{
		if (success)
			return;

		int num = _wcstoi64_l(chosen.c_str(),nullptr, 10, NULL);
		if (util.testPassword(chosen))
		{
			wcout<< "password Found: <" << chosen << ">\n";
			success = true;
			
			return;
		}

		if (chosen.size() == k) {
			
			return;
		}

		for (int i = 0; i < characters.size()&& !success; ++i)
		{
			chosen += characters[i];
			checkUtil(k, i + 1, chosen, util, success);
			chosen.erase(chosen.size() - 1);
		}
	}
public:
	CombinationUtil(wstring& charset) : characters(charset) {};
	~CombinationUtil() = default;

	bool checkAllCombinations(int k, CompressUtil& util)
	{
		wstring chosen = L"";
		static bool success = false;
		checkUtil(k, 0, chosen, util, success);
		return success;
	}


	bool checkCombinationMultiThreaded(wstring intial, int len, CompressUtil& util)
	{
		bool success = false;
		checkUtil(len, 0, intial, util, success);
		return success;
	}
};
#include <algorithm>
using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
	string result = "Impossible";

	vector<int> boxSize(container.size(), 0);
	vector<int> boxCount(container.size(), 0);

	for (int i = 0; i < container.size(); ++i)
	{
		for (int j = 0; j < container[0].size(); ++j)
		{
			boxSize[i] += container[i][j];
			boxCount[j] += container[i][j];
			;
		}
	}
	std::sort(boxSize.begin(), boxSize.end(), std::greater<int>());
	std::sort(boxCount.begin(), boxCount.end(), std::greater<int>());
	// cout << boxSize[0] << " " << boxSize[1] << " ";
	// cout << boxCount[0] << " " << boxCount[1]  << " ";

	for (int i = 0; i < boxCount.size(); ++i)
		if (boxSize[i] != boxCount[i])
		{
			return result;
		}
	result = "Possible";
	return result;
}


int main()
{
	std::vector<std::vector<int>> vec{ {0, 2, 1},  {1, 1, 1}, {2, 0, 0} };
	cout << organizingContainers(vec);
	wstring charset = L"1234567"; // abcdefghijklmnopqrstuvwxyz1234567890
	wstring numset = L"0987654321";

	int len = 7;
	CompressUtil util(L"D:\\Others\\Test\\test.rar");
	if (len == 1 && !CombinationUtil(charset).checkAllCombinations(len, util))
	{
		CompressUtil util(L"D:\\Others\\Test\\test.rar");
		cout << "not found";
	}
	else if (len == 4)
	{
		Timer y(L"Single Thread");
		CompressUtil util(L"D:\\Others\\Test\\test.rar");
		util.testPassword(L"1234567");
		if(!CombinationUtil(charset).checkCombinationMultiThreaded(L"a", len, util))
			cout << "not found";
	}
	else
	{
		Timer y(L"MultiThreaded");
		std::vector<std::thread> vecOfThreads;

		for (int i = 0; i < charset.size(); ++i)
		{
			//CompressUtil util(L"D:\\Others\\Test\\Only The TOP 5 % Of The Population Knows THIS!.part01.rar");
			CompressUtil util(L"D:\\Others\\Test\\test.rar");
			CombinationUtil comb(charset);
			std::thread th(&CombinationUtil::checkCombinationMultiThreaded, comb, wstring(1, charset[i]), len, std::ref(util));
			//std::thread th(&CombinationUtil::fun, comb, std::ref(util), len);
			vecOfThreads.push_back(std::move(th));
		}
	
		for (std::thread& th : vecOfThreads)
		{
			// If thread Object is Joinable then Join that thread.
			if (th.joinable())
				th.join();
		}
	}
	return 0;
}





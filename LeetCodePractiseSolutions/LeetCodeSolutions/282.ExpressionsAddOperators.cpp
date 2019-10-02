#include "headers.h"
/*

282. Expression Add Operators
Hard

Given a string that contains only digits 0-9 and a target value, 
return all possibilities to add binary operators 
(not unary) +, -, or * between the digits so they evaluate to the target value.

Example 1:

Input: num = "123", target = 6
Output: ["1+2+3", "1*2*3"]

Example 2:

Input: num = "232", target = 8
Output: ["2*3+2", "2+3*2"]

Example 3:

Input: num = "105", target = 5
Output: ["1*0+5","10-5"]

Example 4:

Input: num = "00", target = 0
Output: ["0+0", "0-0", "0*0"]

Example 5:

Input: num = "3456237490", target = 9191
Output: []


*/

class Solution {
private:
	// cur: {string} expression generated so far.
	// pos: {int}    current visiting position of num.
	// cv:  {long}   cumulative value so far.
	// pv:  {long}   previous operand value.
	// op:  {char}   previous operator used.
	void dfs(std::vector<string>& res, const string& num, const int target, string cur, int pos, const long cv, const long pv, const char op) {
		if (pos == num.size() && cv == target) {
			res.push_back(cur);
		}
		else {
			for (int i = pos + 1; i <= num.size(); i++) {
				string t = num.substr(pos, i - pos);
				long now = stol(t);
				if (to_string(now).size() != t.size()) continue;
				dfs(res, num, target, cur + '+' + t, i, cv + now, now, '+');
				dfs(res, num, target, cur + '-' + t, i, cv - now, now, '-');
				dfs(res, num, target, cur + '*' + t, i, (op == '-') ? cv + pv - pv * now : ((op == '+') ? cv - pv + pv * now : pv * now), pv * now, op);
			}
		}
	}

public:
	vector<string> addOperators(string num, int target) {
		vector<string> res;
		if (num.empty()) return res;
		for (int i = 1; i <= num.size(); i++) {
			string s = num.substr(0, i);
			long cur = stol(s);
			if (to_string(cur).size() != s.size()) continue;
			dfs(res, num, target, s, i, cur, cur, '#');         // no operator defined.
		}

		return res;
	}
};

class Solution282 {

private:
	void dfs(string operation, string numbers, int index, int currentResult, int target, vector<string>& result)
	{
		if (index == numbers.size() && currentResult == target)
			result.push_back(operation);
		else {
			for (int i = 1; i + index <= numbers.size(); ++i)
			{
				string str = numbers.substr(index, i);
				//operation = operation + numbers.substr(index, i - 1) + lastOp;
				long number = stol(str);
				dfs(operation + '+' + str, numbers, index + 1, currentResult + number, target, result);
				dfs(operation + '-' + str, numbers, index + 1, currentResult - number, target, result);
				dfs(operation + '*' + str, numbers, index + 1, currentResult * number, target, result);
			}
			
		}
	}
public:
	vector<string> addOperators(string num, int target) {
		vector<string> result;
		dfs(num.substr(0, 1), num, 1, stoi(num.substr(0, 1)), target, result);

		return result;
	}
};

int main282()
{
	Solution282 s;
	s.addOperators("1234", 19);
	return 0;
}
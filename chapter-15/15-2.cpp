/*
 * Filename: 15-2.cpp 
 * 
 * 输入字符串，输出该字符串的最长回文串
 * 
 */

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

string find_max_pal(const string& str)
{
	int max_len = 1, start_index;
	bool EVEN = false;
	string max_pal;
	
	int new_half_len_odd, new_start_odd, j_odd, max_len_odd;
	int new_half_len_even, new_start_even, j_even, max_len_even;
	for (int i = 1; i < str.size(); i++)
	{
		/* 如果加上当前字符，可以构成更长的的回文串的话，则更新 max_len, start_index */
		/* 分两种，奇数，与偶数 */
		if (EVEN == true)
		{
			new_half_len_even = (max_len + 2) / 2;
			new_start_even = i - 2*new_half_len_even + 1;
			new_half_len_odd = (max_len + 1) / 2;
			new_start_odd = i - 2*new_half_len_odd;
		}
		else // EVEN == false, ODD
		{
			new_half_len_even = new_half_len_odd = (max_len + 1) / 2;
			new_start_even = i - 2*new_half_len_even + 1;
			new_start_odd = i - 2*new_half_len_odd;
		
		}
		
		j_odd = 0;
		max_len_odd = 0;
		while (j_odd < new_half_len_odd)
		{
			if (str[new_start_odd + j_odd] != str[i - j_odd])
				break;
			else
				++j_odd;
		}
		if (j_odd == new_half_len_odd)
			max_len_odd += 2*new_half_len_odd + 1;

		j_even = 0;
		max_len_even = 0;
		while (j_even < new_half_len_even)
		{
			if (str[new_start_even + j_even] != str[i-j_even])
				break;
			else 
				++j_even;
		}
		if (j_even == new_half_len_even)
			max_len_even = 2*new_half_len_even;
		
		if (max_len_even != 0 || max_len_odd != 0)
		{
			if (max_len_odd > max_len_even)
			{
				max_len = max_len_odd;
				start_index = new_start_odd;
				EVEN = false;
			}
			else
			{
				max_len = max_len_even;
				start_index = new_start_even;
				EVEN = true;
			}
		}

		/* 如果不能，则保持原来的最长回文串 */
	}
	
	for (int i = 0; i < max_len; i++)
		max_pal.push_back(str[start_index + i]);

	return max_pal;
}

int main()
{
	string str1 = "charahcter", str2 = "abcdddfghjkjhgfdmmm", str3 = "abcddcbajjj", str4 = "djfghjkkjhgfsqwdsadxsa", str5 = "hh";
	cout << find_max_pal(str1) << endl;
	cout << find_max_pal(str2) << endl;
	cout << find_max_pal(str3) << endl;
	cout << find_max_pal(str4) << endl;
	cout << find_max_pal(str5) << endl;
	return 0;
}








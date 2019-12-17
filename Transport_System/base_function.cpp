#include "base_function.h"

int str_int(string s)
{
	int f = 1, res = 0;
	if (s[0] == '-') f = -1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-') continue;
		res = res * 10 + s[i] - '0';
	}
	return f * res;
}

string int_str(int x)
{
	string res = "";
	int flag = 0;
	if (x < 0) {
		flag = 1;
		x = -x;
	}
	while (x){
		res += (char)(x % 10 + '0');
		x /= 10;
	}
	if (flag == 1) {
		res += '-';
	}
	reverse(res.begin(),res.end());
	
	return res;
}
#pragma once

#include <string>
#include "User.h"
#include <vector>
#include <map>
#include <stack>
#include "flag.h"

using namespace std;

class User_set {
public:
	vector <User> list;
	map <string, int> s_user;
	stack <int> Available;
	vector <bool> vis;

	bool check(string username);
	bool signin(string username, string password);
	void signup(string username, string password, string name, int sex, int age);
	void signoff(int id);
	void change_info(int id, string name, int sex, int age);
	void Ins_Uesr(string username, string password, string name, int sex, int age,int admin);
};
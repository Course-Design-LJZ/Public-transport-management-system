#pragma once

#include <string>
#include "base_function.h"
#include "flag.h"
#include "AES.h"

using namespace std;

class User {
public:
	string username;

	bool check_password(string s);
	string query_name();
	int query_sex();
	int query_age();

	string AES_username();
	string AES_password();
	string AES_name();
	string AES_sex();
	string AES_age();
	string AES_admin();

	void init(string username, string password, string name, int sex, int age, int admin);

	bool set_admin(bool flag,int admin);
	void set_name(string s);
	void set_age(int age);
	void set_sex(int flag);

private:
	string password;
	string name;
	int sex;
	int age;
	int admin;
};
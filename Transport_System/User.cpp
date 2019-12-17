#include "User.h"

bool User::check_password(string s)
{
	if (this->password == s) {
		return _OK_;
	}
	return _NO_;
}

string User::query_name()
{
	return this->name;
}

int User::query_sex()
{
	return this->sex;
}

int User::query_age()
{
	return this->age;
}

string User::AES_username()
{
	AES solve;
	return solve.EncryptionAES(this->username);
}

string User::AES_password()
{
	AES solve;
	return solve.EncryptionAES(this->password);
}

string User::AES_name()
{
	AES solve;
	return solve.EncryptionAES(this->name);
}

string User::AES_sex()
{
	AES solve;
	return solve.EncryptionAES(int_str(this->sex));
}

string User::AES_age()
{
	AES solve;
	return solve.EncryptionAES(int_str(this->age));
}

string User::AES_admin()
{
	AES solve;
	return solve.EncryptionAES(int_str(this->admin));
}

void User::init(string username, string password, string name, int sex, int age, int admin)
{
	this->username = username;
	this->password = password;
	this->name = name;
	this->sex = sex;
	this->age = age;
	this->admin = admin;
}







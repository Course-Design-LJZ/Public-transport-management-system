#include "User.h"
#include <iostream>

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

int User::query_admin()
{
	return this->admin;
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

bool User::set_admin(bool flag1,int flag2)
{
	if (_USER<=flag1 && flag1<=_ADMIN && flag2 > this->admin && flag2 <= _0ADMIN) {
		this->admin = flag1;
		return _OK_;
	}
	return _NO_;
}

void User::set_name(string s)
{
	this->name = s;
}

void User::set_age(int age)
{
	this->age = age;
}

void User::set_sex(int flag)
{
	this->sex = flag;
}

void User::set_password(string s)
{
	this->password = s;
}

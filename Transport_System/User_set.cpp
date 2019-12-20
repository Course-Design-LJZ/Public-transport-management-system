#include "User_set.h"

bool User_set::check(string username)
{
	if (s_user[username] != 0) {
		return _OK_;
	}
	else
		return _NO_;
}

bool User_set::signin(string username, string password)
{
	int id = s_user[username];
	return list[id - 1].check_password(password);
}

void User_set::signup(string username, string password, string name, int sex, int age)
{
	if (list.size() == 0) {
		User tmp;
		tmp.init("admin", "998244353", "admin", _none, 0, _0ADMIN);
		list.push_back(tmp);
		s_user["admin"] = 1;
		vis.push_back(1);
	}
	if (!Available.empty()) {
		int id = Available.top();
		list[id].init(username, password, name, sex, age, _USER);
		s_user[username] = id + 1;
		vis[id] = 1;
	}
	else {
		User tmp;
		tmp.init(username, password, name, sex, age, _USER);
		list.push_back(tmp);
		s_user[username] = list.size();
		vis.push_back(1);
	}
}

void User_set::signoff(int id)
{
	Available.push(id);
	vis[id] = 0;
	s_user[list[id].username] = 0;
}

void User_set::change_info(int id, string name, int sex, int age)
{
	list[id].set_name(name);
	list[id].set_sex(sex);
	list[id].set_age(age);
}

void User_set::Ins_Uesr(string username, string password, string name, int sex, int age,int admin)
{
	User tmp;
	tmp.init(username, password, name, sex, age, admin);
	list.push_back(tmp);
	s_user[username] = list.size();
	vis.push_back(1);
}

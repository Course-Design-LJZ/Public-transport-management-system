#include "interaction.h"

Graph_map G;
User_set now;
User now_user;

void init()
{
	_mkdir("data");
	_mkdir("data\\user");
	_mkdir("data\\line");
	_mkdir("data\\input");
	_mkdir("data\\output");
	now = File_input_User_set_AES();
	G = File_input_Graph_map_AES();
}

void outit() {
	File_output_User_set_AES(now);
	File_output_Graph_map_AES(G);
}

void infile() {
	G = File_input_Graph_map();
	system("cls");
	cout << u8"����ɹ�" << endl;
	system("pause");
}

void outfile() {
	File_output_Graph_map(G);
	system("cls");
	cout << u8"�����ɹ�" << endl;
	system("pause");
}

void query_station()
{
	int flag = draw_station(u8"��ѡ��Ҫ��ѯ��վ��", G);
	if (flag == 0) return;
	system("cls");
	if (flag < G.station_list.size()) {
		station s = G.station_list[flag];
		cout << u8"����" << s.name << u8"��·����:" << endl;
		for (auto v : s.pass_line) {
			cout << G.line_list[v].name << endl;
		}
	}
	system("pause");
}

void query_line() {
	int flag = draw_line(u8"��ѡ��Ҫ��ѯ��·��", G);
	if (flag == 0) return;
	system("cls");
	if (flag < G.line_list.size()) {
		line L = G.line_list[flag];
		cout << L.name << u8"������վ����:" << endl;
		for (auto v : L.list) {
			cout << v.name << endl;
		}
	}
	system("pause");
}

void query_station_station()
{
	int flag1 = draw_station(u8"��ѡ�����", G);
	if (flag1 == 0) return;
	int flag2 = draw_station(u8"��ѡ���յ�", G);
	if (flag2 == 0) return;
	get_all_road solve;
	system("cls");
	cout << u8"���еĺϷ�·��Ϊ:" << endl;
	solve.init(G.station_list.size());
	solve.dfs(G.station_list[flag1].id, G.station_list[flag2].id, G.G);
	for (auto v : solve.res) {
		while (!v.empty())
		{
			cout << G.station_list[G.i_station[v.front()]].name <<"->";
			v.pop_front();
			if (v.size() == 1)break;
		}
		cout << G.station_list[G.i_station[v.front()]].name << endl;
		v.pop_front();
	}
	system("pause");
}

void query_sort_path()
{
	int flag1 = draw_station(u8"��ѡ�����", G);
	if (flag1 == 0) return;
	int flag2 = draw_station(u8"��ѡ���յ�", G);
	if (flag2 == 0) return;
	DIJ solve;
	system("cls");
	
	int s = G.station_list[flag1].id, t = G.station_list[flag2].id;
	solve.init(s, t, G.station_list.size());
	solve.Dijkstra(G.G);
	solve.getRoad(s, t, G.station_list.size());
	cout << u8"���·����Ϊ:" << solve.dis[t] << endl;
	cout << u8"·��Ϊ:" << endl;
	for (int i = 0; i < solve.road.size();i++) {
		cout << G.station_list[G.i_station[solve.road[i]]].name << 
			((i == (solve.road.size() - 1)) ? "\n" : "->");
	}
	system("pause");
}

void query_less_path()
{
	int flag1 = draw_station(u8"��ѡ�����", G);
	if (flag1 == 0) return;
	int flag2 = draw_station(u8"��ѡ���յ�", G);
	if (flag2 == 0) return;
	less_change solve;
	system("cls");

	int s = G.station_list[flag1].id, t = G.station_list[flag2].id;
	solve.init(s, t, G.station_list.size());
	solve.bfs(s, t, G.G);
	solve.getRoad(s, t, G.station_list.size());
	if (solve.dis[t] - 1 == 0) cout << u8"���軻��" << endl;
	else cout << u8"���ٻ��˴���ΪΪ:" << solve.dis[t]-1 << endl;
	cout << u8"·��Ϊ:" << endl;
	for (int i = 0; i < solve.road.size(); i++) {
		cout << G.station_list[G.i_station[solve.road[i]]].name <<
			((i == (solve.road.size() - 1)) ? "\n" : "->");
	}
	system("pause");
}

int signin()
{
	system("cls");
	cout << u8"�������û���:" << endl;
	string username;
	cin >> username;
	if (now.check(username) == _NO_) {
		system("cls");
		cout << u8"�û�������" << endl;
		system("pause");
		return _NO_;
	}
	system("cls");
	string password;
	cout << u8"����������:" << endl;
	cin >> password;
	if (now.signin(username, password) == _OK_) {
		now_user = now.list[now.s_user[username]-1];
		return _OK_;
	}
	for (int i = 1; i <= 2; i++) {
		system("cls");
		cout << u8"��������������" << endl;
		cin >> password;
		if (now.signin(username, password) == _OK_) {
			now_user = now.list[now.s_user[username]-1];
			return _OK_;
		}
	}
	return _NO_;
}

void signup()
{
	system("cls");
	cout << u8"�������û���:" << endl;
	string username;
	cin >> username;
	if (now.check(username) == _OK_) {
		system("cls");
		cout << u8"�û��Ѵ���" << endl;
		system("pause");
		return;
	}
	system("cls");
	cout << u8"����������:" << endl;
	string password;
	cin >> password;
	system("cls");
	cout << u8"����������:" << endl;
	string name;
	cin >> name;
	system("cls");
	int sex = draw_sex();
	system("cls");
	int age;
	cout << u8"����������:" << endl;
	cin >> age;
	now.signup(username, password, name, sex, age);
	
	system("cls");
	cout << u8"ע��ɹ�\n";
	cout << u8"�û���:" << username << endl;
	cout << u8"����:" << password << endl;
	cout << u8"����:" << name << endl;
	cout << u8"�Ա�:";
	if (sex == _male)cout << u8"��" << endl;
	if (sex == _female)cout << u8"Ů" << endl;
	if (sex == _none)cout << u8"����" << endl;
	cout << u8"����:" << age << endl;
	outit();
	system("pause");
}

void add_line()
{
	system("cls");
	cout << u8"������·����:" << endl;
	string line_name;
	cin >> line_name;
	int flag = draw_station(u8"��ѡ����ʼվ", G);
	if (flag == 0) {
		system("cls");
		cout << u8"���ȡ��" << endl;
		system("pause");
		return;
	}

	G.Ins_line(line_name, G.station_list[flag]);

	int id = G.s_line[line_name];

	while (1)
	{
		int idd = G.line_list[id].list.size();
		flag = draw_station(u8"��ѡ��Ҫ��ӵ�վ����һվ"+G.line_list[id].list[idd-1].name, G);
		if (flag == 0) break;
		system("cls");
		cout << u8"������" << G.line_list[id].list[idd - 1].name << u8"��" << G.station_list[flag].name << u8"�ľ���:" << endl;
		int w;
		cin >> w;
		G.Ins_line_station(id, flag, w);
	}
	outit();
}

void del_line()
{
	int flag = draw_line(u8"��ѡ��Ҫɾ������·", G);
	if (flag == 0) return;
	G.Del_line(flag);
	outit();
}

void change_line()
{
	int flag = draw_line(u8"��ѡ��Ҫ�޸ĵ���·", G);
	if (flag == 0) return;

	string s = G.line_list[flag].name;

	flag = draw_station(u8"��ѡ����ʼվ", G);
	if (flag == 0) {
		system("cls");
		cout << u8"�޸�ȡ��" << endl;
		system("pause");
		return;
	}

	G.Del_line(flag);
	G.Ins_line(s, G.station_list[flag]);

	int id = G.s_line[s];

	while (1)
	{
		int idd = G.line_list[id].list.size();
		flag = draw_station(u8"��ѡ��Ҫ��ӵ�վ����һվ" + G.line_list[id].list[idd - 1].name, G);
		if (flag == 0) break;
		system("cls");
		cout << u8"������" << G.line_list[id].list[idd - 1].name << u8"��" << G.station_list[flag].name << u8"�ľ���:" << endl;
		int w;
		cin >> w;
		G.Ins_line_station(id, flag, w);
	}
	outit();
}

void add_station()
{
	system("cls");
	cout << u8"������Ҫ�����վ������:" << endl;
	string name;
	cin >> name;
	int flag = G.Ins_station(name);
	if (flag == 0) return;
	if (flag == _NO_) {
		system("cls");
		cout << u8"��վ�Ѵ���" << endl;
		system("pause");
		return;
	}
	else {
		system("cls");
		cout << u8"��ӳɹ�" << endl;
		outit();
		system("pause");
		return;
	}
}

void del_station()
{
	int flag = draw_station(u8"��ѡ��Ҫɾ����վ��:", G);
	if (flag == 0) return;
	if (G.Del_station(flag) == _OK_) {
		system("cls");
		cout << u8"ɾ���ɹ�" << endl;
		outit();
		system("pause");
	}
	else {
		system("cls");
		cout << u8"ɾ��ʧ��,��������·�߾�����վ��:" << endl;
		for (int i = 0; i < G.station_list[flag].pass_line.size(); i++) {
			cout << G.line_list[G.station_list[flag].pass_line[i]].name << endl;
		}
		system("pause");
	}
}

void change_station()
{
	int flag = draw_station(u8"��ѡ��Ҫ�޸ĵ�վ��:", G);
	if (flag == 0) return;
	system("cls");
	cout << u8"�������µ�վ����:" << endl;
	string s;
	cin >> s;
	if (G.change_station(flag, s) == _OK_) {
		system("cls");
		cout << u8"�޸ĳɹ�" << endl;
		outit();
		system("pause");
	}
	else {
		system("cls");
		cout << u8"վ������ͻ,�޸�ʧ��" << endl;
		system("cls");
	}
}

void change_info()
{
	while (1)
	{
		int id = now.s_user[now_user.username] - 1;
		int flag = draw_edit_user(now_user);
		if (flag == 0) {
			system("cls");
			cout << u8"�������µ�����:" << endl;
			string name;
			cin >> name;
			now.list[id].set_name(name);
		}
		else if (flag == 1) {
			int sex = draw_sex();
			now.list[id].set_sex(sex);
		}
		else if (flag == 2) {
			system("cls");
			cout << u8"�������µ�����:" << endl;
			int age;
			cin >> age;
			now.list[id].set_age(age);
		}
		else return;
		now_user = now.list[id];
	}
	outit();
}

void change_password()
{
	system("cls");
	int id = now.s_user[now_user.username] - 1;
	cout << u8"�������µ�����:" << endl;
	string password;
	cin >> password;
	now.list[id].set_password(password);
	now_user = now.list[id];
	system("cls");
	cout << u8"�޸ĳɹ�" << endl;
	outit();
}

void del_user()
{
	system("cls");
	if (now.s_user[now_user.username] - 1 == 0) {
		cout << u8"�����˻��޷�ɾ��" << endl;
		system("pause");
	}
	else {
		now.signoff(now.s_user[now_user.username] - 1);
		cout << u8"ע���ɹ�" << endl;
		outit();
		system("pause");
	}
	User tmp;
	now_user = tmp;
}

void change_admin()
{
	int flag = draw_user(u8"��ѡ��Ҫ�޸�Ȩ�޵��û�", now);
	if (flag == 0) return;
	int tmp = draw_change();
	if (tmp > 2) return;
	if (now.list[flag].set_admin(tmp, now_user.query_admin()) == _OK_) {
		system("cls");
		cout << u8"�޸ĳɹ�" << endl;
		outit();
		system("pause");
	}
	else {
		system("cls");
		cout << u8"�޸�ʧ�ܣ�Ȩ�޲���" << endl;
		system("pause");
	}
}

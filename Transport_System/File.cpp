#include "File.h"

int file_list::get_file_list(string path)
{
	intptr_t handle;
	struct _finddata_t fileinfo;
	handle = _findfirst(path.c_str(), &fileinfo);
	if (handle == -1) return -1;
	do {
		file_list.push_back(fileinfo.name);
	} while (!_findnext(handle, &fileinfo));
	_findclose(handle);
	return 0;
}

User_set File_input_User_set_AES()
{
	User_set res;
	AES solve;
	ifstream username("data\\user\\0.user");
	ifstream password("data\\user\\1.user");
	ifstream name("data\\user\\2.user");
	ifstream sex("data\\user\\3.user");
	ifstream age("data\\user\\4.user");
	ifstream admin("data\\user\\5.user");
	string un, pd, ne, sx, ae, an;
	if (username.is_open() &&
		password.is_open() &&
		name.is_open() &&
		sex.is_open() &&
		age.is_open() &&
		admin.is_open()
		)
	{
		while (username >> un) {
			password >> pd;
			name >> ne;
			sex >> sx;
			age >> ae;
			admin >> an;
			if (pd != "" &&
				ne != "" &&
				sx != "" &&
				ae != "" &&
				an != "")
			{
				un = solve.DecryptionAES(un);
				pd = solve.DecryptionAES(pd);
				ne = solve.DecryptionAES(ne);
				sx = solve.DecryptionAES(sx);
				ae = solve.DecryptionAES(ae);
				an = solve.DecryptionAES(an);
				
				res.Ins_Uesr(un, pd, ne, str_int(sx), str_int(ae),str_int(an));
			}
		}
	}
	username.close();
	password.close();
	name.close();
	sex.close();
	age.close();
	admin.close();
	return res;
}

void File_output_User_set_AES(User_set out)
{
	AES solve;
	ofstream username("data\\user\\0.user");
	ofstream password("data\\user\\1.user");
	ofstream name("data\\user\\2.user");
	ofstream sex("data\\user\\3.user");
	ofstream age("data\\user\\4.user");
	ofstream admin("data\\user\\5.user");

	for (int i = 0; i < out.list.size(); i++) {
		if (out.vis[i] == 0) continue;
		username << out.list[i].AES_username() << endl;
		password << out.list[i].AES_password() << endl;
		name << out.list[i].AES_name() << " ";
		sex << out.list[i].AES_sex() << " ";
		age << out.list[i].AES_age() << " ";
		admin << out.list[i].AES_admin() << " ";
	}
	username.close();
	password.close();
	name.close();
	sex.close();
	age.close();
	admin.close();
}

Graph_map File_input_Graph_map_AES()
{
	file_list list;
	AES solve;
	list.get_file_list("data\\line\\*.line_AES");
	Graph_map res;
	for (int i = 0; i < list.file_list.size(); i++) {
		string path = "data\\line\\" + list.file_list[i];
		ifstream line(path);
		string line_name, sname, w;
		int dis = 0;
		line >> line_name >> sname;
		line_name = solve.DecryptionAES(line_name);
		sname = solve.DecryptionAES(sname);
		res.Ins_station(sname);
		res.Ins_line(line_name, res.station_list[res.s_station[sname]]);
		while (line >> w >> sname) {
			dis = str_int(solve.DecryptionAES(w));
			sname = solve.DecryptionAES(sname);
			res.Ins_station(sname);
			res.Ins_line_station(res.s_line[line_name], res.s_station[sname], dis);
		}
		line.close();
	}
	return res;
}

void File_output_Graph_map_AES(Graph_map G)
{
	AES solve;
	for (int i = 0; i < G.line_list.size(); i++) {
		if (G.vis_line[i] == 0) continue;
		string path = "data\\line\\" + int_str(i) + ".line_AES";
		ofstream out(path);
		string tmp;
		tmp = solve.EncryptionAES(G.line_list[i].name);
		out << tmp << endl;
		tmp = solve.EncryptionAES(G.line_list[i].list[0].name);
		out << tmp << " ";
		for (int j = 1; j < G.line_list[i].list.size(); j++) {
			tmp = solve.EncryptionAES(int_str(G.line_list[i]._w[j - 1]));
			out << tmp << endl;
			tmp = solve.EncryptionAES(G.line_list[i].list[j].name);
			out << tmp << " ";
		}
		out.close();
	}
}

Graph_map File_input_Graph_map()
{
	file_list list;
	AES solve;
	list.get_file_list(u8"data\\input\\*.line");
	Graph_map res;
	for (int i = 0; i < list.file_list.size(); i++) {
		string path = "data\\input\\" + list.file_list[i];
		ifstream line(path);
		string line_name, sname;
		int dis = 0;
		line >> line_name >> sname;
		res.Ins_station(sname);
		res.Ins_line(line_name, res.station_list[res.s_station[sname]]);
		while (line >> dis >> sname) {
			res.Ins_station(sname);
			res.Ins_line_station(res.s_line[line_name], res.s_station[sname], dis);
		}
		line.close();
	}
	return res;
}

void File_output_Graph_map(Graph_map G)
{
	AES solve;
	for (int i = 0; i < G.line_list.size(); i++) {
		if (G.vis_line[i] == 0) continue;
		string path = "data\\output\\" + int_str(i) + ".line";
		ofstream out(path);
		out << G.line_list[i].name << endl;
		out << G.line_list[i].list[0].name << " ";
		for (int j = 1; j < G.line_list[i].list.size(); j++) {
			out << G.line_list[i]._w[j - 1] << endl;
			out << G.line_list[i].list[j].name << " ";
		}
		out.close();
	}
}



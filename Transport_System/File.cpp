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
	del_file del;
	del.DeleteAllFile("data\\user");
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
		name << out.list[i].AES_name() << endl;
		sex << out.list[i].AES_sex() << endl;
		age << out.list[i].AES_age() << endl;
		admin << out.list[i].AES_admin() << endl;
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
	list.get_file_list(u8"data\\line\\*.line_AES");
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
	del_file del;
	del.DeleteAllFile("data\\line");
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
	del_file del;
	del.DeleteAllFile("data\\output");
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

bool del_file::IsSpecialDir(const char* path)
{
	return strcmp(path, "..") == 0 || strcmp(path, ".") == 0;
}

bool del_file::IsDir(int attrib)
{
	return attrib == 16 || attrib == 18 || attrib == 20;
}

void del_file::ShowError(const char* file_name)
{
	errno_t err;
	_get_errno(&err);
	switch (err)
	{
	case ENOTEMPTY:
		printf("Given path is not a directory, the directory is not empty, or the directory is either the current working directory or the root directory.\n");
		break;
	case ENOENT:
		printf("Path is invalid.\n");
		break;
	case EACCES:
		printf("%s had been opend by some application, can't delete.\n", file_name);
		break;
	}
}
void del_file::GetFilePath(const char* path, const char* file_name, char* file_path)
{
	strcpy_s(file_path, sizeof(char) * _MAX_PATH, path);
	file_path[strlen(file_path) - 1] = '\0';
	strcat_s(file_path, sizeof(char) * _MAX_PATH, file_name);
}

void del_file::DeleteFile(const char* path)
{
	char pcSearchPath[_MAX_PATH];
	sprintf_s(pcSearchPath, _MAX_PATH, "%s\\*", path); //pcSearchPath 为搜索路径，* 代表通配符

	_finddata_t DirInfo; //文件夹信息
	_finddata_t FileInfo; //文件信息
	intptr_t f_handle; //查找句柄

	char pcTempPath[_MAX_PATH];
	if ((f_handle = _findfirst(pcSearchPath, &DirInfo)) != -1)
	{
		while (_findnext(f_handle, &FileInfo) == 0)
		{
			if (IsSpecialDir(FileInfo.name))
				continue;
			if (FileInfo.attrib & _A_SUBDIR)//如果是目录，生成完整的路径
			{
				GetFilePath(pcSearchPath, FileInfo.name, pcTempPath);
				DeleteFile(pcTempPath); //开始递归删除目录中的内容
				if (FileInfo.attrib == 20)
					printf("This is system file, can't delete!\n");
				else
				{
					//删除空目录，必须在递归返回前调用_findclose,否则无法删除目录
					if (_rmdir(pcTempPath) == -1)
					{
						ShowError();//目录非空则会显示出错原因
					}
				}
			}
			else
			{
				strcpy_s(pcTempPath, pcSearchPath);
				pcTempPath[strlen(pcTempPath) - 1] = '\0';
				strcat_s(pcTempPath, FileInfo.name);//生成完整的文件路径

				if (remove(pcTempPath) == -1)
				{
					ShowError(FileInfo.name);
				}

			}
		}
		_findclose(f_handle);//关闭打开的文件句柄，并释放关联资源，否则无法删除空目录
	}
	else
	{
		ShowError();//若路径不存在，显示错误信息
	}
}

void del_file::DeleteAllFile(const char* pcPath)
{
	DeleteFile(pcPath); //删除该文件夹里的所有文件
}

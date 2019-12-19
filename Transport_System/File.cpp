#include "File.h"

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
		username << out.list[i].AES_username << endl;
		password << out.list[i].AES_password << endl;
		name << out.list[i].AES_name << " ";
		sex << out.list[i].AES_sex << " ";
		age << out.list[i].AES_age << " ";
		admin << out.list[i].AES_admin << " ";
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
	
}

void File_output_Graph_map_AES(Graph_map G)
{
}

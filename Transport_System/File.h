#pragma once

#include "AES.h"
#include "Graph_map.h"
#include "User_set.h"
#include <string>
#include <fstream>
#include "base_function.h"
#include <stdio.h>
#include <io.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <direct.h>
#include <errno.h>


using namespace std;

class file_list {
public:
	vector <string> file_list;

	int get_file_list(string path);
};

class del_file {
public:
	//�ж��Ƿ���".."Ŀ¼��"."Ŀ¼
	static bool IsSpecialDir(const char* path);

	//�ж��ļ�������Ŀ¼�����ļ�
	static bool IsDir(int attrib);

	//��ʾɾ��ʧ��ԭ��
	static void ShowError(const char* file_name = NULL);

	static void GetFilePath(const char* path, const char* file_name, char* file_path);

	//�ݹ�����Ŀ¼���ļ���ɾ��
	static void DeleteFile(const char* path);


	void DeleteAllFile(const char* pcPath);
};

User_set File_input_User_set_AES();
void File_output_User_set_AES(User_set out);

Graph_map File_input_Graph_map_AES();
void File_output_Graph_map_AES(Graph_map G);

Graph_map File_input_Graph_map();
void File_output_Graph_map(Graph_map G);
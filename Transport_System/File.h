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

using namespace std;

class file_list {
public:	
	vector <string> file_list;

	int get_file_list(string path);
};

User_set File_input_User_set_AES();
void File_output_User_set_AES(User_set out);

Graph_map File_input_Graph_map_AES();
void File_output_Graph_map_AES(Graph_map G);

Graph_map File_input_Graph_map();
void File_output_Graph_map(Graph_map G);
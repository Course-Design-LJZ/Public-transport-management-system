#pragma once

#include "File.h"
#include "User_set.h"
#include "Graph_map.h"
#include "User.h"
#include "algorithm.h"
#include "flag.h"
#include "darw_choice.h"

extern Graph_map G;
extern User_set now;
extern User now_user;

void init(); 
void outit();

void infile();
void outfile();

void query_station();
void query_line();
void query_station_station();
void query_sort_path();
void query_less_path();

int signin();
void signup();

void add_line();
void del_line();
void change_line();

void add_station();
void del_station();
void change_station(); 

void change_info();
void change_password();
void del_user();
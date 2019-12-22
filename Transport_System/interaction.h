#pragma once

#include "File.h"
#include "User_set.h"
#include "Graph_map.h"
#include "User.h"
#include "algorithm.h"
#include "flag.h"
#include "darw_choice.h"

static Graph_map G;
static User_set now;
static User now_user;

void init(); 
void outit();

void infile();
void outfile();

void query_station();
void query_line();
void query_station_station();
void query_sort_path();
void query_less_path();
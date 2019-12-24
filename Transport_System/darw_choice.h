#pragma once
#include <iostream>
#include <cstdio>
#include <conio.h>
#include "Graph_map.h"
#include "User_set.h"

int draw_station(string title, Graph_map G);

int draw_line(string title, Graph_map G);

int draw_sex();

int draw_user(string title, User_set set);

int draw_edit_user(User now);

int draw_change();
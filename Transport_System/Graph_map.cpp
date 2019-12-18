#include "Graph_map.h"

int Graph_map::Ins_station(string name)
{
	if (s_station[name] != 0) {
		return _NO_;
	}
	if (station_list.size() == 0) {
		station tmp;
		station_list.push_back(tmp);
		vis_station.push_back(0);
	}

	if (!station_Available.empty()) {
		int id = station_Available.top();
		station_Available.pop();
		int tmp = G.Ins();
		station_list[id].init(name, tmp);
		s_station[name] = id;
		i_station[tmp] = id;
		vis_station[id] = 1;
	}
	else
	{
		station stmp;
		int tmp = G.Ins();
		stmp.init(name, tmp);
		station_list.push_back(stmp);
		s_station[name] = station_list.size() - 1;
		i_station[tmp] = station_list.size() - 1;
		vis_station.push_back(1);
	}
	return _OK_;
}

int Graph_map::Del_station(int id)
{
	if (station_list[id].pass_line.size() != 0) {
		return _NO_;
	}
	s_station[station_list[id].name] = 0;
	i_station[station_list[id].id] = 0;
	G.Del(station_list[id].id);
	station_Available.push(id);
	vis_station[id] = 0;
	return _OK_;
}

int Graph_map::change_station(int id, string rename)
{
	if (s_station[rename] != 0) {
		return _NO_;
	}
	s_station[station_list[id].name] = 0;
	station_list[id].name = rename;
	s_station[rename] = id;
}

int Graph_map::Ins_line(string name,station star)
{
	if (s_line[name] != 0) {
		return _NO_;
	}
	if (line_list.size() == 0) {
		line tmp;
		line_list.push_back(tmp);
		vis_line.push_back(0);
	}

	if (!line_Available.empty()) {
		int id = line_Available.top();
		line_Available.pop();
		line_list[id].init(name, id);
		s_line[name] = id;
		vis_line[id] = 1;
		line_list[id].line.push_back(star);
		line_list[id].set[star] = line_list[id].line.size();
	}
	else {
		line ltmp;
		line_list.push_back(ltmp);
		line_list[line_list.size() - 1].init(name, line_list.size() - 1);
		s_line[name] = line_list.size() - 1;
		vis_line.push_back(1);
		line_list[line_list.size() - 1].line.push_back(star);
		line_list[line_list.size() - 1].set[star] = 
			line_list[line_list.size() - 1].line.size();
	}
	return _OK_;
}

void Graph_map::Ins_line_station(int lid,int sid,int w)
{
	G.Ins_Edge(line_list[lid].line[line_list[lid].line.size() - 1].id,
		station_list[sid].id, 
		w, line_list[lid].id);
	line_list[lid].line.push_back(station_list[lid]);
	line_list[lid].set[station_list[lid]] = line_list[lid].line.size();
}

int Graph_map::Del_line(int id)
{

	return 0;
}
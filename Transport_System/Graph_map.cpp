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
	return _OK_;
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
		line_list[id].list.push_back(star);
		line_list[id].set[star.name] = line_list[id].list.size();
		station_list[s_station[star.name]].pass_line.push_back(line_list[id].id);
	}
	else {
		line ltmp;
		ltmp.init(name, line_list.size());
		line_list.push_back(ltmp);
		s_line[name] = line_list.size() - 1;
		vis_line.push_back(1);
		line_list[line_list.size() - 1].list.push_back(star);
		line_list[line_list.size() - 1].set[star.name] = 
			line_list[line_list.size() - 1].list.size();
		station_list[s_station[star.name]].pass_line.push_back(line_list[line_list.size() - 1].id);
	}
	return _OK_;
}

void Graph_map::Ins_line_station(int lid,int sid,int w)
{
	int id_1 = line_list[lid].list.size();
	G.Ins_Edge(line_list[lid].list[id_1-1].id, station_list[sid].id, w, line_list[lid].id);
	line_list[lid].list.push_back(station_list[sid]);
	line_list[lid].set[station_list[sid].name] = id_1;
	station_list[sid].pass_line.push_back(line_list[lid].id);
	station_list[sid]._line[lid] = station_list[sid].pass_line.size() - 1;
	line_list[lid]._w.push_back(w);
}

void Graph_map::Del_line(int id)
{
	for (int i = 0; i < line_list[id].list.size() - 2; i++) {
		G.Del_Edge(line_list[id].list[i].id,
			line_list[id].list[i + 1].id,
			line_list[id].id);
	}
	for (int i = 0; i < line_list[id].list.size() - 1; i++) {
		station_list[s_station[line_list[id].list[i].name]].
			pass_line.erase(
				station_list[s_station[line_list[id].list[i].name]].
				pass_line.begin() + 
				station_list[s_station[line_list[id].list[i].name]].
				_line[id]);
		station_list[s_station[line_list[id].list[i].name]]._line[id] = 0;
	}
	line_list[id].list.clear();
	line_list[id]._w.clear();
	s_line[line_list[id].name] = 0;
	vis_line[id] = 0;
	line_Available.push(id);
}

void station::init(string name, int id)
{
	this->name = name;
	this->id = id;
	this->pass_line.clear();
}

void line::init(string name, int id)
{
	this->name = name;
	this->id = id;
	this->list.clear();
	this->set.clear();
}

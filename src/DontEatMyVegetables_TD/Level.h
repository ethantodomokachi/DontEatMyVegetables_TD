#pragma once
#include <vector>

class Level {
private :
	std::vector<std::vector<char>> m_map;
	int m_wave;
public :
	Level(const char* file) {
		Load(file);
	}

	void Load(const char* file);

	int GetWave();

	void NextWave();

	std::vector<int> GetMap();

	~Level() {}
};
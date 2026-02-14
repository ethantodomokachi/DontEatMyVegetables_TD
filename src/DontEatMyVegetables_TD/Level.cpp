#include <iostream>
#include <Windows.h>
#include "Level.h"

void Level::Load(const char* file) {
	m_wave = 1;
    FILE* fp;
    errno_t e = fopen_s(&fp, file, "r");

    if (e)
    {
        return;
    }

    char buf[11];
    int i = 0;
    while (fgets(buf, sizeof buf, fp) != NULL) {
        if ((i % 2) == 0) {
            std::vector<char> tmp;
            for (int j = 0; j < 11; j++) {
                tmp.push_back(buf[j]);
            }
            m_map.push_back(tmp);
        }
        i++;
    }

    if (fclose(fp) == EOF)
    {
        return;
    }
}

int Level::GetWave() {
    return m_wave;
}

void Level::NextWave() {
    m_wave++;
}

std::vector<int> Level::GetMap() {
    std::vector<int> allTiles;
    for (int i = 0; i < m_map.size(); i++) {
        for (int j = 0; j < m_map[i].size(); j++) {
            switch (m_map[i][j]) {
            case '=' :
                //pushback de tile normale
                std::cout << "Tile normale" << std::endl;
                break;
            case '0' :
                //pushback de tile objectif
                std::cout << "Tile Objectif" << std::endl;
                break;
            case 'T' :
                std::cout << "Tile tourelle" << std::endl;
                //pushback de tile tourelle
                break;
            default :
                if (m_map[i][j] <= (char)m_wave) {
                    std::cout << "Tile chemin " << m_map[i][j] << std::endl;
                    //pushback de tile chemin
                }
                else {
                    std::cout << "Tile normale" << std::endl;
                    //pushback de tile normale
                }
            }
        }
    }

    return allTiles;
}
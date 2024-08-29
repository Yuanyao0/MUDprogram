#pragma once
#ifndef FILESTORE_H
#define FILESTORE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct GameData {
    int score;
    int level;
    std::string highScore; // ��ѡ�ĸ߷ּ�¼
    // ���������Ҫ����ı���...
};

// ���ڶ�ȡ��д����Ϸ���ݵĺ���


void saveGameData(const GameData& data, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {


        file << data.score << "\\n";
        file << data.level << "\\n";
        file << data.highScore << "\\n"; // ����и߷ּ�¼
        // д��������Ҫ����ı���...



        file.close();
        std::cout << "��Ϸ�����ѱ��档\\n";
    }
    else {
        std::cerr << "�޷����ļ����б��档\\n";
    }
}


GameData readGameData(const std::string& filename) {
    GameData data;
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> data.score;
        file >> data.level;
        file >> data.highScore; // ����и߷ּ�¼
        // ��ȡ������Ҫ����ı���...
        file.close();
        return data;
    }
    else {
        std::cerr << "�޷����ļ����ж�ȡ��\\n";
        return GameData(); // ���ؿ�����
    }
}


/*                                                  ���Ʒ���

int main() {
    GameData data;
    data.score = 12345; // ������ҵ�ǰ�÷�
    data.level = 5; // ���赱ǰ�ؿ�

    std::string filename = "save_game.txt"; // �����ļ���

    // ������Ϸ����
    saveGameData(data, filename);

    // ��ȡ��Ϸ����
    data = readGameData(filename);

    std::cout << "��ȡ�ĵ÷�: " << data.score << "\\n";
    std::cout << "��ȡ�Ĺؿ�: " << data.level << "\\n";

    return 0;
}


*/




#endif // !FILESTORE_H
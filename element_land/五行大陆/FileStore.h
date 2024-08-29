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
    std::string highScore; // 可选的高分记录
    // 添加其他需要保存的变量...
};

// 用于读取和写入游戏数据的函数


void saveGameData(const GameData& data, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {


        file << data.score << "\\n";
        file << data.level << "\\n";
        file << data.highScore << "\\n"; // 如果有高分记录
        // 写入其他需要保存的变量...



        file.close();
        std::cout << "游戏数据已保存。\\n";
    }
    else {
        std::cerr << "无法打开文件进行保存。\\n";
    }
}


GameData readGameData(const std::string& filename) {
    GameData data;
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> data.score;
        file >> data.level;
        file >> data.highScore; // 如果有高分记录
        // 读取其他需要保存的变量...
        file.close();
        return data;
    }
    else {
        std::cerr << "无法打开文件进行读取。\\n";
        return GameData(); // 返回空数据
    }
}


/*                                                  控制方法

int main() {
    GameData data;
    data.score = 12345; // 假设玩家当前得分
    data.level = 5; // 假设当前关卡

    std::string filename = "save_game.txt"; // 保存文件名

    // 保存游戏数据
    saveGameData(data, filename);

    // 读取游戏数据
    data = readGameData(filename);

    std::cout << "读取的得分: " << data.score << "\\n";
    std::cout << "读取的关卡: " << data.level << "\\n";

    return 0;
}


*/




#endif // !FILESTORE_H
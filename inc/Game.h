#ifndef GAME_H
#define GAME_H // prevent all .h files from being included more than once


#include <server.h>
#include <unordered_map>

class Game{
    std::vector<std::string> allTheWords;
    std::unordered_map<std::string, bool> theWords;

    void readWordsFile(std::string filename);
    public:
        Game();

        ucm::json generateList();
        ucm::json checkWord(std::string word);
        ucm::json solution();

        std::vector<std::string> distinctPowerset(std::string str);
        void permute(std::string a, int l, int r, std::unordered_map<std::string, bool>& results);
};

#endif
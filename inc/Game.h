#include <server.h>

class Game{
    public:
        ucm::json generateList();
        ucm::json checkWord(std::string word);
        ucm::json solution();
};
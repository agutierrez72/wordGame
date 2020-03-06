#include <server.h>

class Game{
        ucm::json list();
    public:
        ucm::json checkWord(std::string word);
        ucm::json solution();
};
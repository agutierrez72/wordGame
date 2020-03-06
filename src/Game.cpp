#include <Game.h>
#include <random>
std::vector<std::string> readWordsFile(std::string filename){
	std::ifstream file(filename);
	std::string str; 

	std::vector<std::string> words;

	while (std::getline(file, str)){
		words.push_back(boost::to_upper_copy(str));
		
	}

	return words;
}

ucm::json Game::generateList(){
    std::uniform_int_distribution<> distribution(65, 90);
    std::mt19937 gen;
    gen.seed(std::random_device()());

    ucm::json temp;

    for (int i = 0; i < 9; i++){
        temp.push_back(distribution(gen));
    }

    return temp;
}

ucm::json Game::checkWord(std::string word){
    std::vector<std::string> allTheWords = readWordsFile("misc/english.txt");
    word = boost::to_upper_copy(word);

    bool found = find(allTheWords.begin(), allTheWords.end(), word) != allTheWords.end();

    ucm::json temp;
    temp["word"] = word;
    temp["valid"] = found;
    return temp;
}
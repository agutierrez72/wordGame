#include <Game.h>

std::vector<std::string> readWordsFile(std::string filename){
	std::ifstream file(filename);
	std::string str; 

	std::vector<std::string> words;

	while (std::getline(file, str)){
		words.push_back(boost::to_upper_copy(str));
		
	}

	return words;
}

ucm::json Game::checkWord(std::string word){
    std::vector<std::string> allTheWords = readWordsFile("misc/english.txt");


    bool found = find(allTheWords.begin(), allTheWords.end(), word) != allTheWords.end();

    ucm::json temp;
    temp["word"] = word;
    temp["valid"] = found;
    return temp;
}
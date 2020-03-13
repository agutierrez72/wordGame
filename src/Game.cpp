#include <Game.h>
#include <random>
#include <algorithm>
#include <TimeSupport.h>

void Game::readWordsFile(std::string filename){
	std::ifstream file(filename);
	std::string str; 

	while (std::getline(file, str)){
        theWords.insert({boost::to_upper_copy(str), true});
		allTheWords.push_back(boost::to_upper_copy(str));
	}

}// end of readWordsFile

// At start of game read words from file
Game::Game(){
    readWordsFile("misc/english.txt");
}// end of Game constructor

ucm::json Game::generateList(){

    std::uniform_int_distribution<> distribution(65, 90);
    std::mt19937 gen;
    gen.seed(std::random_device()());

    ucm::json temp;

    for (int i = 0; i < 9; i++){
        temp.push_back(distribution(gen));
    }

    return temp;
}// end of generateList

ucm::json Game::checkWord(std::string word){
    word = boost::to_upper_copy(word);

    timestamp start = current_time();
    auto pos = theWords.find(word);

    bool found = true;
    if(pos == theWords.end()){
        found = false;
    }

    timestamp end = current_time();
    long duration = time_diff(start, end);
    std::cout << "Took: " << duration << " ms." << std::endl;

    ucm::json temp;
    temp["word"] = word;
    temp["valid"] = found;
    return temp;
}// end of checkWord

std::vector<std::string> Game::distinctPowerset(std::string str){
    if(str.size() == 0){
        std::vector<std::string> res;
        res.push_back("");

        return res;
    }
    else{
        char head = str[0];
        std::string tail;
        tail = str.substr (1,std::string::npos);

        std::vector<std::string> res = distinctPowerset(tail);
        std::vector<std::string> ans = res;

        for(auto element :res){
            std::string temp = element;
            temp.insert(temp.begin(), head);
            bool found = false;

            for(std::string curr : ans){
                if(curr == temp){
                    found = true;
                    break;
                }
                else{
                    if (curr != "" && std::is_permutation(temp.begin(), temp.end(), curr.begin())){
                        found = true;
                        break;
                    }
                }
            }

            if(!found){
                ans.push_back(temp);
            }
        }
        return ans;
    }
}// end of distinctPowerset

void Game::permute(std::string a, int l, int r, std::unordered_map<std::string, bool>& results){
    if(l == r){
        auto got = results.find(a);
        if(got == results.end()){
            results.insert({a, true});
        }
    }
    else{
        for(int i =l; i <= r; i++){
            char temp = a[l];
            a[l] = a[i];
            a[i] = temp;

            permute(a, l+r, r, results);

            temp = a[l];
            a[l] = a[i];
            a[i] = temp;
        }
    }
}// end of permute

// Helper Function
std::vector<std::string> Game::getAllPossibleSubstrings(std::string word){
    std::vector<std::string> ps = distinctPowerset(word);
    std::vector<std::string> possible;

    for(std::string item :ps){
        if(item.size() > 0){
            if(item.size() == 1){
                possible.push_back(item);
            }
            else{
                std::unordered_map<std::string, bool> curr;
                permute(item, 0, item.size()-1, curr);

                for(auto element : curr){
                    possible.push_back(element.first);
                }
            }
        }
    }
    return possible;
}// end of getAllPossibleSubstrings

std::vector<char> Game::mixup(std::string word){
    // transfer chars from string to a vector of chars
    std::vector<char> result;


    for(int i = 0; i < word.size(); i++){
        result.push_back(word[i]);
    }

    //shuffle vector of chars
    std::random_shuffle(result.begin(), result.end());
    return result;
}// end of mixup
#include <server.h>
#include <algorithm>

using namespace ucm;

std::vector<std::string> readWordsFile(std::string filename){
	std::ifstream file(filename);
	std::string str; 

	std::vector<std::string> words;

	while (std::getline(file, str)){
		words.push_back(boost::to_upper_copy(str));
		
	}

	return words;
}


int main(int argc, char** argv){

    Server server(argc, argv);

    server.renderHTML("/", "index.html");

    server.route("/list", [&](const request& req, response& res){
        json temp;
        temp.push_back(65);
        temp.push_back(66);
        temp.push_back(67);
        temp.push_back(68);
        temp.push_back(69);
        temp.push_back(70);
        temp.push_back(71);
        temp.push_back(72);
        temp.push_back(73);

        res.sendJSON(temp);
    });

    server.route("/checkWord", [&](const request& req, response& res){
        if (req.has_params({"word"})){
            std::string word = req.url_params.get("word");

            std::vector<std::string> allTheWords = readWordsFile("misc/english.txt");

            bool found = find(allTheWords.begin(), allTheWords.end(), word) != allTheWords.end();

            json temp;
            temp["word"] = word;
            temp["valid"] = found;

            res.sendJSON(temp);
        }
        else {
            res.sendError400();
        }
    });

    server.run();
}

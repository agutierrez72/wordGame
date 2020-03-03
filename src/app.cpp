#include <server.h>

using namespace ucm;


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

            json temp;
            temp["word"] = word;
            temp["valid"] = true;

            res.sendJSON(temp);
        }
    });

    server.run();
}

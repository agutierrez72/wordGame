#include <server.h>
#include <algorithm>
#include <Game.h>

using namespace ucm;

int main(int argc, char** argv){

    Server server(argc, argv);

     Game game;

    server.renderHTML("/", "index.html");

    server.route("/list", [&](const request& req, response& res){
        res.sendJSON(game.generateList());
    });

    server.route("/checkWord", [&](const request& req, response& res){
        if (req.has_params({"word"})){
            std::string word = req.url_params.get("word");

             res.sendJSON(game.checkWord(word));
        }
        else {
            res.sendError400();
        }
    });

    server.route("/solution", [&](const request& req, response& res){

    });

    server.run();
}

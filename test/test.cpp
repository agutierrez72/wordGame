#include <igloo/igloo.h>
#include <Game.h>
#include <string>
#include <algorithm>
//#include <iterator>

using namespace igloo;

Context(CheckWord){
	Game game;
	ucm::json ans;
	Spec(CheckFAisInvalid){
		ans["word"] = "FA ";
		ans["valid"] = false;
		Assert::That(game.checkWord("FA "), Equals(ans));
	};
	Spec(CheckFACisInvalid){
		ans["word"] = "FAC ";
		ans["valid"] = false;
		Assert::That(game.checkWord("FAC "), Equals(ans));
	};
	Spec(CheckTIisValid){
		ans["word"] = "TI";
		ans["valid"] = true;
		Assert::That(game.checkWord("TI"), Equals(ans));
	};
	Spec(ChecktiIsInvalid){
		ans["word"] = "TI";
		ans["valid"] = true;
		Assert::That(game.checkWord("ti"), Equals(ans));
	};
	Spec(CheckAdditionIsValid){
		ans["word"] = "ADDITION";
		ans["valid"] = true;
		Assert::That(game.checkWord("addition"), Equals(ans));
	};

};

Context(IsIntersection){
	std::string par = "MISSION";
	std::string sub1 = "NOI";
	std::string sol = "INO";
	std::string ret;
	Spec(noiIntersectsMission){
		std::sort(par.begin(), par.end());
		std::sort(sub1.begin(), sub1.end());
		std::set_intersection(sub1.begin(), sub1.end(), par.begin(), par.end(), back_inserter(ret));
		Assert::That(ret, Equals(sol));
	};
};

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}

#include <igloo/igloo.h>

#include <Game.h>

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
	Spec(CheckTIisInvalid){
		ans["word"] = "TI";
		ans["valid"] = false;
		Assert::That(game.checkWord("TI"), Equals(ans));
	};
	Spec(ChecktiIsInvalid){
		ans["word"] = "ti";
		ans["valid"] = false;
		Assert::That(game.checkWord("ti"), Equals(ans));
	};
	Spec(CheckAdditionIsValid){
		ans["word"] = "addition";
		ans["valid"] = false;
		Assert::That(game.checkWord("addition"), Equals(ans));
	};

};


int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}

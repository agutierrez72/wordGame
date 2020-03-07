#include <igloo/igloo.h>
#include <string>
#include <Game.h>
#include <algorithm>

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

// Test to check if one string is a subset of another
// Plan to use to find the solution set for 9 letter words
Context(IsPermutation){
	std::string par = "ADDITION";
	std::string sub1 = "ADD";
	Spec(addIsPAddition){
		Assert::That(std::is_permutation(par.begin(), par.end(), sub1.begin()), Equals(1));
	};
};


int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}

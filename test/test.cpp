#include <igloo/igloo.h>
#include <string>
#include <Game.h>
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

// Test to check if one string is a subset of another
// Plan to use to find the solution set for 9 letter words
// Does not work for out of order solutions such as ON -> NO
// Context(IsPermutation){
// 	std::string par = "ADDITION";
// 	std::string sub1 = "ADDIT";
// 	std::string sub2 = "ION";
// 	std::string sub3 = "NO";

	
// 	Spec(addIsPAddition){
// 		std::sort(par.begin(), par.end());
// 		std::sort(sub1.begin(), sub1.end());
// 		Assert::That(std::is_permutation(sub1.begin(), sub1.end(), par.begin()));
// 	};
// 	Spec(ionIsPAddition){
// 		std::sort(par.begin(), par.end());
// 		std::sort(sub2.begin(), sub2.end());
// 		Assert::That(boost::algorithm::contains(par, sub2));
// 	};
// 	Spec(noIsPAddition){
// 		std::sort(par.begin(), par.end());
// 		std::sort(sub3.begin(), sub3.end());
// 		Assert::That(boost::algorithm::contains(par, sub3));
// 	};
// };

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

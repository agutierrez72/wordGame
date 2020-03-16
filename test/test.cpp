#include <igloo/igloo.h>
#include <Game.h>
#include <string>
#include <algorithm>
//#include <iterator>

using namespace igloo;

// Context(CheckWord){
// 	Game game;
// 	ucm::json ans;
// 	Spec(CheckFAisInvalid){
// 		ans["word"] = "FA ";
// 		ans["valid"] = false;
// 		Assert::That(game.checkWord("FA "), Equals(ans));
// 	};
// 	Spec(CheckFACisInvalid){
// 		ans["word"] = "FAC ";
// 		ans["valid"] = false;
// 		Assert::That(game.checkWord("FAC "), Equals(ans));
// 	};
// 	Spec(CheckTIisValid){
// 		ans["word"] = "TI";
// 		ans["valid"] = true;
// 		Assert::That(game.checkWord("TI"), Equals(ans));
// 	};
// 	Spec(ChecktiIsValid){
// 		ans["word"] = "TI";
// 		ans["valid"] = true;
// 		Assert::That(game.checkWord("ti"), Equals(ans));
// 	};
// 	Spec(CheckAdditionIsValid){
// 		ans["word"] = "ADDITION";
// 		ans["valid"] = true;
// 		Assert::That(game.checkWord("Addition"), Equals(ans));
// 	};

// };
Context(TestAllSubs){
	Spec(allSubsAddition){
		Game game;
		std::string word = "addition";
		std::vector<std::string> test;
		ucm::json isWord;
		isWord["valid"] = false;
		//test = game.distinctPowerset(word);
		
		 test = game.getAllPossibleSubstrings(word);
		 for(const auto& n : test){
		 	isWord = game.checkWord(n);
		 	if(isWord["valid"] == true){
		 		std::cout << n << " ";
		 	}
		 }
		
	};
};

// Context(TestStringLength){
// 	Spec(LengthOfLittleIs6){
// 		std::string len = "Little";
// 		Assert::That(len.length(), Equals(6));
// 	};
// };

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();

}

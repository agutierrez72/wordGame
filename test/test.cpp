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
	// Spec(allSubsAddition){
	// 	Game game;
	// 	std::string word = "addition";
	// 	std::vector<std::string> test, sol;
	// 	int count;
	// 	ucm::json isWord;
	// 	isWord["valid"] = false;
		
	// 	// all possible substrings of "additon"
	// 	 test = game.getAllPossibleSubstrings(word);

	// 	// for each substring in "addition"
	// 	  for(const auto& n : test){
	// 	 		// count++;
	// 	  		// std::cout << count << ": " << n << std::endl;		
	// 	  }
	// };
	Spec(viewAllSubsAddition){
		Game game;
		std::string word = "addition";
		std::string word2 = "washingto";
		ucm::json temp, ans;
    	temp["word"];
    	temp["subwords"];
    	// for all 9 letter words
    	
        	// find all possible substrings of each 9 letter word
       		temp["word"] = word;
        	temp["subwords"] = game.getAllPossibleSubstrings(word);
        	ans.push_back(temp);
       		temp["word"] = word2;
        	temp["subwords"] = game.getAllPossibleSubstrings(word2);
        	ans.push_back(temp);
			std::cout << ans.size() << std::endl;
			auto& p = ans[0];
			auto& t = p[0];
			std::cout << t; 
    	// for(const auto& n : ans["wordList"]){
		// 	for(const auto& p : n["subwords"]){
				
		// 		std::cout << p << " " << std::endl;
		// 	}
		// }
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

//
//  main.cpp
//  TripleXGame
//
//  Created by Aleksey Glyantsev on 06.08.2020.
//  Copyright © 2020 Aleksey Glyantsev. All rights reserved.
//

#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty){
    std::cout << "\n\nYou are a janitor, that clean office at " << Difficulty << " floor";
    std::cout << "\nYou need to enter correct codes to continue you cleaning... \n\n";
}

bool PlayGame(int Difficulty) {
    
    PrintIntroduction(Difficulty);
    
    int const CodeA = rand() % Difficulty + Difficulty;
    int const CodeB = rand() % Difficulty + Difficulty;
    int const CodeC = rand() % Difficulty + Difficulty;
    
    const int CodeSum = CodeA+ CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    std::cout << "There are 3 numbers in the door code... \n";
    std::cout << "Enter it! in one line with spaces(like this 1 2 3)\n";
    std::cout << "The code add-up: " << CodeSum << "\n";
    std::cout << "The code multiply to give: " << CodeProduct << "\n";
    
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "*** That was right door code. Please, clean next floor ***\n";
            std::cout << '\n' <<R"(
        A____A
        |・ㅅ・|
        |っ　ｃ|
        |　　　|
        |　　　|
        |　　　|
        U￣￣U
        )" << '\n';
        return true;
    } else {
        std::cout << "You cant do this job. fired... \nJust a joke, try again please.\n";
        return false;
    }
}

int main() {
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    
    while (LevelDifficulty <= MaxDifficulty) {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clear any errors
        std::cin.ignore(); //discards the buffer
        
        if (bLevelComplete) {
            ++LevelDifficulty;
        }
    }
    std::cout << "Your watch has ended. Good night.\n";
    std::cout << '\n' << R"(
          .-.
         (o.o)
          |=|
         __|__
       //.=|=.\\
      // .=|=. \\
      \\ .=|=. //
       \\(_=_)//
        (:| |:)
         || ||
         () ()
         || ||
         || ||
    420 ==' '==
    )" << '\n';
    return 0;
}

#include<iostream>
#include<string>
#include <cstdlib>

using namespace std;

int main() {

    int userChoice; // get user input
    bool activate = true; // turn on the game
    char Again; // ask the user do they want to play the game or not
    int Lowerbound, Upperbound; // boundary of the result
    bool configure = false; // open the parameter configuration gate
    static bool invalid = false; // open the invalid loop gate
    bool predict = false; // open the predict mode
    bool giveUpCheck = false; // check to the user want to give up or not
    bool luckyGen = false; // Initiate the 3rd mode (generate a random number)

    // main-menu
            std::cout << "TROY HIGH LOW GAME" << endl;
            std::cout   << "1. Configure the parameter.\n" 
                        << "2. Predict the lucky number.\n"
                        << "3. Generate lucky number and view the result.\n"
                        << "4. Quit game.\n"
                        << "5. Check the upperbound & LowerBound.\n ";


   

    while(activate == true)  

    {     
            std::cout << " enter your mode choice: \n";
            cin >> userChoice;

            // get the input from user to select mode:

            userChoice = (userChoice > 1 && userChoice < 4) ? userChoice = userChoice : userChoice = static_cast<int>(userChoice); 

            /*
            if user give a decimal or a number a: 1 < a < 4 => not convert, stay still
            if give the rest -> convert to int -> compare
            */
            cin.clear();    // Clear the error state (clear the message)

            if (userChoice == 4) // Out the game
                {  
                    activate = false; // set to false - because the game on loop will not automatically stop if meet break -> undetermined loop
                    break; // break turn on the game loop
                } 

            if (userChoice == 1) // Open the mode of configuration
                {   
                    configure = true; // update the configure variable
                    std::cout << "You are in the configurator mode" << endl; 
                }
            
                while(configure == true) 
                
                {
                        // the game parameters configuration
                        std::cout << "Choose the smallest number: " << std::endl;
                        cin >> Lowerbound;
                        std::cout << "Choose the highest number: " << std::endl;
                        cin >> Upperbound;

                        Lowerbound = static_cast<int>(Lowerbound);
                        Upperbound = static_cast<int>(Upperbound);

                        if(Upperbound > Lowerbound) 
                            {
                                std::cout << "You have done the configuration !" << endl;
                                configure = false;
                                break; 
                                continue;
                            }

                        else
                            {   
                                std::cout << "You must re enter the Upperbound and/or lowerbound" << endl;
                                // Clear the cin stream.
                                cin.clear();
                                // Ignore the rest of the line.
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                }
    
            // test the value of Upperbound - LowerBound  
            if(userChoice == 5)
                {
                    cout << "you are in the checking mode" << endl;
                    cout << "Your upperbound is: " << Upperbound << endl;
                    cout << "Your lowerbound is: " << Lowerbound << endl;
                }

            // predict the lucky number mode
            if(userChoice == 2)
                {
                    std::cout << "You are in lucky prediction mode\n" << "please predict your number" << endl;
                    predict = true;
                        //prediciting process
                    while (predict == true) {

                        std::cout << "Enter your prediction !" << endl;
                        cout << "Your Lucky Number must be between " << Lowerbound << " and " << Upperbound << " !!!" << endl;
                        int yourNum;
                        cin >> yourNum;
                        yourNum = static_cast<int>(yourNum); // convert the input to the int - check the type

                        // Seed the random number generator.
                        srand(time(NULL));

                        // generate the lucky number in 2rd mode:
                        int luckyMode2 = rand() % (Upperbound - Lowerbound + 1) + Lowerbound;

                        if((yourNum > Lowerbound && yourNum < Upperbound ) || (yourNum == static_cast<int>('G') || yourNum == static_cast<int>('g') )) 
                        // check if your prediction satisfy the boundary or choosing to give up

                            {
                                if (yourNum == luckyMode2) // check if success
                                    {
                                        cout << "You're correct! Wow. \n";
                                        predict = false;
                                        break;
                                    }

                                else  //  incorrect or Give up
                                    {
                                        cout << " You're not correct" << endl;
                                        giveUpCheck = true;

                                        while(giveUpCheck != false)  
                                         {
                                            cout << " Do you want to continue the game ?" << endl;
                                            cout << " Enter Y or y for yes &  N or n for no" << endl;
                                            std::cin >> Again;
                                        
                                            if (Again == 'Y' || Again == 'y') // continue the game
                                                {   
                                                    giveUpCheck = false;
                                                    break;
                                                    continue;
                                                }
                                            else if (Again == 'N' || Again == 'n') // give up
                                                {
                                                    cin.clear(); // clear the buffer from the keyboar
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                    std::cout << "You lose, :)" << endl;
                                                    std::cout << "Your lucky number is " << luckyMode2 << endl;
                                                    giveUpCheck = false;
                                                    predict = false;
                                                    break;
                                                }
                                            else // wrong key -> reask to re-enter again
                                                {
                                                    cout << " You entered wrong keys" << endl;
                                                    continue;
                                                    
                                                }
                                         }
                                        continue; // continue the loop of prediction (for Y)                  
                                    }                         
                            }
                        else  // check if your enter invalid type
                            {
                                 std::cout << "You must re enter your prediction" << endl;
                                    // Clear the cin stream.
                                 cin.clear();
                                    // Ignore the rest of the line.
                                 cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                    }
                    
                }

            // Generate lucky number and view the result
            if(userChoice == 3) 
            {
                std::cout << "You enter the generating mode" << endl;
                luckyGen = true;

                while(luckyGen == true) 
                    {
                        int luckyGenResult = rand() % (Upperbound - Lowerbound + 1) + Lowerbound;
                        std::cout << "Your lucky number is: " << luckyGenResult << endl;
                        luckyGen = false;
                        break; // break the loop of mode 3
                    }
            }

            // Invalid mode input loop || exchange between modes
             if (userChoice != 1 || userChoice != 2 || userChoice != 3 || userChoice != 4 || userChoice != 5)
                {   
                    invalid = true;
                    while(invalid == true) 
                    {
                        std::cout << "You must re-enter the mode again - press anykey to saw the options \n\n" << endl;
                        cin.clear();   // Clear the error state (clear the message) -> to get to correct state -> (ignore invalid input)
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        std::cout    << "1. Configure the parameter.\n" 
                                     << "2. Predict the lucky number.\n"
                                     << "3. Generate lucky number and view the result.\n"
                                     << "4. Quit game.\n"
                                     << "5. Check the upperbound & LowerBound.\n ";
                        invalid = false;
                        break; // break the invalid input loop
                    }
                }        
    }

    // End the game
    std::cout << "Thank you for playing!" << endl;
    return 0;
}
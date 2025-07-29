#include <iostream>
#include <ctime>
#include <string>
#include <limits>

void announcement();
int tell_rule();
char player_make_choice();
char computer_make_choice();
void show_choice(char choice, std::string name);
char show_result(char player, char computer);
void account(char result);
void show_grade();

char player;
char computer;
char result;
int player_grade = 0;
int computer_grade = 0;

int main(){
    srand(time(NULL));
    int game_num;

    announcement();
    game_num = tell_rule();
    for(int i = 0; i < game_num; i++){
        std::cout << "this is the #" << i + 1 << " round." << '\n';
        player = player_make_choice();
        computer = computer_make_choice();
        show_choice(player, "player");
        show_choice(computer, "computer");
        result = show_result(player, computer);
        account(result);
        show_grade();
        std::cout << "---------------------------------" << '\n';
    }
    if(player_grade > computer_grade){
        std::cout << "after " << game_num << " round. you win!!!" << '\n';
    }
    else if(player_grade < computer_grade){
        std::cout << "after " << game_num << " round. you lose!!!" << '\n';
    }
    else{
        std::cout << "after " << game_num << " round. you tie!!!" << '\n';
    }
    return 0;
}

void announcement(){
    std::cout << "++++++welcome to the rock-paper-scissor game!++++++" << '\n';
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << '\n';
}
int tell_rule(){
    int game_num;
    std::cout << "'r' is rock, 'p' is paper, 's' is scissors." << '\n';
    std::cout << "win a round can earn 3 points\n"
                 "make a tie can earn 1 point\n"
                 "lose a round will earn nothing\n";
    
    
    while(true){
        std::cout << "please enter the # of round you want to play: " << '\n';
        std::cin >> game_num;
        if(std::cin){
            std::cout << "ok! you need to play " << game_num << " rounds." << '\n';
            return game_num;
        }
        else{
            std::cout << "invalid input, please try again!" << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
}
char player_make_choice(){
    char player;
    while(true){
        std::cout << "here is your term, make the choice:" << '\n';
        std::cin >> player;
        if(player == 'r' || player == 'p' || player == 's'){
                return player;
        }
        else{
            std::cout << "please enter the correct letter again." << '\n';
        }
    }
}
char computer_make_choice(){
    char computer;
    int num = rand() % 3 + 1;
    switch(num){
        case 1: computer = 'r';
            break;
        case 2: computer = 'p';
            break;
        case 3: computer = 's';
            break;
    }
    return computer;
}
void show_choice(char choice, std::string name){
    switch(choice){
        case 'r': std::cout << name << " chooses rock!" << '\n';
            break;
        case 'p': std::cout << name << " chooses paper!" << '\n';
            break;
        case 's': std::cout << name << " chooses scissors!" << '\n';
            break;
    }
}
char show_result(char player, char computer){
    char result;
    switch(player){
        case 'r': switch(computer){
                        case 'r': result = 't';
                            std::cout << "you tie." << '\n';
                            break;
                        case 'p': result = 'l';
                            std::cout << "you lose." << '\n';
                            break;
                        case 's': result = 'w';
                            std::cout << "you win." << '\n';
                            break;
                  }
            break;
        case 'p': switch(computer){
                        case 'p': result = 't';
                            std::cout << "you tie." << '\n';
                            break;
                        case 'r': result = 'w';
                            std::cout << "you win." << '\n';
                            break;
                        case 's': result = 'l';
                            std::cout << "you lose." << '\n';
                            break;
                  }
            break;
        case 's': switch(computer){
                        case 's': result = 't';
                            std::cout << "you tie." << '\n';
                            break;
                        case 'p': result = 'w';
                            std::cout << "you win." << '\n';
                            break;
                        case 'r': result = 'l';
                            std::cout << "you lose." << '\n';
                            break;
                  }
            break;
    }
    return result;
}
void account(char result){
    switch(result){
        case 't': player_grade ++, computer_grade++;
            break;
        case 'w': player_grade += 3;
            break;
        case 'l': computer_grade += 3;
            break;
    }
}
void show_grade(){
    std::cout << "the grade of the player is: " << player_grade << " !" << '\n';
    std::cout << "the grade of the computer is: " << computer_grade << " !" << '\n';
}
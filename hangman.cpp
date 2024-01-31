#include<iostream>
#include<ctime>
using namespace std;

int tries=3;
string message="you have 3 chances!";

void hangman(char);
int checkguess(char, string, string&);  


int checkguess(char guess, string real_word, string &hidden_word){
    int matches=0;
    int len = real_word.length();
    for (int i=0; i<len; i++){
        if (guess==hidden_word[i]){
            return 0;
        }
        if (guess==real_word[i]){
            hidden_word[i]=guess;
            matches++;
        }
    }
    return matches;
}

void hangman(char state){
    cout<<"\t\t\t_______________________"<<endl;
    cout<<"\t\t\t          |          |"<<endl;
    cout<<"\t\t\t          O          |"<<endl;
    cout<<"\t\t\t         / \\         |"<<"\t    "<<message<<endl;
    cout<<"\t\t\t          |          |           /"<<endl;
    cout<<"\t\t\t         / \\         |         O   "<<endl;
    cout<<"\t\t\t      =========      |        / \\    "<<endl;
    cout<<"\t\t\t      |        |     |         |    "<<endl;
    cout<<"\t\t\t      |        |     |        / \\  "<<endl;
    cout<<"\t\t\t  ========================================  "<<endl;
}

int main(){
    char letter;
    string word;
    string words[]{
        "games",
        "programming",
        "ibm",
        "friends",
        "class",
        "dreams"
    };

    srand(time(NULL));
    int word_number=rand()% 6;
    word=words[word_number];

    string hide_word(word.length(), 'X');

    system("cls");

    while (tries != 0){
        hangman('n');
        cout<<"\t\t\tLife : "<<tries<<endl;
        cout<<hide_word<<endl;
        cout<<"Guess a Letter : ";
        cin>>letter;

        system("cls");

        if (checkguess(letter, word, hide_word) == 0){
            message="Incorrect letter!";
            tries--;
        }else{
            message="Nice! Correct Guess";
        }

        if (hide_word==word)
        {
            message="You are Free!";
            hangman('f');
            cout<<"\t\t\tLife : "<<tries<<endl;
            cout<<"\t\t\tThe Word is "<<word<<endl;
            break;
        }
    }
    
    if (tries==0)
    {
        message="You're Hanged!";
        hangman('h');
        cout<<"\t\t\tLife : "<<tries<<endl;
        cout<<"\t\t\tThe Word is "<<word<<endl;
    }
    
    return 0;
}
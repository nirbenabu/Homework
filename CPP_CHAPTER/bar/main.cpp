#include<iostream>
#include "drink.hpp"
#include "Beer.hpp"
#include "barRedWines.hpp"
#include "barWhiteWines.hpp"

#if !defined (NULL)
#define NULL ((void*)0)
#endif

#define SHELF_SIZE 98

using namespace std;

void resetStock(Drink** s);
void options(Drink** s);

int main()
{
    int c;
    Drink* last = NULL;
    Drink* stock[SHELF_SIZE];

    resetStock(stock);
    // Feel free to add drinks to the stock
    stock[0] = new Beer("Heineken");
    stock[1] = new Beer("Goldstar");
    stock[2] = new Beer("Maccabi");
    stock[3] = new Beer("Tuborg");
    stock[4] = new GolanSmadar(1989);
    stock[5] = new CarmelEmeraldRiesling(1986);
    stock[6] = new YardenHermonRed(1994);
    stock[7] = new YardenSherdona(1997);
    stock[8] = new YardenCabernetSauvignon(1997);
    stock[9] = new Chianti(1997);
    stock[10] = new ChadeauMargot(1997);

    // Bar application
    cout<<"What can I get you, sir? (0 - list options)"<<endl;
    cin >> c;

    while(c!=100) {
        int i = c-1;

        if(c==0)
            options(stock);
        else if(c==99) {
            if(last == NULL)
                cout << "I didn't make you any drinks before, sir. I think you're drunk."<<endl;
            else {
                cout<<"You ordered "<<last->getName()<<"."<<endl;
                last->prepare();
            }
        }
        else if(stock[i]!=NULL) {
            cout << "One "<<stock[i]->getName() << " coming up, sir."<<endl;
            last = stock[i];
        }
        else
            cout << "No such choice, sir."<<endl;

        cout<< endl <<"What can I get you, sir? (0 - list options)"<<endl;
        cin>>c;
    }

    cout<<"Bar is closed. Good night."<<endl;

    return 0;
}


void resetStock(Drink** s) {
    for(int i = 0; i < SHELF_SIZE; i++) {
        s[i] = NULL;
    }
}

void options(Drink** s) {
    cout << "(0) list options"<<endl;

    for(int i = 0; i<SHELF_SIZE; i++) {
        if(s[i] == NULL)
            continue;
        cout << "(" << i+1 << ")\t" << s[i]->getName() << endl;
    }

    cout << "(99) How did you prepare my last drink?"<<endl;
    cout << "(100) Leave the bar"<<endl;
}

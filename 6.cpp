#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

class Card {
public:
    string suit;  // Масть
    string rank;  // Старшинство

    Card(string s, string r) : suit(s), rank(r) {}

    void display() const {
        cout << rank << " of " << suit << endl;
    }
};

class Deck {
private:
    vector<Card> deck;  

public:
    Deck() {
        string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
        string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
        for (const auto& suit : suits) {
            for (const auto& rank : ranks) {
                deck.push_back(Card(suit, rank));
            }
        }
    }

    void shuffleDeck() {
        random_device rd;
        mt19937 g(rd());
        shuffle(deck.begin(), deck.end(), g);
    }

    void dealCards() {
        for (int i = 0; i < 4; i++) {
            cout << "Игрок " << i + 1 << " получает следующие карты:" << endl;
            for (int j = 0; j < 13; j++) {
                int index = i * 13 + j;
                deck[index].display();
            }
            cout << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Deck deck;
    deck.shuffleDeck();
    deck.dealCards();

    return 0;
}


class Card {
public:
	Card(int value, Card* prev, Card* next);
	void SetNext(Card* next);
	void SetPrev(Card* prev);
	int GetValue();
	Card* GetNext();
	Card* GetPrev();

private:
	int value;
	Card* prev;
	Card* next;
};
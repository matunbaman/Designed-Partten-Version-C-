#pragma once
#include <string>

#if 0
enum HandType {
	HAND_TYPE_ROCK,
	HAND_TYPE_SCISSORS,
	HAND_TYPE_PAPER
};

class Hand {
public:
	HandType m_handvalue;
	Hand(HandType handvalue) : m_handvalue(handvalue) {}
};
Hand *g_hands[] = {
	new Hand(HandType::HAND_TYPE_ROCK),
	new Hand(HandType::HAND_TYPE_SCISSORS),
	new Hand(HandType::HAND_TYPE_PAPER)
};
#endif

class Hand {
public:
	enum HandType {
		HAND_TYPE_ROCK,
		HAND_TYPE_SCISSORS,
		HAND_TYPE_PAPER
	};
private:
	HandType m_handvalue;
	std::string m_handname[3]= {
		"Rock",
		"Scissors",
		"Paper"
	};
	Hand(HandType handvalue) : m_handvalue(handvalue) {}
	static Hand *g_hands[];
	static Hand *getHand(HandType handvalue) {
		return g_hands[handvalue];
	}
};

#include "MatamStory.h"
#include "Utilities.h"
#include <algorithm>
#include <sstream>
#include <string>

const string INVALID_PLAYERS_FILE = "Invalid Players File";
const string INVALID_EVENTS_FILE = "Invalid Events File";


const int MIN_NUMBER_OF_PLAYERS = 2;
const int MAX_NUMBER_OF_PLAYERS = 6;
const int MIN_NUMBER_OF_EVENTS = 2;
const int MIN_LENGTH_OF_NAME = 3;
const int MAX_LENGTH_OF_NAME = 15;
const int LEVEL_TO_WIN = 10;


MatamStory::MatamStory(std::istream &eventsStream, std::istream &playersStream)
        : m_turnIndex(1), jobFactory(), characterFactory(), eventFactory() {
    int playersNum = 0;
    try {
        int eventNum = 0;
        while (!eventsStream.eof()) {
            std::unique_ptr<Event> event = createEvent(eventsStream);
            if (event) {
                m_events.push_back(std::move(event));
            }
            eventNum++;
        }
        if (eventNum < MIN_NUMBER_OF_EVENTS) {
            throw std::runtime_error(INVALID_EVENTS_FILE);
        }
        while (!playersStream.eof()) {
            std::shared_ptr<Player> player = createPlayer(playersStream);
            if (player) {
                m_players.push_back(player);
                playersNum++;
            }
            if (playersNum > MAX_NUMBER_OF_PLAYERS) {
                throw std::runtime_error(INVALID_PLAYERS_FILE);
            }
        }
        if (playersNum < MIN_NUMBER_OF_PLAYERS) {
            throw std::runtime_error(INVALID_PLAYERS_FILE);
        }
        m_leaderBoard = m_players;
    } catch (const std::runtime_error &error) {
        throw error;
    }
}

std::shared_ptr<Player> MatamStory::createPlayer(std::istream &playersStream) {
    string name, jobType, characterType;
    try {
        playersStream >> name >> jobType >> characterType;
        unsigned int i;
        for (i = 0; i < name.size(); i++) {
            if (i > MAX_LENGTH_OF_NAME || name[i] < 'A' || name[i] > 'z') {
                throw std::runtime_error(INVALID_PLAYERS_FILE);
            }
        }
        if (i < MIN_LENGTH_OF_NAME) {
            throw std::runtime_error(INVALID_PLAYERS_FILE);
        }
        std::shared_ptr<Job> job = jobFactory.create(jobType);
        std::shared_ptr<Character> character = characterFactory.create(characterType);

        return std::make_shared<Player>(name, job, character);
    } catch (const std::runtime_error &error) {
        throw error;
    }

}

std::unique_ptr<Event> MatamStory::createEvent(std::istream &eventsStream) {
    try {
        return eventFactory.create(eventsStream);
    } catch (const std::runtime_error &error) {
        throw error;
    }
}


void MatamStory::playTurn(Player &player) {

    if (m_events.empty()) {
        return;
    }
    int spot = (m_turnIndex - 1) % m_events.size();
    std::unique_ptr<Event> &currentEvent = m_events[spot];

    printTurnDetails(m_turnIndex, player, *currentEvent);

    string outcome = currentEvent->playEvent(player);

    printTurnOutcome(outcome);

    m_turnIndex++;
}


void MatamStory::playRound() {

    printRoundStart();

    for (shared_ptr<Player> &player: m_players) {
        if (player->getHealthPoints() != 0) {
            playTurn(*player);
        }
    }
    /*=============================================*/
    printRoundEnd();
    std::sort(m_leaderBoard.begin(), m_leaderBoard.end(),
              [](const shared_ptr<Player> &firstPlayer,
                      const shared_ptr<Player> &secondPlayer) {
        return !(*firstPlayer < *secondPlayer);
    });
    printLeaderBoardMessage();
    int i = 1;
    for (shared_ptr<Player> &player: m_leaderBoard) {
        printLeaderBoardEntry(i++, *player);
    }


    /*=======================================================================================*/
    printBarrier();
}

bool MatamStory::isGameOver() const {
    if (hasWinner()) {
        return true;
    }
    bool allHpZeros = true;
    for (const shared_ptr<Player> &player: m_players) {
        if (player->getHealthPoints() != 0) {
            allHpZeros = false;
        }
    }
    return allHpZeros;
}

void MatamStory::play() {

    printStartMessage();
    int i = 1;
    for (shared_ptr<Player> &player: m_players) {
        printStartPlayerEntry(i++, *player);
    }

    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();

    if (hasWinner()) {
        printWinner(*getWinner());
    }
    else {
        printNoWinners();
    }

}

bool MatamStory::hasWinner() const {

    for (const auto &player: m_leaderBoard) {
        if (player->getLevel() == LEVEL_TO_WIN) {
            return true;
        }
    }
    return false;
}

std::shared_ptr<Player> MatamStory::getWinner() const {
    if (hasWinner()) {
        return m_leaderBoard[0];
    }
    return nullptr;
}


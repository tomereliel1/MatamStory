#include "MatamStory.h"
#include "Utilities.h"
#include <algorithm>
#include <sstream>
#include <string>

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
        if (eventNum < 2) {
            throw std::runtime_error("Invalid Events File");
        }
        while (!playersStream.eof()) {
            std::shared_ptr<Player> player = createPlayer(playersStream);
            if (player) {
                m_players.push_back(player);
                playersNum++;
            }
            if (playersNum > 6) {
                throw std::runtime_error("Invalid Players File");
            }
        }
        if (playersNum < 2) {
            throw std::runtime_error("Invalid Players File");
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
            if (i > 15 || name[i] < 'A' || name[i] > 'z') {
                throw std::runtime_error("Invalid Players File");
            }
        }
        if (i < 3) {
            throw std::runtime_error("Invalid Players File");
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
    std::sort(m_leaderBoard.begin(), m_leaderBoard.end(), [](const shared_ptr<Player> &firstPlayer,
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
        if (player->getLevel() == 10) {
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


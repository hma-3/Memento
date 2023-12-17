#include <iostream>
#include <string>

using namespace std;

class Memento {
public:
    Memento(const string& state) : state(state) {}

    string getState() const {
        return state;
    }

private:
    string state;
};

class Originator {
public:
    void setState(const string& state) {
        this->state = state;
    }

    Memento createMemento() const {
        return Memento(state);
    }

    void restoreFromMemento(const Memento& memento) {
        state = memento.getState();
    }

    void displayState() const {
        cout << "Current State: " << state << endl;
    }

private:
    string state;
};

int main() {
    Originator originator;

    originator.setState("State 1");
    originator.displayState();

    Memento snapshot = originator.createMemento();

    originator.setState("State 2");
    originator.displayState();

    originator.restoreFromMemento(snapshot);
    originator.displayState();

    return 0;
}

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <vector>
#include <set>
#include <map>

template<class T, class A>
class FSM
{
public:
    explicit FSM(T initialState, bool isFinalState);
    FSM(std::set<T> states, std::set<A> alphabet, std::map<std::pair<T,A>, T> transitions, T initialState, std::set<T> finalStates);
    ~FSM();
    void add_state(T state, bool isfinalState);
    void add_transition(T src, A input, T dest);
    void add_symbolToAlphabet(A input);
    void saveFSM();
    std::string readFSM(const char *filename);
    bool parseFSM(std::string str, T initialState, std::set<T> finalStates, std::string FSM);
private:
    T m_initial;
    std::set<T> m_states;
    std::set<T> m_final_states;
    std::map<T, std::pair<A,T>> m_transitions;
    std::set<A> m_alphabet;
};

#endif


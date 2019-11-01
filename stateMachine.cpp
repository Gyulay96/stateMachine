#include <iostream>
#include <fstream> 
#include <cstdio>
#include <string>
#include <utility>
#include "stateMachine.h"

template<class T, class A>
FSM<T,A>::FSM(T initialState, bool isfinalState)
{
	this->m_initial = initialState;
	add_state(initialState, isfinalState);
}

template<class T, class A>
FSM<T,A>::~FSM()
{
}

template<class T, class A>
void FSM<T,A>::add_state(T state, bool isfinalState)
{
	m_states.insert(state);
	if(isfinalState) {
	    m_final_states.insert(state);
	}
}

template<class T, class A>
void FSM<T,A>::add_transition(T src, A input, T dest)
{
    m_transitions.insert(std::make_pair(src, std::make_pair(input, dest)));
}

template<class T, class A>
void FSM<T,A>::add_symbolToAlphabet(A input)
{
    m_alphabet.insert(input);
}

template<class T, class A>
void FSM<T,A>::saveFSM()
{
    //create unique name;
    char name[L_tmpnam];
    std::ofstream ofs;
    ofs.open (name, std::ofstream::out | std::ofstream::app);
    for(auto it = m_transitions.begin(); it != m_transitions.end(); ++it)
    {
        ofs << it->first << "=>" << it->second.first << "=>" << it->second.second << "\n";
    }
    ofs.close();
}

template<class T, class A>
std::string FSM<T,A>::readFSM(const char *filename)
{
    std::string line;
    std::ifstream ifs(filename);
    if (ifs.is_open())
    {
        getline(ifs,line, char(-1));
        ifs.close();
    }
    else
        std::cout << "Unable to open file";

    return line;
}

template class FSM<int,char>;

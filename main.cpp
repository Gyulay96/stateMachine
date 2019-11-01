#include <iostream>
#include "stateMachine.h"

int main()
{
    FSM<int,char> fsm(0, false);
    fsm.add_state(1,true);
    fsm.add_transition(0,'a',1);
    fsm.add_transition(0,'b',1);
    fsm.saveFSM();
    std::string strFSM;
    strFSM = fsm.readFSM("test.txt");
    return 0;
}

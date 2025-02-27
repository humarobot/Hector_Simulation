#ifndef PASSIVE_H
#define PASSIVE_H

#include "FSMState.h"

class FSMState_Passive: public FSMState
{
    public:
        FSMState_Passive(std::shared_ptr<ControlFSMData> data);
        void enter();
        void run();
        void exit();
        FSMStateName checkTransition();
};

#endif
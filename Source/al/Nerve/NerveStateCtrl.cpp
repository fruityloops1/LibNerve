#include "al/Nerve/NerveStateCtrl.h"
#include "al/Nerve/NerveStateBase.h"

namespace al {

NerveStateCtrl::NerveStateCtrl(int capacity)
    : mCapacity(capacity)
    , mStates(new State[mCapacity])
{
    for (int i = 0; i < mCapacity; i++)
        mStates[i] = State();
}

NerveStateCtrl::~NerveStateCtrl()
{
    delete[] mStates;
}

void NerveStateCtrl::addState(NerveStateBase* state, const Nerve* nerve, const char* name)
{
    mStates[mNumStates] = { state, nerve, name };
    mNumStates++;
}

bool NerveStateCtrl::updateCurrentState()
{
    if (mCurrentState)
        return mCurrentState->mNerveState->update();
    return false;
}

void NerveStateCtrl::startState(const Nerve* nerve)
{
    mCurrentState = findStateInfo(nerve);

    if (mCurrentState)
        mCurrentState->mNerveState->appear();
}

NerveStateCtrl::State* NerveStateCtrl::findStateInfo(const Nerve* nerve)
{
    for (int i = 0; i < mNumStates; i++) {
        State* state = &mStates[i];

        if (state->mHostStateNerve == nerve)
            return state;
    }
    return nullptr;
}

bool NerveStateCtrl::isCurrentStateEnd() const
{
    if (mCurrentState)
        return mCurrentState->mNerveState->isDead();
    return false;
}

void NerveStateCtrl::tryEndCurrentState()
{
    if (mCurrentState && !isCurrentStateEnd()) {
        mCurrentState->mNerveState->kill();
        mCurrentState = nullptr;
    }
}

} // namespace al

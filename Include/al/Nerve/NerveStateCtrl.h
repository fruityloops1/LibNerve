#pragma once

namespace al {

struct Nerve;
class NerveStateBase;

class NerveStateCtrl {
    struct State {
        NerveStateBase* mNerveState = nullptr;
        const Nerve* mHostStateNerve = nullptr;
        const char* mName = nullptr;
    };

    int mCapacity = 0;
    int mNumStates = 0;
    State* mStates = nullptr;
    State* mCurrentState = nullptr;

public:
    NerveStateCtrl(int capacity);
    ~NerveStateCtrl();

    void addState(NerveStateBase* state, const Nerve* nerve, const char* name);
    bool updateCurrentState();
    void startState(const Nerve* nerve);
    State* findStateInfo(const Nerve* nerve);
    void tryEndCurrentState();
    bool isCurrentStateEnd() const;
};

} // namespace al

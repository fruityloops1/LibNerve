#include "al/Nerve/NerveUtil.h"
#include "al/Nerve/NerveKeeper.h"
#include "al/Nerve/NerveStateBase.h"
#include "al/Nerve/NerveStateCtrl.h"

namespace al {

void setNerve(IUseNerve* user, const Nerve* nerve)
{
    user->getNerveKeeper()->setNerve(nerve);
}

void setNerveAtStep(IUseNerve* user, const Nerve* nerve, int step)
{
    if (isStep(user, step))
        setNerve(user, nerve);
}

bool isStep(const IUseNerve* user, int step)
{
    return getNerveStep(user) == step;
}

bool isNerve(const IUseNerve* user, const Nerve* nerve)
{
    return getNerve(user) == nerve;
}

int getNerveStep(const IUseNerve* user)
{
    return user->getNerveKeeper()->getStep();
}

const Nerve* getNerve(const IUseNerve* user)
{
    return user->getNerveKeeper()->getCurrentNerve();
}

bool isFirstStep(const IUseNerve* user)
{
    return isStep(user, 0);
}

bool isLessStep(const IUseNerve* user, int than)
{
    return getNerveStep(user) < than;
}

bool isLessEqualStep(const IUseNerve* user, int than)
{
    return getNerveStep(user) <= than;
}

bool isGreaterStep(const IUseNerve* user, int than)
{
    return getNerveStep(user) > than;
}

bool isGreaterEqualStep(const IUseNerve* user, int than)
{
    return getNerveStep(user) >= than;
}

bool isIntervalStep(const IUseNerve* user, int interval, int offset)
{
    int adjustedStep = getNerveStep(user) - offset;
    int quotient = 0;

    if (interval != 0)
        quotient = adjustedStep / interval;

    return adjustedStep == quotient * interval;
}

bool isIntervalOnOffStep(const IUseNerve* user, int interval, int offset)
{
    int step = getNerveStep(user);
    int adjustedStep = 0;
    if (interval != 0)
        adjustedStep = (step - offset) / interval;
    return adjustedStep % 2 == 0;
}

bool isNewNerve(const IUseNerve* user)
{
    return user->getNerveKeeper()->isNewNerve();
}

void initNerveState(IUseNerve* user, NerveStateBase* state, const Nerve* hostStateNerve, const char* name)
{
    state->init();
    addNerveState(user, state, hostStateNerve, name);
}

void addNerveState(IUseNerve* user, NerveStateBase* state, const Nerve* hostStateNerve, const char* name)
{
    user->getNerveKeeper()->getStateCtrl()->addState(state, hostStateNerve, name);
}

bool updateNerveState(IUseNerve* user)
{
    return user->getNerveKeeper()->getStateCtrl()->updateCurrentState();
}

bool updateNerveStateAndNextNerve(IUseNerve* user, const Nerve* nerve)
{
    bool died = updateNerveState(user);
    if (died)
        setNerve(user, nerve);
    return died;
}

bool isStateEnd(const IUseNerve* user)
{
    return user->getNerveKeeper()->getStateCtrl()->isCurrentStateEnd();
}

} // namespace al

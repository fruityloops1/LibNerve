#include "al/Nerve/NerveStateBase.h"

namespace al {

NerveStateBase::NerveStateBase(const char* name)
    : NerveExecutor(name)
{
}

void NerveStateBase::init() { }
void NerveStateBase::appear() { mIsDead = false; }
void NerveStateBase::kill() { mIsDead = true; }
bool NerveStateBase::update()
{
    updateNerve();

    if (!mIsDead) {
        control();
        return false;
    }

    return true;
}
void NerveStateBase::control() { }

} // namespace al

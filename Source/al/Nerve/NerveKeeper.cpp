#include "al/Nerve/NerveKeeper.h"
#include "al/Nerve/Nerve.h"
#include "al/Nerve/NerveStateCtrl.h"

namespace al {

NerveKeeper::NerveKeeper(IUseNerve* host, const Nerve* initNerve, int nerveStateCapacity)
    : mHost(host)
    , mNextNerve(initNerve)
{
    if (nerveStateCapacity > 0)
        mStateCtrl = new NerveStateCtrl(nerveStateCapacity);
}

NerveKeeper::~NerveKeeper()
{
    if (mStateCtrl)
        delete mStateCtrl;
}

void NerveKeeper::update()
{
    tryChangeNerve();
    mCurrentNerve->execute(this);
    mStep++;
    tryChangeNerve();
}

void NerveKeeper::tryChangeNerve()
{
    if (mNextNerve == nullptr)
        return;
    if (mStateCtrl) {
        mStateCtrl->tryEndCurrentState();
        mStateCtrl->startState(mNextNerve);
    }

    mCurrentNerve = mNextNerve;
    mStep = 0;
    mNextNerve = nullptr;
}

void NerveKeeper::setNerve(const Nerve* nerve)
{
    if (mStep > -1 && mCurrentNerve)
        mCurrentNerve->executeOnEnd(this);
    mNextNerve = nerve;
    mStep = -1;
}

const Nerve* NerveKeeper::getCurrentNerve() const
{
    return mNextNerve ? mNextNerve : mCurrentNerve;
}

} // namespace al

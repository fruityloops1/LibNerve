#include "al/Nerve/NerveExecutor.h"
#include "al/Nerve/NerveKeeper.h"

namespace al {

NerveExecutor::NerveExecutor(const char* name) { }

NerveExecutor::~NerveExecutor()
{
    if (mNerveKeeper)
        delete mNerveKeeper;
}

NerveKeeper* NerveExecutor::getNerveKeeper() const { return mNerveKeeper; }

void NerveExecutor::initNerve(const Nerve* nerve, int maxNerveStates)
{
    mNerveKeeper = new NerveKeeper(this, nerve, maxNerveStates);
}

void NerveExecutor::updateNerve()
{
    if (mNerveKeeper)
        mNerveKeeper->update();
}

} // namespace al

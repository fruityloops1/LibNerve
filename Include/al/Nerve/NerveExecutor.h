#pragma once

#include "al/Nerve/NerveKeeper.h"

namespace al {

class NerveKeeper;

class NerveExecutor : public IUseNerve {
    NerveKeeper* mNerveKeeper = nullptr;

public:
    NerveExecutor(const char* name);
    virtual ~NerveExecutor();

    NerveKeeper* getNerveKeeper() const override;

    void initNerve(const Nerve* nerve, int nerveStateCapacity = 0);
    void updateNerve();
};

} // namespace al

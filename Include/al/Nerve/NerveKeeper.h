#pragma once

namespace al {

struct Nerve;
class IUseNerve;
class NerveStateCtrl;
class NerveActionCtrl;

class NerveKeeper {
    IUseNerve* mHost = nullptr;
    const Nerve* mCurrentNerve = nullptr;
    const Nerve* mNextNerve = nullptr;
    int mStep = 0;
    NerveStateCtrl* mStateCtrl = nullptr;

public:
    NerveKeeper(IUseNerve* host, const Nerve* initNerve, int nerveStateCapacity = 0);
    ~NerveKeeper();

    void update();
    void tryChangeNerve();
    void setNerve(const Nerve* nerve);
    const Nerve* getCurrentNerve() const;

    IUseNerve* getHost() const { return mHost; }
    int getStep() const { return mStep; }
    NerveStateCtrl* getStateCtrl() const { return mStateCtrl; }
    bool isNewNerve() const { return mNextNerve != nullptr; }
};

class IUseNerve {
public:
    virtual NerveKeeper* getNerveKeeper() const = 0;
};

} // namespace al

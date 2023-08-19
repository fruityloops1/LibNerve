#pragma once

#include "al/Nerve/NerveExecutor.h"

namespace al {

class NerveStateBase : public NerveExecutor {
    bool mIsDead = true;

public:
    NerveStateBase(const char* name);

    virtual void init();
    virtual void appear();
    virtual void kill();
    virtual bool update();
    virtual void control();

    bool isDead() const { return mIsDead; }
};

template <typename T>
class HostStateBase : public NerveStateBase {
protected:
    T* const mHost = nullptr;

public:
    HostStateBase(T* host, const char* name)
        : NerveStateBase(name)
        , mHost(host)
    {
    }
};

} // namespace al

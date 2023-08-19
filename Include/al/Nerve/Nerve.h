#pragma once

namespace al {

class NerveKeeper;

struct Nerve {
    virtual void execute(NerveKeeper* parent) const = 0;
    virtual void executeOnEnd(NerveKeeper* parent) const {};
};

#define NERVE_DEF(HostType, Action)                                   \
    struct HostType##Nrv##Action : ::al::Nerve {                      \
        void execute(::al::NerveKeeper* parent) const override        \
        {                                                             \
            static_cast<HostType*>(parent->getHost())->exe##Action(); \
        }                                                             \
    };                                                                \
    const static HostType##Nrv##Action nrv##HostType##Action;

#define NERVE_DEF_END(HostType, Action)                                    \
    struct HostType##Nrv##Action : ::al::Nerve {                           \
        void execute(::al::NerveKeeper* parent) const override             \
        {                                                                  \
            static_cast<HostType*>(parent->getHost())->exe##Action();      \
        }                                                                  \
        void executeOnEnd(::al::NerveKeeper* parent) const override        \
        {                                                                  \
            static_cast<HostType*>(parent->getHost())->exe##Action##End(); \
        }                                                                  \
    };                                                                     \
    const static HostType##Nrv##Action nrv##HostType##Action;

} // namespace al

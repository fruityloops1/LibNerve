#pragma once

namespace al {

struct Nerve;
class IUseNerve;
class NerveStateBase;

void setNerve(IUseNerve* user, const Nerve* nerve);
void setNerveAtStep(IUseNerve* user, const Nerve* nerve, int step);
bool isStep(const IUseNerve* user, int step);
bool isNerve(const IUseNerve* user, const Nerve* nerve);
int getNerveStep(const IUseNerve* user);
const Nerve* getNerve(const IUseNerve* user);
bool isFirstStep(const IUseNerve* user);
bool isLessStep(const IUseNerve* user, int than);
bool isLessEqualStep(const IUseNerve* user, int than);
bool isGreaterStep(const IUseNerve* user, int than);
bool isGreaterEqualStep(const IUseNerve* user, int than);
bool isIntervalStep(const IUseNerve* user, int interval, int offset = 0);
bool isIntervalOnOffStep(const IUseNerve* user, int interval, int offset = 0);
bool isNewNerve(const IUseNerve* user);
// float calcNerveRate(const IUseNerve* user, int);
// float calcNerveRate(const IUseNerve* user, int, int);
// float calcNerveEaseInRate(const IUseNerve* user, int);
// float calcNerveEaseInRate(const IUseNerve* user, int, int);
// float calcNerveEaseOutRate(const IUseNerve* user, int);
// float calcNerveEaseOutRate(const IUseNerve* user, int, int);
// float calcNerveEaseInOutRate(const IUseNerve* user, int);
// float calcNerveEaseInOutRate(const IUseNerve* user, int, int);
// float calcNerveSquareInRate(const IUseNerve* user, int);
// float calcNerveSquareInRate(const IUseNerve* user, int, int);
// float calcNerveSquareOutRate(const IUseNerve* user, int);
// float calcNerveSquareOutRate(const IUseNerve* user, int, int);
// float calcNerveValue(const IUseNerve* user, int, float, float);
// float calcNerveValue(const IUseNerve* user, int, int, float, float);
// float calcNerveEaseInValue(const IUseNerve* user, int, float, float);
// float calcNerveEaseInValue(const IUseNerve* user, int, int, float, float);
// float calcNerveEaseOutValue(const IUseNerve* user, int, float, float);
// float calcNerveEaseOutValue(const IUseNerve* user, int, int, float, float);
// float calcNerveSquareInValue(const IUseNerve* user, int, float, float);
// float calcNerveSquareInValue(const IUseNerve* user, int, int, float, float);
// float calcNerveSquareOutValue(const IUseNerve* user, int, float, float);
// float calcNerveSquareOutValue(const IUseNerve* user, int, int, float, float);
// float calcNerveJumpValue(IUseNerve* user, int, int, int, float);
void initNerveState(IUseNerve* user, NerveStateBase* state, const Nerve* hostStateNerve, const char* name);
void addNerveState(IUseNerve* user, NerveStateBase* state, const Nerve* hostStateNerve, const char* name);
bool updateNerveState(IUseNerve* user);
bool updateNerveStateAndNextNerve(IUseNerve* user, const Nerve* nerve);
bool isStateEnd(const IUseNerve* user);

} // namespace al

#include "Entry.h"

#include <ll/api/memory/Hook.h>
#include <ll/api/mod/RegisterHelper.h>
#include <mc/world/level/storage/LevelData.h>

LL_AUTO_TYPE_INSTANCE_HOOK(LevelDataCtorHook, ll::memory::HookPriority::Normal,
                           LevelData,
                           &LevelData::achievementsWillBeDisabledOnLoad, bool)
{
    const auto& logger =
        mfa::MForceAchievements::getInstance().getSelf().getLogger();
    logger.debug("Hooked &LevelData::achievementsWillBeDisabledOnLoad");
    if (getGameType() == GameType::Creative) setGameType(GameType::Survival);
    ll::memory::dAccess<bool>(this, 1284) = false;
    ll::memory::dAccess<bool>(this, 1324) = false;
    ll::memory::dAccess<bool>(this, 1325) = false;
    return false;
}

namespace mfa
{

MForceAchievements& MForceAchievements::getInstance()
{
    static MForceAchievements instance;
    return instance;
}

bool MForceAchievements::load() const
{
    const auto& logger = getSelf().getLogger();
    logger.debug("Loading...");

    return true;
}

bool MForceAchievements::enable() const
{
    const auto& logger = getSelf().getLogger();
    logger.debug("Starting up...");

    return true;
}

bool MForceAchievements::disable() const
{
    const auto& logger = getSelf().getLogger();
    logger.debug("Disabling...");

    return true;
}

}  // namespace mfa

LL_REGISTER_MOD(mfa::MForceAchievements,
                mfa::MForceAchievements::getInstance());

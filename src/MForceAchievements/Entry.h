#pragma once

#include <ll/api/mod/NativeMod.h>

namespace mfa
{

class MForceAchievements
{
public:
    static MForceAchievements& getInstance();

    MForceAchievements() : mSelf(*ll::mod::NativeMod::current()) {}

    [[nodiscard]] ll::mod::NativeMod& getSelf() const { return mSelf; }

    /// @return True if the mod is loaded successfully.
    bool load() const;

    /// @return True if the mod is enabled successfully.
    bool enable() const;

    /// @return True if the mod is disabled successfully.
    bool disable() const;

private:
    ll::mod::NativeMod& mSelf;
};

}  // namespace mfa

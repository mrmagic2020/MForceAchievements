#include "MSeries/Entry.h"

#include <ll/api/mod/RegisterHelper.h>

#include "i18n.h"

namespace mseries
{

MSeries& MSeries::getInstance()
{
    static MSeries instance;
    return instance;
}

bool MSeries::load() const
{
    const auto& logger = getSelf().getLogger();
    logger.debug("Loading...");

    if (!i18n::init()) return false;

    return true;
}

bool MSeries::enable() const
{
    const auto& logger = getSelf().getLogger();
    logger.debug("Starting up...");

    return true;
}

bool MSeries::disable() const
{
    const auto& logger = getSelf().getLogger();
    logger.debug("Disabling...");

    return true;
}

bool MSeries::unload() const
{
    const auto& logger = getSelf().getLogger();
    logger.debug("Unloading...");

    return true;
}

}  // namespace mseries

LL_REGISTER_MOD(mseries::MSeries, mseries::MSeries::getInstance());

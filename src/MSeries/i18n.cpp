#include "i18n.h"

#include <ll/api/i18n/I18n.h>

#include "Entry.h"

namespace mseries::i18n
{
bool init()
{
    const auto& logger = MSeries::getInstance().getSelf().getLogger();

    const auto res = ll::i18n::getInstance().load(
        MSeries::getInstance().getSelf().getLangDir());
    if (!res)
    {
        logger.error("Failed to load i18n.");
        return false;
    }

    logger.debug("i18n loaded.");
    return true;
}
}  // namespace mseries::i18n
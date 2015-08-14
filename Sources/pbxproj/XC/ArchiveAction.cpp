// Copyright 2013-present Facebook. All Rights Reserved.

#include <pbxproj/XC/ArchiveAction.h>

using pbxproj::XC::ArchiveAction;

ArchiveAction::ArchiveAction() :
    _revealArchiveInOrganizer(false)
{
}

bool ArchiveAction::
parse(plist::Dictionary const *dict)
{
    if (!Action::parse(dict))
        return false;

    auto RAIO = dict->value <plist::Boolean> ("revealArchiverInOrganize");
    
    if (RAIO != nullptr) {
        _revealArchiveInOrganizer = RAIO->value();
    }

    return true;
}

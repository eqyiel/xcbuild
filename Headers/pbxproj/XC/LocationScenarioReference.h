// Copyright 2013-present Facebook. All Rights Reserved.

#ifndef __pbxproj_XC_LocationScenarioReference_h
#define __pbxproj_XC_LocationScenarioReference_h

#include <pbxproj/Base.h>

namespace pbxproj { namespace XC {

class LocationScenarioReference {
public:
    typedef std::shared_ptr <LocationScenarioReference> shared_ptr;

private:
    std::string _identifier;
    uint32_t    _referenceType;

public:
    LocationScenarioReference();

public:
    inline std::string const &identifier() const
    { return _identifier; }

public:
    inline uint32_t referenceType() const
    { return _referenceType; }

public:
    bool parse(plist::Dictionary const *dict);
};

} }

#endif  // !__pbxproj_XC_LocationScenarioReference_h

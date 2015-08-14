// Copyright 2013-present Facebook. All Rights Reserved.

#ifndef __pbxproj_PBX_TargetDependency_h
#define __pbxproj_PBX_TargetDependency_h

#include <pbxproj/PBX/FileReference.h>

namespace pbxproj { namespace PBX {

// Avoid circular dependencies
class Target;
class ContainerItemProxy;

class TargetDependency : public Object {
public:
    typedef std::shared_ptr <TargetDependency> shared_ptr;
    typedef std::vector <shared_ptr> vector;

private:
    std::shared_ptr <Target>             _target;
    std::shared_ptr <ContainerItemProxy> _targetProxy;

public:
    TargetDependency();

public:
    inline std::shared_ptr <Target> const &target() const
    { return _target; }
    inline std::shared_ptr <Target> &target()
    { return _target; }

public:
    inline std::shared_ptr <ContainerItemProxy> const &targetProxy() const
    { return _targetProxy; }
    inline std::shared_ptr <ContainerItemProxy> &targetProxy()
    { return _targetProxy; }

public:
    bool parse(Context &context, plist::Dictionary const *dict);

public:
    static inline char const *Isa()
    { return ISA::PBXTargetDependency; }
};

} }

#endif  // !__pbxproj_PBX_TargetDependency_h

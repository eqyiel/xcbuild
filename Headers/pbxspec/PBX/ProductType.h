// Copyright 2013-present Facebook. All Rights Reserved.

#ifndef __pbxspec_PBX_ProductType_h
#define __pbxspec_PBX_ProductType_h

#include <pbxspec/PBX/Specification.h>

namespace pbxspec { namespace PBX {

class ProductType : public Specification {
public:
    typedef std::shared_ptr <ProductType> shared_ptr;
    typedef std::vector <shared_ptr> vector;

protected:
    std::string             _defaultTargetName;
    plist::Dictionary      *_defaultBuildProperties;
    plist::Dictionary      *_validation;
    libutil::string_vector  _packageTypes;
    std::string             _iconNamePrefix;
    bool                    _hasInfoPlist;
    bool                    _hasInfoPlistStrings;
    bool                    _isWrapper;
    bool                    _supportsZeroLink;
    bool                    _alwaysPerformSeparateStrip;

protected:
    ProductType(bool isDefault);
    ProductType(bool isDefault, std::string const &isa);

public:
    virtual ~ProductType();

public:
    inline char const *type() const override
    { return ProductType::Type(); }

public:
    inline ProductType::shared_ptr const &base() const
    { return reinterpret_cast <ProductType::shared_ptr const &> (Specification::base()); }

public:
    inline std::string const &defaultTargetName() const
    { return _defaultTargetName; }

public:
    inline plist::Dictionary const *defaultBuildProperties() const
    { return _defaultBuildProperties; }

public:
    inline plist::Dictionary const *validation() const
    { return _validation; }

public:
    inline libutil::string_vector const &packageTypes() const
    { return _packageTypes; }

public:
    inline std::string const &iconNamePrefix() const
    { return _iconNamePrefix; }

public:
    inline bool hasInfoPlist() const
    { return _hasInfoPlist; }
    inline int hasInfoPlistStrings() const
    { return _hasInfoPlistStrings; }

public:
    inline bool isWrapper() const
    { return _isWrapper; }

public:
    inline bool supportsZeroLink() const
    { return _supportsZeroLink; }

public:
    inline bool alwaysPerformSeparateStrip() const
    { return _alwaysPerformSeparateStrip; }

protected:
    friend class Specification;
    bool parse(plist::Dictionary const *dict) override;

protected:
    bool inherit(Specification::shared_ptr const &base) override;
    virtual bool inherit(ProductType::shared_ptr const &base);

protected:
    static ProductType::shared_ptr Parse(plist::Dictionary const *dict);

public:
    static inline char const *Isa()
    { return ISA::PBXProductType; }
    static inline char const *Type()
    { return Types::ProductType; }
};

} }

#endif  // !__pbxspec_PBX_ProductType_h

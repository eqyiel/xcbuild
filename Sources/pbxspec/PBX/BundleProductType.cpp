// Copyright 2013-present Facebook. All Rights Reserved.

#include <pbxspec/PBX/BundleProductType.h>

using pbxspec::PBX::BundleProductType;

BundleProductType::BundleProductType(bool isDefault) :
    ProductType(isDefault, ISA::PBXBundleProductType)
{
}

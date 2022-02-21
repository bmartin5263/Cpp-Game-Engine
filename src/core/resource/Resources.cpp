//
// Created by Brandon on 2/20/22.
//

#include "Resources.h"

ResourcesImpl &Resources::instance() {
    static ResourcesImpl ri;
    return ri;
}

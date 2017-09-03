#ifndef XOLOTL_CORE_REACTANTTYPE_H_
#define XOLOTL_CORE_REACTANTTYPE_H_

#include <string>

#include "Species.h"

namespace xolotlCore {

// TODO Don't like having to define ReactantTypes for all types of
// ReactionNetworks here.  Would prefer that the ReactantTypes are
// defined in the the derived ReactionNetwork subdirectories,
// so that ReactionNetworks can define those for only those that
// it knows about.
//
// C++ doesn't support derivation of enum classes, such that we
// could define a base set of ReactantTypes and then extend it
// by the specific types of reaction networks.
//
// Since Reactant keeps its own type, and the other parts of the code
// also use these reactant types without distinguishing whether they
// have a PSIClusterReactionNetwork or NEClusterReactionNetwork,
// and because support for both types of reaction entworks is always built,
// for now we're stuck defining all potential reactant types in this shared
// enum.
//
// We could finesse the problem using preprocessor tricks, e.g., by
// including a file from the psiclusters and neclusters directories
// in the appropriate place in the enum definition.
//
// Note: do not assume that the values of these enums correspond to
// those in the Species enum.
//
enum class ReactantType {
    // Common Reactant types.
    Invalid = -1,
    V,
    I,

    // Reactant types for PSI networks
    He,
    HeV,
    HeI,
    PSISuper,

    // Reactant types for NE networks
    Xe,
    XeV,
    XeI,
    NESuper
};

std::string toString(ReactantType rtype);

Species toSpecies(ReactantType rtype);

} // namespace xolotlCore

#endif /* XOLOTL_CORE_REACTANTTYPE_H_ */
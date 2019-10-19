

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Enum.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef Enum_2007232608_hpp
#define Enum_2007232608_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

struct BasicEnum_def {
    enum type {
        A,      
        B,      
        C     
    };
    static type get_default(){ return A;}
};

typedef dds::core::safe_enum<BasicEnum_def> BasicEnum;
NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const BasicEnum& sample);
struct MixedEnum_def {
    enum type {
        X = 2,      
        Z = 4,      
        Y = 10     
    };
    static type get_default(){ return X;}
};

typedef dds::core::safe_enum<MixedEnum_def> MixedEnum;
NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const MixedEnum& sample);
struct NegativeEnum_def {
    enum type {
        K = -20,      
        L = -2,      
        M = 0     
    };
    static type get_default(){ return K;}
};

typedef dds::core::safe_enum<NegativeEnum_def> NegativeEnum;
NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const NegativeEnum& sample);

class NDDSUSERDllExport Enums {

  public:
    Enums();

    Enums(
        const BasicEnum& basic,
        const MixedEnum& mixed,
        const NegativeEnum& negative);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    Enums (Enums&&) = default;
    Enums& operator=(Enums&&) = default;
    Enums& operator=(const Enums&) = default;
    Enums(const Enums&) = default;
    #else
    Enums(Enums&& other_) OMG_NOEXCEPT;  
    Enums& operator=(Enums&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    BasicEnum& basic() OMG_NOEXCEPT; 
    const BasicEnum& basic() const OMG_NOEXCEPT;
    void basic(const BasicEnum& value);

    MixedEnum& mixed() OMG_NOEXCEPT; 
    const MixedEnum& mixed() const OMG_NOEXCEPT;
    void mixed(const MixedEnum& value);

    NegativeEnum& negative() OMG_NOEXCEPT; 
    const NegativeEnum& negative() const OMG_NOEXCEPT;
    void negative(const NegativeEnum& value);

    bool operator == (const Enums& other_) const;
    bool operator != (const Enums& other_) const;

    void swap(Enums& other_) OMG_NOEXCEPT ;

  private:

    BasicEnum m_basic_;
    MixedEnum m_mixed_;
    NegativeEnum m_negative_;

};

inline void swap(Enums& a, Enums& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Enums& sample);

namespace dds { 
    namespace topic {

        template<>
        struct topic_type_name<Enums> {
            NDDSUSERDllExport static std::string value() {
                return "Enums";
            }
        };

        template<>
        struct is_topic_type<Enums> : public dds::core::true_type {};

        template<>
        struct topic_type_support<Enums> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const Enums& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(Enums& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(Enums& sample);

            NDDSUSERDllExport 
            static void allocate_sample(Enums& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {
        template<>
        struct dynamic_type<BasicEnum> {
            typedef dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility<BasicEnum> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<MixedEnum> {
            typedef dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility<MixedEnum> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<NegativeEnum> {
            typedef dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility<NegativeEnum> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<Enums> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<Enums> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // Enum_2007232608_hpp


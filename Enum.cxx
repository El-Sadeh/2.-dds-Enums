

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Enum.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "Enum.hpp"
#include "EnumPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

std::ostream& operator << (std::ostream& o,const BasicEnum& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    switch(sample.underlying()){
        case BasicEnum::A:
        o << "BasicEnum::A" << " ";
        break;
        case BasicEnum::B:
        o << "BasicEnum::B" << " ";
        break;
        case BasicEnum::C:
        o << "BasicEnum::C" << " ";
        break;
    }
    return o;
}
std::ostream& operator << (std::ostream& o,const MixedEnum& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    switch(sample.underlying()){
        case MixedEnum::X:
        o << "MixedEnum::X" << " ";
        break;
        case MixedEnum::Z:
        o << "MixedEnum::Z" << " ";
        break;
        case MixedEnum::Y:
        o << "MixedEnum::Y" << " ";
        break;
    }
    return o;
}
std::ostream& operator << (std::ostream& o,const NegativeEnum& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    switch(sample.underlying()){
        case NegativeEnum::K:
        o << "NegativeEnum::K" << " ";
        break;
        case NegativeEnum::L:
        o << "NegativeEnum::L" << " ";
        break;
        case NegativeEnum::M:
        o << "NegativeEnum::M" << " ";
        break;
    }
    return o;
}

// ---- Enums: 

Enums::Enums() :
    m_basic_(BasicEnum::get_default()) ,
    m_mixed_(MixedEnum::get_default()) ,
    m_negative_(NegativeEnum::get_default())  {
}   

Enums::Enums (
    const BasicEnum& basic,
    const MixedEnum& mixed,
    const NegativeEnum& negative)
    :
        m_basic_( basic ),
        m_mixed_( mixed ),
        m_negative_( negative ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
Enums::Enums(Enums&& other_) OMG_NOEXCEPT  :m_basic_ (std::move(other_.m_basic_))
,
m_mixed_ (std::move(other_.m_mixed_))
,
m_negative_ (std::move(other_.m_negative_))
{
} 

Enums& Enums::operator=(Enums&&  other_) OMG_NOEXCEPT {
    Enums tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void Enums::swap(Enums& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_basic_, other_.m_basic_);
    swap(m_mixed_, other_.m_mixed_);
    swap(m_negative_, other_.m_negative_);
}  

bool Enums::operator == (const Enums& other_) const {
    if (m_basic_ != other_.m_basic_) {
        return false;
    }
    if (m_mixed_ != other_.m_mixed_) {
        return false;
    }
    if (m_negative_ != other_.m_negative_) {
        return false;
    }
    return true;
}
bool Enums::operator != (const Enums& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
BasicEnum& Enums::basic() OMG_NOEXCEPT {
    return m_basic_;
}

const BasicEnum& Enums::basic() const OMG_NOEXCEPT {
    return m_basic_;
}

void Enums::basic(const BasicEnum& value) {
    m_basic_ = value;
}

MixedEnum& Enums::mixed() OMG_NOEXCEPT {
    return m_mixed_;
}

const MixedEnum& Enums::mixed() const OMG_NOEXCEPT {
    return m_mixed_;
}

void Enums::mixed(const MixedEnum& value) {
    m_mixed_ = value;
}

NegativeEnum& Enums::negative() OMG_NOEXCEPT {
    return m_negative_;
}

const NegativeEnum& Enums::negative() const OMG_NOEXCEPT {
    return m_negative_;
}

void Enums::negative(const NegativeEnum& value) {
    m_negative_ = value;
}

std::ostream& operator << (std::ostream& o,const Enums& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "basic: " << sample.basic()<<", ";
    o << "mixed: " << sample.mixed()<<", ";
    o << "negative: " << sample.negative() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<BasicEnum> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member BasicEnum_g_tc_members[3]=
                {

                    {
                        (char *)"A",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        BasicEnum::A, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"B",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        BasicEnum::B, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"C",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        BasicEnum::C, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode BasicEnum_g_tc =
                {{
                        DDS_TK_ENUM,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"BasicEnum", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        BasicEnum_g_tc_members, /* Members */
                        DDS_VM_NONE   /* Type Modifier */        
                    }}; /* Type code for BasicEnum*/

                if (is_initialized) {
                    return &BasicEnum_g_tc;
                }

                is_initialized = RTI_TRUE;

                return &BasicEnum_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::EnumType& dynamic_type<BasicEnum>::get()
        {
            return static_cast<const dds::core::xtypes::EnumType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<BasicEnum>::get())));
        }

        template<>
        struct native_type_code<MixedEnum> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member MixedEnum_g_tc_members[3]=
                {

                    {
                        (char *)"X",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        MixedEnum::X, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"Z",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        MixedEnum::Z, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"Y",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        MixedEnum::Y, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode MixedEnum_g_tc =
                {{
                        DDS_TK_ENUM,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"MixedEnum", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        MixedEnum_g_tc_members, /* Members */
                        DDS_VM_NONE   /* Type Modifier */        
                    }}; /* Type code for MixedEnum*/

                if (is_initialized) {
                    return &MixedEnum_g_tc;
                }

                is_initialized = RTI_TRUE;

                return &MixedEnum_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::EnumType& dynamic_type<MixedEnum>::get()
        {
            return static_cast<const dds::core::xtypes::EnumType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<MixedEnum>::get())));
        }

        template<>
        struct native_type_code<NegativeEnum> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member NegativeEnum_g_tc_members[3]=
                {

                    {
                        (char *)"K",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        NegativeEnum::K, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"L",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        NegativeEnum::L, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"M",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        NegativeEnum::M, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode NegativeEnum_g_tc =
                {{
                        DDS_TK_ENUM,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"NegativeEnum", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        NegativeEnum_g_tc_members, /* Members */
                        DDS_VM_NONE   /* Type Modifier */        
                    }}; /* Type code for NegativeEnum*/

                if (is_initialized) {
                    return &NegativeEnum_g_tc;
                }

                is_initialized = RTI_TRUE;

                return &NegativeEnum_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::EnumType& dynamic_type<NegativeEnum>::get()
        {
            return static_cast<const dds::core::xtypes::EnumType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<NegativeEnum>::get())));
        }

        template<>
        struct native_type_code<Enums> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Enums_g_tc_members[3]=
                {

                    {
                        (char *)"basic",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"mixed",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"negative",/* Member name */
                        {
                            2,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode Enums_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Enums", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        Enums_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for Enums*/

                if (is_initialized) {
                    return &Enums_g_tc;
                }

                Enums_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type< BasicEnum>::get().native();

                Enums_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type< MixedEnum>::get().native();

                Enums_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type< NegativeEnum>::get().native();

                is_initialized = RTI_TRUE;

                return &Enums_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<Enums>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<Enums>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<Enums>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                EnumsPlugin_new,
                EnumsPlugin_delete);
        }

        std::vector<char>& topic_type_support<Enums>::to_cdr_buffer(
            std::vector<char>& buffer, const Enums& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = EnumsPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = EnumsPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<Enums>::from_cdr_buffer(Enums& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = EnumsPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create Enums from cdr buffer");
        }

        void topic_type_support<Enums>::reset_sample(Enums& sample) 
        {
            rti::topic::reset_sample(sample.basic());
            rti::topic::reset_sample(sample.mixed());
            rti::topic::reset_sample(sample.negative());
        }

        void topic_type_support<Enums>::allocate_sample(Enums& sample, int, int) 
        {
            rti::topic::allocate_sample(sample.basic(),  -1, -1);
            rti::topic::allocate_sample(sample.mixed(),  -1, -1);
            rti::topic::allocate_sample(sample.negative(),  -1, -1);
        }

    }
}  


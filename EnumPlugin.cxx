

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Enum.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <string.h>

#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif

#ifndef osapi_type_h
#include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
#include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
#include "osapi/osapi_utility.h"
#endif

#ifndef cdr_log_h
#include "cdr/cdr_log.h"
#endif

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif

#ifndef cdr_type_object_h
#include "cdr/cdr_typeObject.h"
#endif

#ifndef cdr_encapsulation_h
#include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
#include "cdr/cdr_stream.h"
#endif

#ifndef cdr_log_h
#include "cdr/cdr_log.h"
#endif

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#include "rti/topic/cdr/Serialization.hpp"

#define RTI_CDR_CURRENT_SUBMODULE RTI_CDR_SUBMODULE_MASK_STREAM

#include "EnumPlugin.hpp"

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

RTIBool 
BasicEnumPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const BasicEnum *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    try {
        char * position = NULL;
        const char *METHOD_NAME = "BasicEnumPlugin_serialize";

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */

        if(serialize_encapsulation) {
            if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }

        if(serialize_sample) {

            if (*sample != BasicEnum::A && *sample != BasicEnum::B && *sample != BasicEnum::C){
                RTICdrLog_exception(
                    METHOD_NAME, 
                    &RTI_CDR_LOG_SERIALIZE_INVALID_ENUMERATOR_ds, 
                    sample->underlying(), 
                    "BasicEnum");
                return RTI_FALSE;       
            }

            if (!RTICdrStream_serializeEnum(stream, sample))
            {
                return RTI_FALSE;
            }

        }

        if(serialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;

    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool 
BasicEnumPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    BasicEnum *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    DDS_Enum enum_tmp;
    const char *METHOD_NAME = "BasicEnumPlugin_deserialize_sample";

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */
    if(deserialize_encapsulation) {

        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }
    if(deserialize_sample) {

        if (!RTICdrStream_deserializeEnum(stream, &enum_tmp))
        {
            return RTI_FALSE;
        }
        switch (enum_tmp) {
            case BasicEnum::A:
            *sample=BasicEnum::A;
            break;
            case BasicEnum::B:
            *sample=BasicEnum::B;
            break;
            case BasicEnum::C:
            *sample=BasicEnum::C;
            break;
            default:
            {
                struct PRESTypePluginDefaultEndpointData * epd =
                (struct PRESTypePluginDefaultEndpointData *)
                endpoint_data;
                const struct PRESTypePluginSampleAssignabilityProperty * ap =
                PRESTypePluginDefaultEndpointData_getAssignabilityProperty(epd);

                if (ap->acceptUnknownEnumValue) {
                    rti::topic::reset_sample(*sample);
                } else {
                    stream->_xTypesState.unassignable = RTI_TRUE;
                    RTICdrLog_exception(
                        METHOD_NAME, 
                        &RTI_CDR_LOG_DESERIALIZE_INVALID_ENUMERATOR_ds, 
                        enum_tmp, 
                        "BasicEnum");
                    return RTI_FALSE;
                }
            }
        }

    }

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool BasicEnumPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
    try    
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if (skip_sample) {

        if (!RTICdrStream_skipEnum(stream)) {
            return RTI_FALSE;
        }
    }

    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}
catch (...) {
    return RTI_FALSE;
}

unsigned int 
BasicEnumPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += RTICdrType_getEnumMaxSizeSerialized(current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

unsigned int 
BasicEnumPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {
        unsigned int initial_alignment = current_alignment;

        current_alignment += BasicEnumPlugin_get_serialized_sample_max_size_ex(
            endpoint_data,
            NULL,
            include_encapsulation,
            encapsulation_id, current_alignment);

        return current_alignment - initial_alignment;
    } catch (...) {
        return 0;
    }    
}

unsigned int BasicEnumPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{  
    try {
        unsigned int initial_alignment = current_alignment;

        current_alignment += BasicEnumPlugin_get_serialized_sample_max_size(
            endpoint_data,include_encapsulation,
            encapsulation_id, current_alignment);

        return current_alignment - initial_alignment;
    } catch (...) {
        return 0;
    }    
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
BasicEnumPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const BasicEnum * sample) 
{
    try {  
        unsigned int initial_alignment = current_alignment;

        if (sample==NULL) {
            return 0;
        }

        current_alignment += BasicEnumPlugin_get_serialized_sample_max_size(
            endpoint_data,include_encapsulation,
            encapsulation_id,
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data,
                current_alignment));

        return current_alignment - initial_alignment;
    } catch (...) {
        return RTI_FALSE;
    }    
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

RTIBool 
BasicEnumPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const BasicEnum *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    try {
        return  BasicEnumPlugin_serialize(
            endpoint_data, sample, stream, 
            serialize_encapsulation, encapsulation_id, 
            serialize_key, endpoint_plugin_qos);

    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool BasicEnumPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    BasicEnum *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    try {
        return  BasicEnumPlugin_deserialize_sample(
            endpoint_data, sample, stream, deserialize_encapsulation, 
            deserialize_key, endpoint_plugin_qos);
    } catch (...) {
        return RTI_FALSE;
    }
}

unsigned int
BasicEnumPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    current_alignment +=  BasicEnumPlugin_get_serialized_sample_max_size_ex(
        endpoint_data, overflow, include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}

RTIBool 
BasicEnumPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    BasicEnum *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
    try    
{

    return  BasicEnumPlugin_deserialize_sample(
        endpoint_data, sample, stream, deserialize_encapsulation, 
        deserialize_key, endpoint_plugin_qos);

} catch (...) {
    return RTI_FALSE;
} 

/* ----------------------------------------------------------------------------
Support functions:
* ---------------------------------------------------------------------------- */

void BasicEnumPluginSupport_print_data(
    const BasicEnum *sample,
    const char *description, int indent_level)
{
    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("NULL\n");
        return;
    }

    RTICdrType_printEnum((RTICdrEnum *)sample, "BasicEnum", indent_level + 1);
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

RTIBool 
MixedEnumPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const MixedEnum *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    try {
        char * position = NULL;
        const char *METHOD_NAME = "MixedEnumPlugin_serialize";

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */

        if(serialize_encapsulation) {
            if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }

        if(serialize_sample) {

            if (*sample != MixedEnum::X && *sample != MixedEnum::Z && *sample != MixedEnum::Y){
                RTICdrLog_exception(
                    METHOD_NAME, 
                    &RTI_CDR_LOG_SERIALIZE_INVALID_ENUMERATOR_ds, 
                    sample->underlying(), 
                    "MixedEnum");
                return RTI_FALSE;       
            }

            if (!RTICdrStream_serializeEnum(stream, sample))
            {
                return RTI_FALSE;
            }

        }

        if(serialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;

    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool 
MixedEnumPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    MixedEnum *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    DDS_Enum enum_tmp;
    const char *METHOD_NAME = "MixedEnumPlugin_deserialize_sample";

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */
    if(deserialize_encapsulation) {

        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }
    if(deserialize_sample) {

        if (!RTICdrStream_deserializeEnum(stream, &enum_tmp))
        {
            return RTI_FALSE;
        }
        switch (enum_tmp) {
            case MixedEnum::X:
            *sample=MixedEnum::X;
            break;
            case MixedEnum::Z:
            *sample=MixedEnum::Z;
            break;
            case MixedEnum::Y:
            *sample=MixedEnum::Y;
            break;
            default:
            {
                struct PRESTypePluginDefaultEndpointData * epd =
                (struct PRESTypePluginDefaultEndpointData *)
                endpoint_data;
                const struct PRESTypePluginSampleAssignabilityProperty * ap =
                PRESTypePluginDefaultEndpointData_getAssignabilityProperty(epd);

                if (ap->acceptUnknownEnumValue) {
                    rti::topic::reset_sample(*sample);
                } else {
                    stream->_xTypesState.unassignable = RTI_TRUE;
                    RTICdrLog_exception(
                        METHOD_NAME, 
                        &RTI_CDR_LOG_DESERIALIZE_INVALID_ENUMERATOR_ds, 
                        enum_tmp, 
                        "MixedEnum");
                    return RTI_FALSE;
                }
            }
        }

    }

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool MixedEnumPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
    try    
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if (skip_sample) {

        if (!RTICdrStream_skipEnum(stream)) {
            return RTI_FALSE;
        }
    }

    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}
catch (...) {
    return RTI_FALSE;
}

unsigned int 
MixedEnumPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += RTICdrType_getEnumMaxSizeSerialized(current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

unsigned int 
MixedEnumPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {
        unsigned int initial_alignment = current_alignment;

        current_alignment += MixedEnumPlugin_get_serialized_sample_max_size_ex(
            endpoint_data,
            NULL,
            include_encapsulation,
            encapsulation_id, current_alignment);

        return current_alignment - initial_alignment;
    } catch (...) {
        return 0;
    }    
}

unsigned int MixedEnumPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{  
    try {
        unsigned int initial_alignment = current_alignment;

        current_alignment += MixedEnumPlugin_get_serialized_sample_max_size(
            endpoint_data,include_encapsulation,
            encapsulation_id, current_alignment);

        return current_alignment - initial_alignment;
    } catch (...) {
        return 0;
    }    
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
MixedEnumPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const MixedEnum * sample) 
{
    try {  
        unsigned int initial_alignment = current_alignment;

        if (sample==NULL) {
            return 0;
        }

        current_alignment += MixedEnumPlugin_get_serialized_sample_max_size(
            endpoint_data,include_encapsulation,
            encapsulation_id,
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data,
                current_alignment));

        return current_alignment - initial_alignment;
    } catch (...) {
        return RTI_FALSE;
    }    
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

RTIBool 
MixedEnumPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const MixedEnum *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    try {
        return  MixedEnumPlugin_serialize(
            endpoint_data, sample, stream, 
            serialize_encapsulation, encapsulation_id, 
            serialize_key, endpoint_plugin_qos);

    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool MixedEnumPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    MixedEnum *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    try {
        return  MixedEnumPlugin_deserialize_sample(
            endpoint_data, sample, stream, deserialize_encapsulation, 
            deserialize_key, endpoint_plugin_qos);
    } catch (...) {
        return RTI_FALSE;
    }
}

unsigned int
MixedEnumPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    current_alignment +=  MixedEnumPlugin_get_serialized_sample_max_size_ex(
        endpoint_data, overflow, include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}

RTIBool 
MixedEnumPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    MixedEnum *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
    try    
{

    return  MixedEnumPlugin_deserialize_sample(
        endpoint_data, sample, stream, deserialize_encapsulation, 
        deserialize_key, endpoint_plugin_qos);

} catch (...) {
    return RTI_FALSE;
} 

/* ----------------------------------------------------------------------------
Support functions:
* ---------------------------------------------------------------------------- */

void MixedEnumPluginSupport_print_data(
    const MixedEnum *sample,
    const char *description, int indent_level)
{
    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("NULL\n");
        return;
    }

    RTICdrType_printEnum((RTICdrEnum *)sample, "MixedEnum", indent_level + 1);
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

RTIBool 
NegativeEnumPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const NegativeEnum *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    try {
        char * position = NULL;
        const char *METHOD_NAME = "NegativeEnumPlugin_serialize";

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */

        if(serialize_encapsulation) {
            if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }

        if(serialize_sample) {

            if (*sample != NegativeEnum::K && *sample != NegativeEnum::L && *sample != NegativeEnum::M){
                RTICdrLog_exception(
                    METHOD_NAME, 
                    &RTI_CDR_LOG_SERIALIZE_INVALID_ENUMERATOR_ds, 
                    sample->underlying(), 
                    "NegativeEnum");
                return RTI_FALSE;       
            }

            if (!RTICdrStream_serializeEnum(stream, sample))
            {
                return RTI_FALSE;
            }

        }

        if(serialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;

    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool 
NegativeEnumPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    NegativeEnum *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    DDS_Enum enum_tmp;
    const char *METHOD_NAME = "NegativeEnumPlugin_deserialize_sample";

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */
    if(deserialize_encapsulation) {

        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }
    if(deserialize_sample) {

        if (!RTICdrStream_deserializeEnum(stream, &enum_tmp))
        {
            return RTI_FALSE;
        }
        switch (enum_tmp) {
            case NegativeEnum::K:
            *sample=NegativeEnum::K;
            break;
            case NegativeEnum::L:
            *sample=NegativeEnum::L;
            break;
            case NegativeEnum::M:
            *sample=NegativeEnum::M;
            break;
            default:
            {
                struct PRESTypePluginDefaultEndpointData * epd =
                (struct PRESTypePluginDefaultEndpointData *)
                endpoint_data;
                const struct PRESTypePluginSampleAssignabilityProperty * ap =
                PRESTypePluginDefaultEndpointData_getAssignabilityProperty(epd);

                if (ap->acceptUnknownEnumValue) {
                    rti::topic::reset_sample(*sample);
                } else {
                    stream->_xTypesState.unassignable = RTI_TRUE;
                    RTICdrLog_exception(
                        METHOD_NAME, 
                        &RTI_CDR_LOG_DESERIALIZE_INVALID_ENUMERATOR_ds, 
                        enum_tmp, 
                        "NegativeEnum");
                    return RTI_FALSE;
                }
            }
        }

    }

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool NegativeEnumPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
    try    
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if (skip_sample) {

        if (!RTICdrStream_skipEnum(stream)) {
            return RTI_FALSE;
        }
    }

    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}
catch (...) {
    return RTI_FALSE;
}

unsigned int 
NegativeEnumPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += RTICdrType_getEnumMaxSizeSerialized(current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

unsigned int 
NegativeEnumPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {
        unsigned int initial_alignment = current_alignment;

        current_alignment += NegativeEnumPlugin_get_serialized_sample_max_size_ex(
            endpoint_data,
            NULL,
            include_encapsulation,
            encapsulation_id, current_alignment);

        return current_alignment - initial_alignment;
    } catch (...) {
        return 0;
    }    
}

unsigned int NegativeEnumPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{  
    try {
        unsigned int initial_alignment = current_alignment;

        current_alignment += NegativeEnumPlugin_get_serialized_sample_max_size(
            endpoint_data,include_encapsulation,
            encapsulation_id, current_alignment);

        return current_alignment - initial_alignment;
    } catch (...) {
        return 0;
    }    
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
NegativeEnumPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const NegativeEnum * sample) 
{
    try {  
        unsigned int initial_alignment = current_alignment;

        if (sample==NULL) {
            return 0;
        }

        current_alignment += NegativeEnumPlugin_get_serialized_sample_max_size(
            endpoint_data,include_encapsulation,
            encapsulation_id,
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data,
                current_alignment));

        return current_alignment - initial_alignment;
    } catch (...) {
        return RTI_FALSE;
    }    
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

RTIBool 
NegativeEnumPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const NegativeEnum *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    try {
        return  NegativeEnumPlugin_serialize(
            endpoint_data, sample, stream, 
            serialize_encapsulation, encapsulation_id, 
            serialize_key, endpoint_plugin_qos);

    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool NegativeEnumPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    NegativeEnum *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    try {
        return  NegativeEnumPlugin_deserialize_sample(
            endpoint_data, sample, stream, deserialize_encapsulation, 
            deserialize_key, endpoint_plugin_qos);
    } catch (...) {
        return RTI_FALSE;
    }
}

unsigned int
NegativeEnumPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    current_alignment +=  NegativeEnumPlugin_get_serialized_sample_max_size_ex(
        endpoint_data, overflow, include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}

RTIBool 
NegativeEnumPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    NegativeEnum *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
    try    
{

    return  NegativeEnumPlugin_deserialize_sample(
        endpoint_data, sample, stream, deserialize_encapsulation, 
        deserialize_key, endpoint_plugin_qos);

} catch (...) {
    return RTI_FALSE;
} 

/* ----------------------------------------------------------------------------
Support functions:
* ---------------------------------------------------------------------------- */

void NegativeEnumPluginSupport_print_data(
    const NegativeEnum *sample,
    const char *description, int indent_level)
{
    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("NULL\n");
        return;
    }

    RTICdrType_printEnum((RTICdrEnum *)sample, "NegativeEnum", indent_level + 1);
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */

/* ----------------------------------------------------------------------------
*  Type Enums
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

Enums *
EnumsPluginSupport_create_data(void)
{
    try {
        Enums *sample = new Enums;    
        rti::topic::allocate_sample(*sample);
        return sample;
    } catch (...) {
        return NULL;
    }
}

void 
EnumsPluginSupport_destroy_data(
    Enums *sample) 
{
    delete sample;
}

RTIBool 
EnumsPluginSupport_copy_data(
    Enums *dst,
    const Enums *src)
{
    try {
        *dst = *src;
    } catch (...) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

PRESTypePluginParticipantData 
EnumsPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */

    return PRESTypePluginDefaultParticipantData_new(participant_info);

}

void 
EnumsPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

    PRESTypePluginDefaultParticipantData_delete(participant_data);
}

PRESTypePluginEndpointData
EnumsPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    try {
        PRESTypePluginEndpointData epd = NULL;

        unsigned int serializedSampleMaxSize;

        if (top_level_registration) {} /* To avoid warnings */
        if (containerPluginContext) {} /* To avoid warnings */

        epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            EnumsPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            EnumsPluginSupport_destroy_data,
            NULL , NULL );

        if (epd == NULL) {
            return NULL;
        } 

        if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
            serializedSampleMaxSize = EnumsPlugin_get_serialized_sample_max_size(
                epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);

            PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

            if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
                (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                EnumsPlugin_get_serialized_sample_max_size, epd,
                (PRESTypePluginGetSerializedSampleSizeFunction)
                EnumsPlugin_get_serialized_sample_size,
                epd) == RTI_FALSE) {
                PRESTypePluginDefaultEndpointData_delete(epd);
                return NULL;
            }
        }

        return epd;
    } catch (...) {
        return NULL;
    }
}

void 
EnumsPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
EnumsPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    Enums *sample,
    void *handle)
{
    try {
        rti::topic::reset_sample(*sample);
    } catch(const std::exception& ex) {
        RTICdrLog_exception(
            "EnumsPlugin_return_sample",
            &RTI_LOG_ANY_FAILURE_s,
            "exception: ",
            ex.what());           
    }

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

RTIBool 
EnumsPlugin_copy_sample(
    PRESTypePluginEndpointData,
    Enums *dst,
    const Enums *src)
{
    return EnumsPluginSupport_copy_data(dst,src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
EnumsPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

RTIBool 
EnumsPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const Enums *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    try {
        char * position = NULL;
        RTIBool retval = RTI_TRUE;

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */

        if(serialize_encapsulation) {
            if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }

        if(serialize_sample) {

            if(!BasicEnumPlugin_serialize(
                endpoint_data,
                &sample->basic(),
                stream,
                RTI_FALSE, encapsulation_id,
                RTI_TRUE,
                endpoint_plugin_qos)) {
                return RTI_FALSE;
            }

            if(!MixedEnumPlugin_serialize(
                endpoint_data,
                &sample->mixed(),
                stream,
                RTI_FALSE, encapsulation_id,
                RTI_TRUE,
                endpoint_plugin_qos)) {
                return RTI_FALSE;
            }

            if(!NegativeEnumPlugin_serialize(
                endpoint_data,
                &sample->negative(),
                stream,
                RTI_FALSE, encapsulation_id,
                RTI_TRUE,
                endpoint_plugin_qos)) {
                return RTI_FALSE;
            }

        }

        if(serialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return retval;

    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool 
EnumsPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    Enums *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */
    if(deserialize_encapsulation) {

        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }
    if(deserialize_sample) {

        if(!BasicEnumPlugin_deserialize_sample(
            endpoint_data,
            &sample->basic(),
            stream,
            RTI_FALSE, RTI_TRUE,
            endpoint_plugin_qos)) {
            goto fin; 
        }
        if(!MixedEnumPlugin_deserialize_sample(
            endpoint_data,
            &sample->mixed(),
            stream,
            RTI_FALSE, RTI_TRUE,
            endpoint_plugin_qos)) {
            goto fin; 
        }
        if(!NegativeEnumPlugin_deserialize_sample(
            endpoint_data,
            &sample->negative(),
            stream,
            RTI_FALSE, RTI_TRUE,
            endpoint_plugin_qos)) {
            goto fin; 
        }
    }

    done = RTI_TRUE;
  fin:
    if (done != RTI_TRUE && 
    RTICdrStream_getRemainder(stream) >=
    RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
        return RTI_FALSE;   
    }
    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool
EnumsPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const Enums *sample)
{
    try{
        struct RTICdrStream stream;
        struct PRESTypePluginDefaultEndpointData epd;
        RTIBool result;

        if (length == NULL) {
            return RTI_FALSE;
        }

        epd._maxSizeSerializedSample =
        EnumsPlugin_get_serialized_sample_max_size(
            NULL, RTI_TRUE, RTICdrEncapsulation_getNativeCdrEncapsulationId(), 0);

        if (buffer == NULL) {
            *length = 
            EnumsPlugin_get_serialized_sample_size(
                (PRESTypePluginEndpointData)&epd,
                RTI_TRUE,
                RTICdrEncapsulation_getNativeCdrEncapsulationId(),
                0,
                sample);

            if (*length == 0) {
                return RTI_FALSE;
            }

            return RTI_TRUE;
        }    

        RTICdrStream_init(&stream);
        RTICdrStream_set(&stream, (char *)buffer, *length);

        result = EnumsPlugin_serialize(
            (PRESTypePluginEndpointData)&epd, sample, &stream, 
            RTI_TRUE, RTICdrEncapsulation_getNativeCdrEncapsulationId(), 
            RTI_TRUE, NULL);  

        *length = RTICdrStream_getCurrentPositionOffset(&stream);
        return result;     
    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool
EnumsPlugin_deserialize_from_cdr_buffer(
    Enums *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream stream;

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, length);

    rti::topic::reset_sample(*sample);
    return EnumsPlugin_deserialize_sample( 
        NULL, sample,
        &stream, RTI_TRUE, RTI_TRUE, 
        NULL);
}

RTIBool 
EnumsPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    Enums **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    try {
        RTIBool result;
        const char *METHOD_NAME = "EnumsPlugin_deserialize";
        if (drop_sample) {} /* To avoid warnings */

        stream->_xTypesState.unassignable = RTI_FALSE;
        result= EnumsPlugin_deserialize_sample( 
            endpoint_data, (sample != NULL)?*sample:NULL,
            stream, deserialize_encapsulation, deserialize_sample, 
            endpoint_plugin_qos);
        if (result) {
            if (stream->_xTypesState.unassignable) {
                result = RTI_FALSE;
            }
        }
        if (!result && stream->_xTypesState.unassignable ) {

            RTICdrLog_exception(
                METHOD_NAME, 
                &RTI_CDR_LOG_UNASSIGNABLE_SAMPLE_OF_TYPE_s, 
                "Enums");

        }

        return result;

    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool EnumsPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
    try    
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if (skip_sample) {

        if (!BasicEnumPlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
            goto fin; 
        }
        if (!MixedEnumPlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
            goto fin; 
        }
        if (!NegativeEnumPlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
            goto fin; 
        }
    }

    done = RTI_TRUE;
  fin:
    if (done != RTI_TRUE && 
    RTICdrStream_getRemainder(stream) >=
    RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
        return RTI_FALSE;   
    }
    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}
catch (...) {
    return RTI_FALSE;
}

unsigned int 
EnumsPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment +=BasicEnumPlugin_get_serialized_sample_max_size_ex(
        endpoint_data, overflow, RTI_FALSE,encapsulation_id,current_alignment);

    current_alignment +=MixedEnumPlugin_get_serialized_sample_max_size_ex(
        endpoint_data, overflow, RTI_FALSE,encapsulation_id,current_alignment);

    current_alignment +=NegativeEnumPlugin_get_serialized_sample_max_size_ex(
        endpoint_data, overflow, RTI_FALSE,encapsulation_id,current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

unsigned int 
EnumsPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {
        unsigned int size;
        RTIBool overflow = RTI_FALSE;

        size = EnumsPlugin_get_serialized_sample_max_size_ex(
            endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

        if (overflow) {
            size = RTI_CDR_MAX_SERIALIZED_SIZE;
        }

        return size;
    } catch (...) {
        return 0;
    }    
}

unsigned int 
EnumsPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {

        unsigned int initial_alignment = current_alignment;

        unsigned int encapsulation_size = current_alignment;

        if (endpoint_data) {} /* To avoid warnings */ 

        if (include_encapsulation) {

            if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
                return 1;
            }
            RTICdrStream_getEncapsulationSize(encapsulation_size);
            encapsulation_size -= current_alignment;
            current_alignment = 0;
            initial_alignment = 0;
        }

        current_alignment +=BasicEnumPlugin_get_serialized_sample_min_size(
            endpoint_data,RTI_FALSE,encapsulation_id,current_alignment);
        current_alignment +=MixedEnumPlugin_get_serialized_sample_min_size(
            endpoint_data,RTI_FALSE,encapsulation_id,current_alignment);
        current_alignment +=NegativeEnumPlugin_get_serialized_sample_min_size(
            endpoint_data,RTI_FALSE,encapsulation_id,current_alignment);

        if (include_encapsulation) {
            current_alignment += encapsulation_size;
        }
        return  current_alignment - initial_alignment;
    } catch (...) {
        return 0;
    }
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
EnumsPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const Enums * sample) 
{
    try {  
        unsigned int initial_alignment = current_alignment;

        unsigned int encapsulation_size = current_alignment;
        struct PRESTypePluginDefaultEndpointData epd;   

        if (sample==NULL) {
            return 0;
        }
        if (endpoint_data == NULL) {
            endpoint_data = (PRESTypePluginEndpointData) &epd;
            PRESTypePluginDefaultEndpointData_setBaseAlignment(
                endpoint_data,
                current_alignment);        
        }

        if (include_encapsulation) {

            if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
                return 1;
            }
            RTICdrStream_getEncapsulationSize(encapsulation_size);
            encapsulation_size -= current_alignment;
            current_alignment = 0;
            initial_alignment = 0;
            PRESTypePluginDefaultEndpointData_setBaseAlignment(
                endpoint_data,
                current_alignment);
        }

        current_alignment += BasicEnumPlugin_get_serialized_sample_size(
            endpoint_data,RTI_FALSE, encapsulation_id,
            current_alignment, &sample->basic());

        current_alignment += MixedEnumPlugin_get_serialized_sample_size(
            endpoint_data,RTI_FALSE, encapsulation_id,
            current_alignment, &sample->mixed());

        current_alignment += NegativeEnumPlugin_get_serialized_sample_size(
            endpoint_data,RTI_FALSE, encapsulation_id,
            current_alignment, &sample->negative());

        if (include_encapsulation) {
            current_alignment += encapsulation_size;
        }
        return current_alignment - initial_alignment;
    } catch (...) {
        return RTI_FALSE;
    }    
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
EnumsPlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_NO_KEY;
}

RTIBool 
EnumsPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const Enums *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    try {
        char * position = NULL;

        if(serialize_encapsulation) {
            if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }

        if(serialize_key) {

            if (!EnumsPlugin_serialize(
                endpoint_data,
                sample,
                stream,
                RTI_FALSE, encapsulation_id,
                RTI_TRUE,
                endpoint_plugin_qos)) {
                return RTI_FALSE;
            }

        }

        if(serialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;
    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool EnumsPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    Enums *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    try {
        char * position = NULL;

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */

        if(deserialize_encapsulation) {

            if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }
        if (deserialize_key) {

            if (!EnumsPlugin_deserialize_sample(
                endpoint_data, sample, stream, 
                RTI_FALSE, RTI_TRUE, 
                endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }

        if(deserialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;
    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool EnumsPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    Enums **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    try {
        RTIBool result;
        if (drop_sample) {} /* To avoid warnings */
        stream->_xTypesState.unassignable = RTI_FALSE;
        result= EnumsPlugin_deserialize_key_sample(
            endpoint_data, (sample != NULL)?*sample:NULL, stream,
            deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
        if (result) {
            if (stream->_xTypesState.unassignable) {
                result = RTI_FALSE;
            }
        }

        return result;    
    } catch (...) {
        return RTI_FALSE;
    }     
}

unsigned int
EnumsPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += EnumsPlugin_get_serialized_sample_max_size_ex(
        endpoint_data, overflow,RTI_FALSE, encapsulation_id, current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return current_alignment - initial_alignment;
}

unsigned int
EnumsPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {
        unsigned int size;
        RTIBool overflow = RTI_FALSE;

        size = EnumsPlugin_get_serialized_key_max_size_ex(
            endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

        if (overflow) {
            size = RTI_CDR_MAX_SERIALIZED_SIZE;
        }

        return size;
    } catch (...) {
        return RTI_FALSE;
    }    
}

RTIBool 
EnumsPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    Enums *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
    try    
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;
    RTIBool error = RTI_FALSE;

    if (stream == NULL) {
        error = RTI_TRUE;
        goto fin;
    }
    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }
        position = RTICdrStream_resetAlignment(stream);
    }

    if (deserialize_key) {

        if (!EnumsPlugin_deserialize_sample(
            endpoint_data, sample, stream, RTI_FALSE, 
            RTI_TRUE, endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }

    done = RTI_TRUE;
  fin:
    if(!error) {
        if (done != RTI_TRUE && 
        RTICdrStream_getRemainder(stream) >=
        RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }
    } else {
        return RTI_FALSE;
    }       

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
} catch (...) {
    return RTI_FALSE;
} 

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *EnumsPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    EnumsPlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    EnumsPlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    EnumsPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    EnumsPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    EnumsPlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    EnumsPlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    EnumsPlugin_destroy_sample;

    plugin->serializeFnc =
    (PRESTypePluginSerializeFunction)
    EnumsPlugin_serialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction)
    EnumsPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    EnumsPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    EnumsPlugin_get_serialized_sample_min_size;

    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    EnumsPlugin_get_sample;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    EnumsPlugin_return_sample;

    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    EnumsPlugin_get_key_kind;

    /* These functions are only used for keyed types. As this is not a keyed
    type they are all set to NULL
    */
    plugin->serializeKeyFnc = NULL ;    
    plugin->deserializeKeyFnc = NULL;  
    plugin->getKeyFnc = NULL;
    plugin->returnKeyFnc = NULL;
    plugin->instanceToKeyFnc = NULL;
    plugin->keyToInstanceFnc = NULL;
    plugin->getSerializedKeyMaxSizeFnc = NULL;
    plugin->instanceToKeyHashFnc = NULL;
    plugin->serializedSampleToKeyHashFnc = NULL;
    plugin->serializedKeyToKeyHashFnc = NULL;    
    plugin->typeCode = (struct RTICdrTypeCode *) 
    &rti::topic::dynamic_type<Enums>::get().native();

    plugin->languageKind = PRES_TYPEPLUGIN_CPPSTL_LANG;

    /* Serialized buffer */
    plugin->getBuffer = 
    (PRESTypePluginGetBufferFunction)
    EnumsPlugin_get_buffer;
    plugin->returnBuffer = 
    (PRESTypePluginReturnBufferFunction)
    EnumsPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    EnumsPlugin_get_serialized_sample_size;

    static const char * TYPE_NAME = "Enums";
    plugin->endpointTypeName = TYPE_NAME;

    return plugin;
}

void
EnumsPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 
#undef RTI_CDR_CURRENT_SUBMODULE 

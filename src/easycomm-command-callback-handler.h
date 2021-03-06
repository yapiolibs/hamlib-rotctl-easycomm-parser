#pragma once
#ifdef __cplusplus
extern "C"
{
#endif

#include "easycomm-parser.h"

    typedef void (*EasycommCommandCallback)(const EasycommData *, void *);

    /**
     * Callback registry.
     * Each entry describes command-id to callback mapping.
     * NULL-callback entries are allowed but skipped.
     */
    typedef struct EasycommCommandsCallback
    {
        EasycommCommandCallback registry[EasycommIdsCount];
    } EasycommCommandsCallback;

    /**
     * Constructs a default callback registry with dummy callbacks for the respective easycomm standard.
     * @param registry the callback registry to construct
     * @param parser_standard describes which commands shall be registered to a dummy callback
     */
    void easycommCommandsCallback(EasycommCommandsCallback *registry, EasycommParserStandard parser_standard);

    /**
     * Same as \see easycommCommandsCallback(EasycommCommandsCallback *, EasycommParserStandard) but with custom default callback.
     * @param registry \see easycommCommandsCallback(EasycommCommandsCallback *, EasycommParserStandard )
     * @param parser_standard \see easycommCommandsCallback(EasycommCommandsCallback *, EasycommParserStandard )
     * @param custom_default_cb custom default callback
     */
    void easycommCommandsCallbackCustomDefaultCb(EasycommCommandsCallback *registry,
                                                 EasycommParserStandard parser_standard,
                                                 EasycommCommandCallback custom_default_cb);

    /**
     * Invokes the parser and the resulting callback.
     * If the parser fails the EasycommIdInvalid-callback is invoked.
     * @param buffer data to parse from: trimmed, no whitespace, null terminated, without "\r" "\n"
     * @param registry command-callback registry, NULL entries are allowed but skipped
     * @param parser_standard easycomm standard for the parser
     * @param custom_data pointer to custom data for the callback
     * @return true if a callback was invoked
     */
    bool easycommHandleCommand(const char *buffer,
                               EasycommCommandsCallback *registry,
                               EasycommParserStandard parser_standard,
                               void *custom_data);

#ifdef __cplusplus
}
#endif

// matth-x/ArduinoOcppMongoose
// Copyright Matthias Akstaller 2019 - 2023
// GPL-3.0 License (see LICENSE)

#ifndef AOCPPMONGOOSECLIENT_C_H
#define AOCPPMONGOOSECLIENT_C_H

#if defined(__cplusplus) && defined(ARDUINO) //fix for conflicting defitions of IPAddress on Arduino
#include <Arduino.h>
#include <IPAddress.h>
#endif

#include "mongoose.h"
#include <ArduinoOcpp/Core/ConfigurationOptions.h>

#ifdef __cplusplus
extern "C" {
#endif

struct AOcppSocket;
typedef struct AOcppSocket AOcppSocket;

AOcppSocket *ao_makeOcppSocket(struct mg_mgr *mgr,
        const char *backend_url_default,   //all cstrings can be NULL
        const char *charge_box_id_default,
        const char *auth_key_default,
        const char *CA_cert_default,
        struct AO_FilesystemOpt fsopt);

void ao_deinitOcppSocket(AOcppSocket *sock);

void ao_setBackendUrl(AOcppSocket *sock, const char *backend_url);
void ao_setChargeBoxId(AOcppSocket *sock, const char *cb_id);
void ao_setAuthKey(AOcppSocket *sock, const char *auth_key);
void ao_setCaCert(AOcppSocket *sock, const char *ca_cert);

void ao_reconnect(AOcppSocket *sock); //after updating all credentials, reconnect to apply them

const char *ao_getBackendUrl(AOcppSocket *sock);
const char *ao_getChargeBoxId(AOcppSocket *sock);
const char *ao_getAuthKey(AOcppSocket *sock);
const char *ao_getCaCert(AOcppSocket *sock);

bool ao_isConnectionOpen(AOcppSocket *sock);

#ifdef __cplusplus
}
#endif

#endif

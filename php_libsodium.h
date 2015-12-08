
#ifndef PHP_LIBSODIUM_H
#define PHP_LIBSODIUM_H

extern zend_module_entry libsodium_module_entry;
#define phpext_libsodium_ptr &libsodium_module_entry

#define PHP_LIBSODIUM_VERSION "1.0.2"

#ifdef PHP_WIN32
# define PHP_LIBSODIUM_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
# define PHP_LIBSODIUM_API __attribute__ ((visibility("default")))
#else
# define PHP_LIBSODIUM_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(libsodium);
PHP_MSHUTDOWN_FUNCTION(libsodium);
PHP_RINIT_FUNCTION(libsodium);
PHP_RSHUTDOWN_FUNCTION(libsodium);
PHP_MINFO_FUNCTION(libsodium);

PHP_FUNCTION(crypto_aead_aes256gcm_is_available);
PHP_FUNCTION(crypto_aead_aes256gcm_decrypt);
PHP_FUNCTION(crypto_aead_aes256gcm_encrypt);
PHP_FUNCTION(crypto_aead_chacha20poly1305_decrypt);
PHP_FUNCTION(crypto_aead_chacha20poly1305_encrypt);
PHP_FUNCTION(crypto_auth);
PHP_FUNCTION(crypto_auth_verify);
PHP_FUNCTION(crypto_box);
PHP_FUNCTION(crypto_box_keypair);
PHP_FUNCTION(crypto_box_seed_keypair);
PHP_FUNCTION(crypto_box_keypair_from_secretkey_and_publickey);
PHP_FUNCTION(crypto_box_open);
PHP_FUNCTION(crypto_box_publickey);
PHP_FUNCTION(crypto_box_publickey_from_secretkey);
PHP_FUNCTION(crypto_box_seal);
PHP_FUNCTION(crypto_box_seal_open);
PHP_FUNCTION(crypto_box_secretkey);
PHP_FUNCTION(crypto_generichash);
PHP_FUNCTION(crypto_generichash_final);
PHP_FUNCTION(crypto_generichash_init);
PHP_FUNCTION(crypto_generichash_update);
PHP_FUNCTION(crypto_onetimeauth);
PHP_FUNCTION(crypto_onetimeauth_init);
PHP_FUNCTION(crypto_onetimeauth_update);
PHP_FUNCTION(crypto_onetimeauth_final);
PHP_FUNCTION(crypto_kx);
PHP_FUNCTION(crypto_pwhash_scryptsalsa208sha256);
PHP_FUNCTION(crypto_pwhash_scryptsalsa208sha256_str);
PHP_FUNCTION(crypto_pwhash_scryptsalsa208sha256_str_verify);
PHP_FUNCTION(crypto_scalarmult);
PHP_FUNCTION(crypto_scalarmult_base);
PHP_FUNCTION(crypto_secretbox);
PHP_FUNCTION(crypto_secretbox_open);
PHP_FUNCTION(crypto_shorthash);
PHP_FUNCTION(crypto_sign);
PHP_FUNCTION(crypto_sign_detached);
PHP_FUNCTION(crypto_sign_ed25519_pk_to_curve25519);
PHP_FUNCTION(crypto_sign_ed25519_sk_to_curve25519);
PHP_FUNCTION(crypto_sign_keypair);
PHP_FUNCTION(crypto_sign_keypair_from_secretkey_and_publickey);
PHP_FUNCTION(crypto_sign_open);
PHP_FUNCTION(crypto_sign_publickey);
PHP_FUNCTION(crypto_sign_publickey_from_secretkey);
PHP_FUNCTION(crypto_sign_secretkey);
PHP_FUNCTION(crypto_sign_seed_keypair);
PHP_FUNCTION(crypto_sign_verify_detached);
PHP_FUNCTION(crypto_stream);
PHP_FUNCTION(crypto_stream_xor);
PHP_FUNCTION(crypto_stream_xsalsa20);
PHP_FUNCTION(crypto_stream_xsalsa20_xor);
PHP_FUNCTION(crypto_stream_xsalsa20_xor_ic);
PHP_FUNCTION(crypto_stream_salsa20);
PHP_FUNCTION(crypto_stream_salsa20_xor);
PHP_FUNCTION(crypto_stream_salsa20_xor_ic);
PHP_FUNCTION(crypto_stream_chacha20);
PHP_FUNCTION(crypto_stream_chacha20_xor);
PHP_FUNCTION(crypto_stream_chacha20_xor_ic);
PHP_FUNCTION(crypto_stream_aes128ctr);
PHP_FUNCTION(crypto_stream_aes128ctr_xor);
PHP_FUNCTION(randombytes_buf);
PHP_FUNCTION(randombytes_random16);
PHP_FUNCTION(randombytes_uniform);
PHP_FUNCTION(sodium_bin2hex);
PHP_FUNCTION(sodium_compare);
PHP_FUNCTION(sodium_hex2bin);
PHP_FUNCTION(sodium_increment);
PHP_FUNCTION(sodium_add);
PHP_FUNCTION(sodium_library_version_major);
PHP_FUNCTION(sodium_library_version_minor);
PHP_FUNCTION(sodium_memcmp);
PHP_FUNCTION(sodium_memzero);
PHP_FUNCTION(sodium_version_string);

#ifdef ZTS
#define LIBSODIUM_G(v) TSRMG(libsodium_globals_id, zend_libsodium_globals *, v)
#else
#define LIBSODIUM_G(v) (libsodium_globals.v)
#endif

#define crypto_kx_BYTES crypto_scalarmult_BYTES
#define crypto_kx_PUBLICKEYBYTES crypto_scalarmult_SCALARBYTES
#define crypto_kx_SECRETKEYBYTES crypto_scalarmult_SCALARBYTES

#endif  /* PHP_LIBSODIUM_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
